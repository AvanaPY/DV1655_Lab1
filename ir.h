#include<iostream>
#include <fstream>
#include<string.h>
#include <list>
#include "Node.h"
#include <map>

namespace IR {

map<std::string, std::string> opmap = {
    { "PLUS" , "ADD" },
    { "MINUS", "SUB" },
    { "DIV"  , "DIV" },
    { "MULT" , "MUL" },
    { "AND"  , "AND" },
    { "OR"   , "OR" },
    { "NOT"  , "NOT" },
    { "GT"  , "GT" },
    { "LT"  , "LT" },
    { "EQ"  , "EQ" },
    { "Indexing", "@" },
    { "new()", "NEW" },
    { "new[]", "NEW[]" }
};

class TAC {
private:
    std::string result, op, lhs, rhs;

public:
    TAC(std::string res, std::string o, std::string l, std::string r) : op(o), lhs(l), rhs(r), result(res){}
    void dump(std::ofstream& stream){
        stream  << result 
                << " := "
                << lhs << " " 
                << op << " " 
                << rhs;
    }
};

class Block {

private:
    list<TAC*> tacs;
    TAC* condition;
    Block *trueExit, *falseExit;

public:
    string name;
    int last_local_id;
    Block(string n) : name(n), trueExit(NULL), falseExit(NULL) {}

    void add_tac(TAC* tac)
    {
        tacs.push_back(tac);
    }

    void set_true_exit(Block* blk)
    {
        trueExit = blk;
    }

    void set_false_exit(Block* blk)
    {
        falseExit = blk;
    }

    void set_condition(TAC* tac)
    {
        condition = tac;
    }

    void dump_rec(std::ofstream& stream)
    {
        stream << "  " << name << " [label=\"" << name << "\\n";
        for(auto it = tacs.begin(); it != tacs.end(); it++)
        {
            (*it)->dump(stream);
            stream << "\\n";
        }
            
        if(condition != nullptr){
            condition->dump(stream);
            stream << "\\n";
        }
        stream << "\"];" << std::endl;

        if(trueExit != nullptr){
            stream << "  " << name << " -> " << trueExit->name << "[xlabel=\"true\"];" << std::endl;
            trueExit->dump_rec(stream);
        }
        
        if(falseExit != nullptr){
            stream << "  " << name << " -> " << falseExit->name << "[xlabel=\"false\"];" << std::endl;
            falseExit->dump_rec(stream);
        }
    }
};

void dump_cfg(std::ofstream&);
void traverse_ast(Node* node, list<Block*>* blks);
void convert_statement(Node* node, Block* currblk);
void convert_expression(Node* node, Block* currblk);


string
to_local_var_name(int id)
{
    return "_+" + std::to_string(id);
}

void 
dump_cfg(list<Block*>* blks, std::ofstream& stream)
{
    stream << "digraph {\n"
           << "  graph [splines=ortho]\n"
           << "  node [shape=box]\n";
    for(auto it = blks->begin(); it != blks->end(); it++)
        (*it)->dump_rec(stream);
    stream << "}";
}

std::string curr_class_name;
Block* currblk;
int block_id = 0;

void
traverse_ast(Node* node, list<Block*>* entry_points)
{
    if(node->type == "MainClass" || node->type == "Class") 
    {
        curr_class_name = node->value;
        for(auto it = node->children.begin(); it != node->children.end(); it++)
            traverse_ast(*it, entry_points);
    } 
    else if(node->type == "Method")
    {
        Block* blk = new Block(curr_class_name + node->value);
        entry_points->push_back(blk);
        currblk = blk;

        for(auto it = node->children.begin(); it != node->children.end(); it++)
            traverse_ast(*it, entry_points);
    }
    else if(node->type == "Statement List")
    {
        for(auto it = node->children.begin(); it != node->children.end(); it++)
            convert_statement(*it, currblk);
    } 
    else {
        for(auto c = node->children.begin(); c != node->children.end(); c++)
            traverse_ast((*c), entry_points);
    }
}

void
convert_statement(Node* node, Block* blk)
{
    std::cout << "statement\n";
    if(node->type == "Assign")
    {
        string typ = node->children.back()->type;

        if(typ == "Int" || typ == "Identifier" || typ == "Bool")
        {
            blk->add_tac(new TAC(node->children.front()->value, "", node->children.back()->value, ""));
        } 
        else 
        {
            convert_expression(node->children.back(), blk);
            blk->add_tac(new TAC(node->children.front()->value, "", to_local_var_name(currblk->last_local_id), ""));
        }

    } 
    else if(node->type == "SYS_PRINTLN")
    {

    }
    else {
        std::cout << "Encountered unhandled statement " << node->type << "\n";

    }
}

string 
get_op(Node* node)
{
    if(opmap.count(node->type))
        return opmap[node->type];
    
    std::cout << "Unhandled get_op: (" << node->type << ", " << node->value << ")\n";
    return "---";
}

/* 
Takes an expresison node and a block as arguments,
then it recursively traverses the node tree and adds TACs to the block.

It returns the name of the last variable.
*/
std::string
expr_node_to_tacs(Node* node, Block* blk)
{
    if(node->type == "Int")
        return "$" + node->value;
    if(node->type == "Identifier")
        return node->value;
    if(node->type == "Bool")
        return node->value;

    string op = get_op(node);

    /* 
    Special case for the NOT, new() and new[] operators 
    because they only take one argument
    */
    if(node->type == "NOT" || node->type == "new()" || node->type == "new[]")
    {
        string c = expr_node_to_tacs(node->children.front(), blk);
        blk->last_local_id++;
        TAC* tac = new TAC(to_local_var_name(blk->last_local_id), op, "", c);
        blk->add_tac(tac);
    } 
    /*
    All other expression operators
    */
    else
    {
        string l = expr_node_to_tacs(node->children.front(), blk);
        string r = expr_node_to_tacs(node->children.back(), blk);

        blk->last_local_id++;
        TAC* tac = new TAC(to_local_var_name(blk->last_local_id), op, l, r);

        blk->add_tac(tac);
    }
    return to_local_var_name(blk->last_local_id);
}

void 
convert_expression(Node* node, Block* blk)
{
    if (node->type == "PLUS"  || 
        node->type == "MINUS" || 
        node->type == "MULT"  || 
        node->type == "DIV"   ||
        node->type == "AND"   || 
        node->type == "OR"    ||
        node->type == "NOT"   ||
        node->type == "GT"    ||
        node->type == "LT"    ||
        node->type == "EQ"    ||
        node->type == "Indexing" ||
        node->type == "new()" ||
        node->type == "new[]" )
    {
        string llc = expr_node_to_tacs(node, blk);
    } 
    else
    {
        std::cout << "Unhandled expression " << node->type << "\n";
    }
}
}
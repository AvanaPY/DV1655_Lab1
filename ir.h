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
static int blk_count;

string 
get_op(Node* node)
{
    if(opmap.count(node->type))
        return opmap[node->type];
    
    std::cout << "Unhandled get_op: (" << node->type << ", " << node->value << ")\n";
    return "---";
}

string
generic_blk_name_from_id(int id)
{
    return "block_" + std::to_string(id);
}


class TAC {
protected:
    std::string result, op, lhs, rhs;

public:
    TAC(std::string res, std::string o, std::string l, std::string r) : op(o), lhs(l), rhs(r), result(res){}
    virtual void dump(std::ofstream& stream){}

    string get_result()
    {
        return result;
    }
    void set_result(string res)
    {
        result = res;
    }

    string get_lhs()
    {
        return lhs;
    }
    string get_rhs()
    {
        return rhs;
    }
    string get_op()
    {
        return op;
    }

    virtual void stack_with(TAC* tac) {
        std::cout << "Stacking Not implemented\n";
    };
};

class AssignTAC : public TAC {
public:
    AssignTAC(std::string res, std::string o, std::string l, std::string r) : TAC(res, o, l, r){}

    void dump(std::ofstream& stream)
    {
        stream  << result 
                << " := "
                << lhs << " " 
                << op << " " 
                << rhs;
    }

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }
};

class CondTAC : public TAC {
public:
    CondTAC(std::string stmt_type, std::string o, std::string l, std::string r) : TAC(stmt_type, o, l, r){}

    void dump(std::ofstream& stream)
    {
        stream  << result << " "
                << lhs << " " 
                << op << " "
                << rhs;
    }

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }
};

class Block {

private:
    TAC* condition;
    Block *trueExit, *falseExit;

public:
    list<TAC*> tacs;
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

    void dump(std::ofstream& stream)
    {
        map<std::string, int> dump_map;
        dump_rec(stream, &dump_map);
    }

    void dump_rec(std::ofstream& stream, map<std::string, int>* dump_map)
    {
        if(dump_map->count(name)){
            return;
        }

        stream << "  " << name << " [label=\"" << name << "\\n";
        dump_map->insert(std::pair<std::string, int>(name, 1));

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
            trueExit->dump_rec(stream, dump_map);
        }
        
        if(falseExit != nullptr){
            stream << "  " << name << " -> " << falseExit->name << "[xlabel=\"false\"];" << std::endl;
            falseExit->dump_rec(stream, dump_map);
        }
    }
};

void dump_cfg(std::ofstream&);
void traverse_ast(Node* node, list<Block*>* blks);
void convert_statement(Node* node, Block* currblk);
string convert_expression(Node* node, Block* currblk);

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
        (*it)->dump(stream);
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
stack_tacs(Block* blk)
{
    if(blk->tacs.size() < 2)
        return;
    TAC* a = blk->tacs.back(); blk->tacs.pop_back();
    TAC* b = blk->tacs.back(); blk->tacs.pop_back();

    a->stack_with(b);
    blk->add_tac(a);
}

void
create_assign_IR(Node* node, Block* blk)
{
    string typ = node->children.back()->type;

    if(typ == "Int" || typ == "Identifier" || typ == "Bool")
    {
        blk->add_tac(new AssignTAC(node->children.front()->value, "", node->children.back()->value, ""));
    } 
    else 
    {
        convert_expression(node->children.back(), blk);
        blk->add_tac(new AssignTAC(node->children.front()->value, "", to_local_var_name(currblk->last_local_id), ""));

        stack_tacs(blk);
    }
}

void
create_if_IR(Node* node, Block* blk)
{
    // Create our new if block
    blk_count++;
    Block* if_blk = new Block(generic_blk_name_from_id(blk_count));
    
    // Convert the conditional expression
    string lvm = convert_expression(node->children.front(), if_blk);
    if_blk->add_tac(new CondTAC("IF", "", "", lvm));
    stack_tacs(if_blk); // Stack the last 2 blocks for nice looking IR

    // Create a true and a false block
    blk_count++;
    Block* trueblk = new Block(generic_blk_name_from_id(blk_count));
    
    blk_count++;
    Block* falseblk = new Block(generic_blk_name_from_id(blk_count));

    // Iterate over the nodes and convert the statements to blocks
    auto it = node->children.begin(); std::advance(it, 1);
    Node* true_stmt = *it; std::advance(it, 1);
    Node* false_stmt = *it; 

    convert_statement(true_stmt, trueblk);
    convert_statement(false_stmt, falseblk);

    // Create an exit block
    blk_count++;
    Block* exitblk = new Block(generic_blk_name_from_id(blk_count));

    // Assign exits
    blk->set_true_exit(if_blk);
    if_blk->set_true_exit(trueblk);
    if_blk->set_false_exit(falseblk);

    trueblk->set_true_exit(exitblk);
    falseblk->set_true_exit(exitblk);
    currblk = exitblk; // Update block we're on
}

void
create_while_IR(Node* node, Block* blk)
{
    blk_count++;
    Block* while_blk = new Block(generic_blk_name_from_id(blk_count));
    
    string lvm = convert_expression(node->children.front(), while_blk);
    while_blk->add_tac(new CondTAC("WHILE", "", "", lvm));
    stack_tacs(while_blk);

    // Create a true and a false block
    blk_count++;
    Block* trueblk = new Block(generic_blk_name_from_id(blk_count));
    
    blk_count++;
    Block* falseblk = new Block(generic_blk_name_from_id(blk_count));

    // Iterate over the nodes and convert the statements to blocks
    auto it = node->children.begin(); std::advance(it, 1);
    Node* true_stmt = *it; std::advance(it, 1);
    convert_statement(true_stmt, trueblk);

    // Assign exits
    blk->set_true_exit(while_blk);
    while_blk->set_true_exit(trueblk);
    while_blk->set_false_exit(falseblk);

    trueblk->set_true_exit(while_blk);
    currblk = falseblk; // Update block we're on
}

void
convert_statement(Node* node, Block* blk)
{
    if(node->type == "Assign")
        create_assign_IR(node, blk);

    else if(node->type == "IF")
        create_if_IR(node, blk);   

    else if(node->type == "WHILE")
        create_while_IR(node, blk);

    else if(node->type == "Statement List")
    {
        for(auto it = node->children.begin(); it != node->children.end(); it++)
            convert_statement(*it, blk);
    }
    else if(node->type == "Statement")
    {
        
    }

    else {
        std::cout << "Encountered unhandled statement " << node->type << "\n";
    }
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
        TAC* tac = new AssignTAC(to_local_var_name(blk->last_local_id), op, "", c);
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
        TAC* tac = new AssignTAC(to_local_var_name(blk->last_local_id), op, l, r);

        blk->add_tac(tac);
    }
    return to_local_var_name(blk->last_local_id);
}

string 
convert_expression(Node* node, Block* blk)
{
    return expr_node_to_tacs(node, blk);
}
}
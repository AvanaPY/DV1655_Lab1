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
    { "new[]", "NEW[]" },
    { "Function Call", "call"},
    { "THIS", "THIS" }
};
static int blk_count;

string 
get_op(Node* node)
{
    if(opmap.count(node->type))
        return opmap[node->type];
    
    std::cout << "BIG ERROR: Unhandled get_op: (" << node->type << ", " << node->value << ")\n";
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

class PrintTAC : public TAC {
public:
    PrintTAC(std::string lhs) : TAC("PRINT", "", lhs, ""){}

    void dump(std::ofstream& stream)
    {
        stream  << result << " "
                << lhs << " "
                << op  << " "
                << rhs;
    }

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }
};

class ParamTAC : public TAC {
public:
    ParamTAC(std::string name) : TAC("param", "", name, ""){}

    void dump(std::ofstream& stream)
    {
        stream  << result << " "
                << lhs << " "
                << op  << " "
                << rhs;
    }

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }
};

class CallTAC : public TAC {
public:
    CallTAC(std::string res, std::string name, int params) : TAC(res, "call", name, std::to_string(params)){}

    void dump(std::ofstream& stream)
    {
        stream  << result << " := "
                << op  << " "
                << lhs << " "
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

public:
    Block *trueExit, *falseExit;
    list<TAC*> tacs;
    string name;
    int last_local_id;
    Block(string n) : name(n), trueExit(NULL), falseExit(NULL) {
    }

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
            stream << "  " << name << " -> " << trueExit->name << "[xlabel=\"True\"];" << std::endl;
            trueExit->dump_rec(stream, dump_map);
        }
        
        if(falseExit != nullptr){
            stream << "  " << name << " -> " << falseExit->name << "[xlabel=\"False\"];" << std::endl;
            falseExit->dump_rec(stream, dump_map);
        }
    }
};

void dump_cfg(std::ofstream&);
void traverse_ast(Node* node, list<Block*>* blks);
Block* convert_statement(Node* node, Block* currblk);
string convert_expression(Node* node, Block* currblk);
std::string expr_node_to_tacs(Node* node, Block* blk);

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

Block*
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
    currblk = blk;
    return currblk;
}

Block*
create_if_IR(Node* node, Block* blk)
{
    // Create our new if block
    
    // Convert the conditional expression
    string lvm = convert_expression(node->children.front(), blk);
    blk->add_tac(new CondTAC("IF", "", "", lvm));
    stack_tacs(blk); // Stack the last 2 tacs for nice looking IR

    // // Create a true and a false block
    blk_count++;
    Block* trueblk = new Block(generic_blk_name_from_id(blk_count));
    
    blk_count++;
    Block* falseblk = new Block(generic_blk_name_from_id(blk_count));

    // Iterate over the nodes and convert the statements to blocks
    auto it = node->children.begin(); std::advance(it, 1);
    Node* true_stmt = *it; std::advance(it, 1);
    Node* false_stmt = *it; 

    Block* a = convert_statement(true_stmt, trueblk);
    Block* b = convert_statement(false_stmt, falseblk);

    // // Create an exit block
    blk_count++;
    Block* exitblk = new Block(generic_blk_name_from_id(blk_count));

    // // Assign exits
    blk->set_true_exit(trueblk);
    blk->set_false_exit(falseblk);

    a->set_true_exit(exitblk);
    b->set_true_exit(exitblk);

    currblk = exitblk; // Update block we're on
    return currblk;
}

Block*
create_while_IR(Node* node, Block* blk)
{
    
    string lvm = convert_expression(node->children.front(), blk);
    blk->add_tac(new CondTAC("WHILE", "", "", lvm));
    stack_tacs(blk);

    // Create a true and a false block
    blk_count++;
    Block* trueblk = new Block(generic_blk_name_from_id(blk_count));
    
    blk_count++;
    Block* falseblk = new Block(generic_blk_name_from_id(blk_count));

    // Iterate over the nodes and convert the statements to blocks
    auto it = node->children.begin(); std::advance(it, 1);
    Node* true_stmt = *it; std::advance(it, 1);
    Block* a = convert_statement(true_stmt, trueblk);

    // Assign exits
    blk->set_true_exit(trueblk);
    blk->set_false_exit(falseblk);

    a->set_true_exit(blk);
    currblk = falseblk; // Update block we're on
    return falseblk;
}

Block*
create_sysprint_IR(Node* node, Block* blk)
{
    string expr = expr_node_to_tacs(node->children.front(), blk);
    blk->add_tac(new PrintTAC(expr));
    // stack_tacs(blk);
    return blk;
}

Block*
convert_statement(Node* node, Block* blk)
{
    Block* finalblk;
    if(node->type == "Assign")
        finalblk = create_assign_IR(node, blk);

    else if(node->type == "IF")
        finalblk = create_if_IR(node, blk);   

    else if(node->type == "WHILE")
        finalblk = create_while_IR(node, blk);

    else if(node->type == "SYS_PRINTLN")
        finalblk = create_sysprint_IR(node, blk);

    else if(node->type == "Statement List")
    {
        finalblk = blk;
        for(auto it = node->children.begin(); it != node->children.end(); it++)
            finalblk = convert_statement(*it, finalblk);
    } 
    else if(node->type == "Statement"){
        finalblk = blk;
    }
    else {
        finalblk = blk;
    }
    return finalblk;
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
    if(node->type == "THIS")
        return "THIS";

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
    else if(node->type == "Function Call")
    {
        auto it = node->children.begin();

        std::string cls_expr = expr_node_to_tacs(*it, blk);
        blk->add_tac(new ParamTAC(cls_expr));

        std::advance(it, 1);
        Node* identifier = *it; std::advance(it, 1);
        Node* args = *it;

        for(auto it_args = args->children.begin(); it_args != args->children.end(); it_args++){
            string args_id = expr_node_to_tacs(*it_args, blk);
            blk->add_tac(new ParamTAC(args_id));
        }

        blk->last_local_id++;
        blk->add_tac(new CallTAC(to_local_var_name(blk->last_local_id), identifier->value, 1  + args->children.size()));
    }
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
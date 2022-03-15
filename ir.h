#include<iostream>
#include <fstream>
#include<string.h>
#include <list>
#include <map>
#include "Node.h"
#include "TAC.h"

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
    { "Assign[]", "@" },
    { "new()", "NEW" },
    { "new[]", "NEW[]" },
    { "Function Call", "call"},
    { "THIS", "THIS" }
};

map<std::string, std::string> op_byte_code = {
    { "ADD" , "iadd" },
    { "SUB", "isub" },
    { "DIV"  , "idiv" },
    { "MUL" , "imul" },
    { "AND"  , "iand" },
    { "OR"   , "ior" },
    { "NOT"  , "inot" },
    { "GT"  , "igt" },
    { "LT"  , "ilt" },
    { "EQ"  , "ieq" }
};

class Block
{
private:
    TAC* condition;
    bool code_dumped;

public:
    Block *trueExit, *falseExit;
    list<TAC*> tacs;
    string name;
    int last_local_id;
    Block(string n) : name(n), trueExit(NULL), falseExit(NULL) {
        code_dumped = false;
    }

    void add_tac(TAC* tac);
    TAC* find_tac(std::string local_var_name);
    void set_true_exit(Block* blk);
    void set_false_exit(Block* blk);
    void set_condition(TAC* tac);
    void dump(std::ofstream& stream); 
    void dump_rec(std::ofstream& stream, map<std::string, int>* dump_map);
    void dump_code(std::ofstream& stream, Block* starting_block);
};

static int blk_count;
std::string curr_class_name;
Block* currblk;
int block_id = 0;

void dump_cfg(std::ofstream&);
void traverse_ast(Node* node, list<Block*>* blks);
Block* convert_statement(Node* node, Block* currblk);
std::string convert_expression(Node* node, Block* currblk);
std::string expr_node_to_tacs(Node* node, Block* blk);

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

void 
Block::add_tac(TAC* tac)
{
    tacs.push_back(tac);
}

TAC* 
Block::find_tac(std::string local_var_name)
{
    for(auto it = tacs.begin(); it != tacs.end(); it++)
        if((*it)->get_result() == local_var_name)
            return *it;
    return nullptr;
}

void 
Block::set_true_exit(Block* blk)
{
    trueExit = blk;
}

void 
Block::set_false_exit(Block* blk)
{
    falseExit = blk;
}

void 
Block::set_condition(TAC* tac)
{
    condition = tac;
}

void 
Block::dump(std::ofstream& stream)
{
    map<std::string, int> dump_map;
    dump_rec(stream, &dump_map);
}

void 
Block::dump_rec(std::ofstream& stream, map<std::string, int>* dump_map)
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

void 
Block::dump_code(std::ofstream& stream, Block* starting_block)
{
    // Check if this block has already been code dumped
    if(code_dumped)
        return;
    code_dumped = true;

    // Create start of block
    stream << name << ":\n";

    // This is such a horrible solution to calls, but it works
    // "It is not horrible if it works" - Sun Tzu
    TAC* invoke_class_tac = nullptr;
    bool listing_params = false;
    bool dump_true_exit_goto = false;

    std::string op, res;
    for(auto it = tacs.begin(); it != tacs.end(); it++)
    {
        op = (*it)->get_op();
        res = (*it)->get_result();
        if(op == "param")
        {
            if(listing_params)
            {
                (*it)->dump_code(stream);
            }
            else
            {
                invoke_class_tac = *it;
                listing_params = true;
            }
        }
        else if(op == "call")
        {
            listing_params = false;
            std::string target_class = invoke_class_tac->get_rhs();
            if(target_class == "THIS")
            {
                int uid = starting_block->name.find("_");
                (*it)->dump_code(stream, starting_block->name.substr(0, uid));
            }
            else
            {
                TAC* tac = find_tac(target_class);
                (*it)->dump_code(stream, tac->get_rhs());
            }
        }
        else if(res == "IF")
            (*it)->dump_code(stream, trueExit->name, falseExit->name);
        else if(res == "WHILE")
        {
            (*it)->dump_code(stream, trueExit->name, falseExit->name);
            dump_true_exit_goto = true;
        }
        else
            (*it)->dump_code(stream);
        
    }
    // If this is our "Main" block, put a stop at the very end
    if(name.compare(name.size() - 4, 4, "Main") == 0)
        stream << "\tstop\n";

    // Continue
    if(trueExit != nullptr)
    {
        trueExit->dump_code(stream, starting_block);
        if(dump_true_exit_goto)
            stream << "\tgoto " << name << "\n";
    }
        
    if(falseExit != nullptr)
    {
        falseExit->dump_code(stream, starting_block);
        if(falseExit->trueExit != nullptr)
            stream << "\tgoto " << falseExit->trueExit->name << "\n";
    }
}

string 
convert_expression(Node* node, Block* blk)
{
    return expr_node_to_tacs(node, blk);
}

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

void
stack_tacs(Block* blk)
{
    if(blk->tacs.size() < 2)
        return;
        
    TAC* a = blk->tacs.back(); blk->tacs.pop_back();
    TAC* b = blk->tacs.back(); blk->tacs.pop_back();

    if(b->get_op() == "call")
    {
        b->stack_with(a);
        blk->add_tac(b);
        blk->last_local_id--;
    }
    else 
    {
        a->stack_with(b);
        blk->add_tac(a);
        blk->last_local_id--;
    }
}

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
        std::string n = curr_class_name + "_" + node->value;
        Block* blk = new Block(n);
        entry_points->push_back(blk);
        currblk = blk;

        for(auto it = node->children.begin(); it != node->children.end(); it++)
            traverse_ast(*it, entry_points);

        Node* ret = node->children.back();
        if(ret->value == "Expression")
        {
            std::string local_var_name = convert_expression(ret->children.front(), currblk);
            currblk->add_tac(new ReturnTAC(local_var_name));
        }
    }
    else if(node->type == "Parameter List")
    {
        for(auto it = node->children.rbegin(); it != node->children.rend(); it++)
        {
            Node* id_node = (*it)->children.back();
            currblk->add_tac(new ArgTAC(id_node->value));
        }
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

Block*
create_assign_IR(Node* node, Block* blk)
{
    string typ = node->children.back()->type;

    if(typ == "Int")
    {
        blk->add_tac(new AssignTAC(node->children.front()->value, "", "$" + node->children.back()->value, ""));
    }
    else if(typ == "Identifier" || typ == "Bool")
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
create_assign_arr_IR(Node* node, Block* blk)
{
    auto it = node->children.begin();

    Node* identifier = *it; std::advance(it, 1);
    Node* index      = *it; std::advance(it, 1);
    Node* value      = *it;

    std::string local_var_name = convert_expression(value, blk);
    blk->add_tac(new AssignTAC(identifier->value, get_op(node), local_var_name, "$" + index->value));

    currblk = blk;
    return currblk;
}

Block*
create_if_IR(Node* node, Block* blk)
{
    // Create our new if block
    

    blk_count++;
    Block* if_blk = new Block(generic_blk_name_from_id(blk_count));

    // Convert the conditional expression
    string lvm = convert_expression(node->children.front(), if_blk);

    if_blk->add_tac(new CondTAC("IF", "", "", lvm));
    stack_tacs(if_blk); // Stack the last 2 tacs for nice looking IR

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

    blk->set_true_exit(if_blk);

    // Assign exits
    if_blk->set_true_exit(trueblk);
    if_blk->set_false_exit(falseblk);

    a->set_true_exit(exitblk);
    b->set_true_exit(exitblk);

    currblk = exitblk; // Update block we're on
    return currblk;
}

Block*
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
    Block* a = convert_statement(true_stmt, trueblk);

    blk->set_true_exit(while_blk);

    // Assign exits
    while_blk->set_true_exit(trueblk);
    while_blk->set_false_exit(falseblk);

    a->set_true_exit(while_blk);
    currblk = falseblk; // Update block we're on
    return falseblk;
}

Block*
create_sysprint_IR(Node* node, Block* blk)
{
    string expr = expr_node_to_tacs(node->children.front(), blk);
    blk->add_tac(new PrintTAC(expr));
    //stack_tacs(blk);
    return blk;
}

Block*
convert_statement(Node* node, Block* blk)
{
    Block* finalblk;
    if(node->type == "Assign")
        finalblk = create_assign_IR(node, blk);

    else if(node->type == "Assign[]")
        finalblk = create_assign_arr_IR(node, blk);

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
}
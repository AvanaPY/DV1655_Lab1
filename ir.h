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

map<std::string, int> bool_map = {
    { "false" , 0 },
    { "true"  , 1 }
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
    
    virtual void dump(std::ofstream& stream)
    {
        stream  << result 
                << " := "
                << op << " " 
                << lhs << " " 
                << rhs;
    }
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

    void dump_lhs(std::ofstream& stream)
    {
        stream << value_to_instruction(lhs);
    }
    
    void dump_rhs(std::ofstream& stream)
    {
        stream << value_to_instruction(rhs);
    }

    void dump_op(std::ofstream& stream)
    {
        if(op.size() == 0)
            return;
        string op_bc = op_byte_code[op];
        stream << "\t" << op_bc << "\n";
    }

    void dump_result(std::ofstream& stream)
    {
        if(result.size() == 0)
            return;

        if(result.find("_+") == -1)
        {
            stream << "\tistore " << result << "\n";
        }
    }

    std::string value_to_instruction(std::string v)
    {
        if(v.find("_+") != -1 || v.size() == 0)
            return "";

        std::string res;
        if(bool_map.count(v) != 0)
        {
            res = "\ticonst " + bool_map[v];
        }
        else if(v.find("$") == -1)
        {
            res = "\tiload " + v;
        }
        else
        {
            res = "\ticonst " + v.substr(1, v.size() - 1);
        }
        return res + "\n";
    }

    virtual void stack_with(TAC* tac) {};
    virtual void dump_code(std::ofstream& stream){};
    virtual void dump_code(std::ofstream& stream, std::string argument){};
    virtual void dump_code(std::ofstream& stream, std::string arg1, std::string arg2){};
};

class AssignTAC : public TAC {
public:
    AssignTAC(std::string res, std::string o, std::string l, std::string r) : TAC(res, o, l, r){}

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }

    void dump_code(std::ofstream& stream)
    {
        dump_lhs(stream);
        dump_rhs(stream);
        dump_op(stream);
        dump_result(stream);
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
    
    void dump_code(std::ofstream& stream, std::string true_exit, std::string false_exit)
    {
        dump_lhs(stream);
        dump_rhs(stream);
        dump_op(stream);
        stream << "\tiffalse goto \n\t\t" << false_exit << "\n";
    }
    
    void dump_code(std::ofstream& stream, std::string true_exit, std::string false_exit, std::string org_exit)
    {
        dump_lhs(stream);
        dump_rhs(stream);
        dump_op(stream);
        stream << "\tiffalse goto \n\t\t" << false_exit << "\n";
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

    void dump_code(std::ofstream& stream)
    {
        if(lhs.find("$") != -1)
            stream << "\ticonst " << lhs.substr(1, lhs.size() - 1) << "\n";
        stream << "\tprint\n";
    }
};

class ParamTAC : public TAC {
public:
    ParamTAC(std::string name) : TAC("", "param", "", name){}

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

    void dump_code(std::ofstream& stream)
    {
        stream << value_to_instruction(rhs);
    }
};

class CallTAC : public TAC {
public:
    CallTAC(std::string res, std::string name, int params) : TAC(res, "call", name, std::to_string(params)){}

    void stack_with(TAC* tac)
    {
        result = tac->get_result();
    }

    void dump_code(std::ofstream& stream, std::string class_name)
    {
        stream << "\tinvokevirtual " << class_name << "_" << lhs << "\n";
    }
};

class ReturnTAC : public TAC {
public:
    ReturnTAC(std::string res) : TAC("", "", res, ""){}

    void dump(std::ofstream& stream)
    {
        stream  << "RETURN " << lhs; 
    }

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }

    void dump_code(std::ofstream& stream)
    {
        dump_lhs(stream);
        dump_rhs(stream);
        dump_op(stream);
        dump_result(stream);
        stream << "\tireturn\n";
    }
};

class Block {

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

    void add_tac(TAC* tac)
    {
        tacs.push_back(tac);
    }

    TAC* find_tac(std::string local_var_name)
    {
        for(auto it = tacs.begin(); it != tacs.end(); it++)
            if((*it)->get_result() == local_var_name)
                return *it;
        return nullptr;
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

    void dump_code(std::ofstream& stream)
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
                    
                    (*it)->dump_code(stream, name.substr(0, name.find("_")));
                }
                else
                {
                    TAC* tac = find_tac(invoke_class_tac->get_rhs());
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
            trueExit->dump_code(stream);
            if(dump_true_exit_goto && !code_dumped)
                stream << "\tgoto " << name << "\n";
        }
            
        if(falseExit != nullptr)
        {
            falseExit->dump_code(stream);
            if(falseExit->trueExit != nullptr)
                stream << "\tgoto " << falseExit->trueExit->name << "\n";
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
        else
            currblk->add_tac(new ReturnTAC(""));
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

string 
convert_expression(Node* node, Block* blk)
{
    return expr_node_to_tacs(node, blk);
}
}
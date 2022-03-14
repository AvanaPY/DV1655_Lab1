#ifndef SEMANTIC_H
#define	SEMANTIC_H
#define T_UNKNOWN "Unknown"

#include "Node.h"
#include "ST.h"
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

bool errored;

namespace Semantic {

string evaluate_function_call(Node* node, ST* scope);
string evaluate_expression_type(Node* node, ST* scope);
void evaluate_statement(Node* node, ST* scope);
void explore_node(Node* node, ST* scope);
void verify_variable_parameter_type(Node* var_node, ST* scope);

void 
error(string err)
{
    std::cout << "Semantic error: " << err << "\n";
    errored = true;
}

string
evaluate_function_call(Node* node, ST* scope)
{
    std::list<Node*>::iterator it = node->children.begin();
    Node* id1 = *it; std::advance(it, 1);
    Node* id2 = *it;  std::advance(it, 1);
    Node* args = *it;
    ST* org_scope = scope;

    // If the first identifier in a function call is THIS then we don't have to update our scope
    if(id1->type == "THIS")
    {
        scope = scope->parent;
    }  
    else {
        string expr_type = evaluate_expression_type(id1, scope);

        ST* id1_scope = scope->find_scope(expr_type);
        if(id1_scope == nullptr) {
            error("15 Cannot find scope " + expr_type + " in scope (" + scope->name + ")");
            return T_UNKNOWN;
        }

        scope = id1_scope;
    }

    // Find the symbol in the current scope
    Symbol* sym = scope->find_local_symbol(id2->value);
    if(sym == nullptr){
        error("16 Cannot find symbol " + id2->value + " in scope (" + scope->name + ")");
        return T_UNKNOWN;
    }
    
    // And make sure it is a method, we cannot call on a non-method type
    if(sym->type != "Method")
    {
        error("17 Symbol " + sym->symbol + " is not a method");
        return T_UNKNOWN;
    }

    ST* method_scope = scope->find_scope(sym->symbol);
    if(method_scope == nullptr){
        error("18 Cannot find a scope for " + sym->symbol);
        return T_UNKNOWN;
    }

    scope = method_scope;

    int input_arg_count = node->children.back()->children.size();
    int param_count = scope->num_param_symbols();

    if(input_arg_count != param_count)
    {
        error("19 Arguments and parameters not matching in function call. Expected: " + to_string(param_count) + ", Got: " + to_string(input_arg_count));
        return T_UNKNOWN;
    }

    list<Symbol*>* params = new list<Symbol *>();
    scope->get_params(params);

    auto param_it = params->begin();
    auto arg_it   = node->children.back()->children.begin();

    for(int i = 0; i < param_count; i++)
    {
        string arg_type = evaluate_expression_type(*arg_it, org_scope);
        if(arg_type == "Identifier")
        {
            Symbol* s = org_scope->find_symbol((*arg_it)->value);
            if(s == nullptr)
                error("20.1 Cannot find symbol " + s->symbol);
            else
                arg_type = s->type;
        }

        if((*param_it)->type != arg_type){
            error("20.2 Cannot match argument " + (*param_it)->symbol + " of type " + (*param_it)->type + " to type " + arg_type + " in " + scope->name);
        }
        std::advance(param_it, 1);
        std::advance(arg_it, 1);
    }
    return sym->attr;
}

string
evaluate_expression_type(Node* expr_node, ST* scope)
{
    if (expr_node->type == "PLUS" || expr_node->type == "MINUS" || expr_node->type == "MULT" || expr_node->type == "DIV")
    {
        string right_typ = evaluate_expression_type(expr_node->children.back(), scope);
        string left_typ = evaluate_expression_type(expr_node->children.front(), scope);

        if(right_typ != left_typ){
            return right_typ + "/" + left_typ;
        }
        return right_typ;
    }   
    else if (expr_node->type == "NOT")
    {
        string child_typ = evaluate_expression_type(expr_node->children.front(), scope);
        return child_typ;
    } 
    else if(expr_node->type == "LT" || expr_node->type == "GT" || expr_node->type == "EQ")
    {
        string right_typ = evaluate_expression_type(expr_node->children.back(), scope);
        string left_typ = evaluate_expression_type(expr_node->children.front(), scope);

        if(right_typ != "Int" || left_typ != "Int"){
            return T_UNKNOWN;
        }
        return "Bool";
    }
    else if(expr_node->type == "AND" || expr_node->type == "OR")
    {
        string right_typ = evaluate_expression_type(expr_node->children.back(), scope);
        string left_typ = evaluate_expression_type(expr_node->children.front(), scope);
        if(right_typ != "Bool" || left_typ != "Bool"){
            return T_UNKNOWN;
        }
        return "Bool";
    }
    else if(expr_node->type == "Int" || expr_node->type == "Bool")
    {
        return expr_node->type; 
    } 
    else if(expr_node->type == "Identifier")
    {
        Symbol* sym = scope->find_symbol(expr_node->value);
        if(sym == nullptr)
            error("10 Cannot find symbol " + expr_node->value + " in scope (" + scope->name + ")");
        else if(sym->type == "Class")
            return sym->symbol;
        else
            return sym->type;
        return T_UNKNOWN;
    }
    else if(expr_node->type == "Function Call")
    {
        string typ = evaluate_function_call(expr_node, scope);
        return typ;
    }
    else if(expr_node->type == "new()")
    {
        Node* id_node = *expr_node->children.begin();
        return id_node->value;
    }
    else if(expr_node->type == "new[]")
    {
        Node* array_len_node = expr_node->children.front();
        if(array_len_node->type != "Int")
        {
            if(array_len_node->type == "Identifier"){
                Symbol* sym = scope->find_symbol(array_len_node->value);
                if(sym == nullptr)
                {
                    error("11.1 Cannot find symbol " + array_len_node->value);
                } 
                else
                {
                    if(sym->type != "Int")
                        error("11.2 " + array_len_node->type + " is an invalid type for array length assignment, expected Integer");
                }
            }
            else
                error("11.3 " + array_len_node->type + " is an invalid type for array length assignment, expected Integer");
        }
        return "Int[]";
    }
    else if(expr_node->type == "LENGTH")
    {
        Node* identifier = expr_node->children.front();
        Symbol* sym = scope->find_symbol(identifier->value);
        if(sym == nullptr)
            error("12.1 Cannot find symbol " + identifier->value);
        else if(sym->type != "Int[]")
            error("12.2 Cannot call .length on type " + sym->type);
        return "Int";
    }
    else if(expr_node->type == "Statement")
    {
        return evaluate_expression_type(expr_node->children.front(), scope);
    }
    else if (expr_node->type == "THIS")
    {
        return scope->parent->name;
    }
    else if(expr_node->type == "Indexing")
    {
        Node* identifier = expr_node->children.front();
        Node* index = expr_node->children.back();

        Symbol* sym = scope->find_symbol(identifier->value);
        if(sym == nullptr){
            error("13.1 Cannot find symbol " + identifier->value + " in method " + scope->name);
            return T_UNKNOWN;
        }
        if(sym->type != "Int[]")
        {
            error("13.2 Cannot index type " + sym->type + ", expected Int[]");
            return T_UNKNOWN;
        }
        if(index->type == "Identifier")
        {
            Symbol* index_symbol = scope->find_symbol(index->value);
            if(index_symbol == nullptr)
            {
                error("13.3 Cannot find symbol " + index->value + " in method " + scope->name);
                return T_UNKNOWN;
            }
            if(index_symbol->type != "Int")
            {
                error("13.4 Cannot index with type " + index_symbol->type + ", expected Integer");
                return T_UNKNOWN;
            }
        }
        else if(index->type != "Int")
        {
            error("13.5 Cannot index with type " + index->type + ", expected Integer");
            return T_UNKNOWN;
        }
        return "Int";
    }
    else {
        error("14 Expression Evaluation: " + expr_node->type + " is not implemented.");
    }
    return T_UNKNOWN;
}

void
evaluate_statement(Node* stmt_node, ST* scope)
{
    if(stmt_node->type == "Assign"){

        Node* identifier = stmt_node->children.front();
        Symbol* id_sym   = scope->find_symbol(identifier->value);
        if(id_sym == nullptr){
            error("5 Cannot find symbol " + identifier->value + " in scope (" + scope->name + ")");
            return;
        }
        Node* expr_node = stmt_node->children.back();
        string typ = evaluate_expression_type(expr_node, scope);
        if (typ != id_sym->type){
            error("5.1 Cannot match type " + id_sym->type + " to " + typ + " in " + scope->name);
        }
    }
    else if(stmt_node->type == "IF") 
    {
        Node* cond_node = stmt_node->children.front();
        string cond_type = evaluate_expression_type(cond_node, scope);
        if(cond_type != "Bool")
            error("6 Expression is not of type Bool in IF statement");

        auto it = stmt_node->children.begin();
        std::advance(it, 1); Node* if_node = *it;
        std::advance(it, 1); Node* else_node = *it;

        if(if_node->type == "Statement List")
            for(auto c = if_node->children.begin(); c != if_node->children.end(); c++)
                evaluate_statement(*c, scope);
        else
            evaluate_statement(if_node, scope);

        if(else_node->type == "Statement List")
            for(auto c = else_node->children.begin(); c != else_node->children.end(); c++)
                evaluate_statement(*c, scope);
        else
            evaluate_statement(else_node, scope);
    }
    else if(stmt_node->type == "WHILE")
    {
        Node* cond_node = stmt_node->children.front();
        string cond_type = evaluate_expression_type(cond_node, scope);

        if(cond_type != "Bool")
            error("7 Expression is not of type Bool in WHILE statement");

        Node* statements = stmt_node->children.back();
        if(statements->type == "Statement List")
            for(auto c = statements->children.begin(); c != statements->children.end(); c++)
                evaluate_statement(*c, scope);
        else
            evaluate_statement(statements, scope);
    }   
    else if(stmt_node->type == "SYS_PRINTLN")
    {
        Node* identifier = stmt_node->children.front();

        if(identifier->type == "Int")
            return;

        string expr_type = evaluate_expression_type(identifier, scope);
        if(expr_type != "Int"){
            error("8 Cannot print type " + expr_type + ", expected Integer");
            return;
        }
    }
    else if(stmt_node->type == "Function Call")
    {
        evaluate_function_call(stmt_node, scope);
        return;
    }
    else if(stmt_node->type == "Statement List")
    {
        for(auto n = stmt_node->children.begin(); n != stmt_node->children.end(); n++)
            evaluate_statement((*n), scope);
        return;
    }
    else if(stmt_node->type == "Assign[]") 
    {
        auto it = stmt_node->children.begin();
        Node* identifier = *it;        std::advance(it, 1);
        Node* assign_index_node = *it; std::advance(it, 1);
        Node* assign_value_node = *it;

        Symbol* id_sym = scope->find_symbol(identifier->value);
        if(id_sym == nullptr)
            error("9.1 Cannot find symbol " + identifier->value);
        else if(id_sym->type != "Int[]")
            error("9.2 Cannot index assign non-array type (" + id_sym->type + ")");

        string index_expr_type = evaluate_expression_type(assign_index_node, scope);
        if(index_expr_type != "Int")
            error("9.3 Cannot index with non-integer value");

        string assign_value_type = evaluate_expression_type(assign_value_node, scope);
        if(assign_value_type != "Int")
            error("9.4 Cannot assign non-integer value to type int[]");
    }
    else if(stmt_node->value == "Empty")
    { return; }
    else {
        evaluate_expression_type(stmt_node, scope);
        //error("13 Statement Evaluation : " + stmt_node->type + " is not implemented");
    }
}

void
verify_variable_parameter_type(Node* var_node, ST* scope)
{
    Node* type = var_node->children.front();
    Node* id   = var_node->children.back();
    if(type->type == "Type")
        return;
    
    Symbol* sym = scope->find_symbol(type->value);
    if(sym == nullptr)
        error("21 Cannot find symbol for type " + type->value + " (" + var_node->type + " " + id->value + " in scope " + scope->name + ")");
}

void
explore_node(Node* node, ST* scope)
{
    if(node->type == "MainClass" || node->type == "Class") 
    {
        ST* child = scope->get_child(node->value);
        if(child == nullptr)
            error("1 Cannot find class " + node->value + " in scope " + scope->name);
        scope = child;
    }
    else if(node->type == "Method")
    {
        ST* child = scope->get_child(node->value);
        if(child == nullptr)
            error("2 Cannot find method " + node->value + " in scope " + scope->name);
        scope = child;

        Node* type = node->children.front()->children.front();
        Node* return_type = node->children.back();

        if(return_type->value != "Void"){
            string ret_expr_type = evaluate_expression_type(return_type->children.front(), scope);

            if(type->type == "Identifier"){
                if(type->value != ret_expr_type)
                    error("3 Cannot convert " + ret_expr_type + " to " + type->type + " in method " + scope->name);
            }
            else if(type->type != ret_expr_type)
                error("3 Cannot convert " + ret_expr_type + " to " + type->type + " in method " + scope->name);
        }
    } 
    else if(node->type == "Statement List")
    {    
        for(auto n = node->children.begin(); n != node->children.end(); n++)
            evaluate_statement((*n), scope);
            
        return;
    }
    else if(node->type == "Variable" || node->type == "Parameter")  {
        verify_variable_parameter_type(node, scope);
        return; 
    }
    else if(node->type == "Identifier")
    {
        // This part might mostly be to catch return statements where we return an identifier
        // std::cout << "Looking for identifiers, but I think this might be a case that is not used, so if you see this message then I was very wrong and should most likely get an F on this assignment.";
        // std::cout << " (" << node->type << ", " << node->value << ")\n";
        Symbol* sym = scope->find_symbol(node->value);
        if(sym == nullptr)
            error("4 Cannot find symbol " + node->value + " in scope (" + scope->name + ")");
        return;
    }
    else if(node->type == "Function Call") { /* evaluate_statement(node, scope); */ return; }

    for(auto c = node->children.begin(); c != node->children.end(); c++)
        explore_node((*c), scope);
}

void
semantic_analysis(Node* root, ST* symbols)
{
    explore_node(root, symbols);

    if(!errored)
        std::cout << "No errors, your code is beautiful just like you <3\n";
}

}
#endif
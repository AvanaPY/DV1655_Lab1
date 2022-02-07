#ifndef SEMANTIC_H
#define	SEMANTIC_H

#include "Node.h"
#include "ST.h"
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

namespace Semantic {


string evaluate_function_call(Node* node, ST* scope);
string evaluate_expression_type(Node* node, ST* scope);
void evaluate_statement(Node* node, ST* scope);
void explore_node(Node* node, ST* scope);

void 
error(string err)
{
    std::cout << "Semantic error: " << err << "\n";
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
    if(id1->type != "THIS")
    {
        ST* id1_scope = scope->find_scope(id1->value);
        if(id1_scope == nullptr) {
            error("9 Cannot find symbol " + id1->value + " in scope (" + scope->name + ")");
            return "Unknown";
        }
        scope = id1_scope;
    }  else {
        scope = scope->parent;
    }

    // Find the symbol in the current scope
    Symbol* sym = scope->find_local_symbol(id2->value);
    if(sym == nullptr){
        error("10 Cannot find symbol " + id2->value + " in scope (" + scope->name + ")");
        return "Unknown";
    }
    
    // And make sure it is a method, we cannot call on a non-method type
    if(sym->type != "Method")
    {
        error("11 Symbol " + sym->symbol + " is not a method");
        return "Unknown";
    }

    ST* method_scope = scope->find_scope(sym->symbol);
    if(method_scope == nullptr){
        error("12 Cannot find a scope for " + sym->symbol);
        return "Unknown";
    }

    scope = method_scope;

    int input_arg_count = node->children.back()->children.size();
    int param_count = scope->num_param_symbols();

    if(input_arg_count != param_count)
    {
        error("12.1 Arguments and parameters not matching in function call. Expected: " + to_string(param_count) + ", Got: " + to_string(input_arg_count));
        return "Unknown";
    }

    list<Symbol*>* params = new list<Symbol *>();
    scope->get_params(params);

    auto param_it = params->begin();
    auto arg_it   = node->children.back()->children.begin();

    for(int i = 0; i < param_count; i++)
    {
        string arg_type = evaluate_expression_type(*arg_it, scope);
        if(arg_type == "Identifier")
        {
            Symbol* s = org_scope->find_symbol((*arg_it)->value);
            if(s == nullptr)
                error("12.2 Cannot find symbol " + s->symbol);
            else
                arg_type = s->type;
        }

        if((*param_it)->type != arg_type){
            error("12.3 Cannot match arguments " + (*param_it)->type + " to " + arg_type);
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
            return "Unknown";
        }
        return "Bool";
    }
    else if(expr_node->type == "AND" || expr_node->type == "OR")
    {
        string right_typ = evaluate_expression_type(expr_node->children.back(), scope);
        string left_typ = evaluate_expression_type(expr_node->children.front(), scope);
        if(right_typ != "Bool" || left_typ != "Bool"){
            return "Unknown";
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
            error("1 Cannot find symbol " + expr_node->value + " in scope (" + scope->name + ")");
        else
            return sym->type;
        return "Unknown";
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
            if(array_len_node->type == "Identifier")
                error(array_len_node->value + " is an invalid type for array length assignment, expected Integer");
            else
                error(array_len_node->type + " is an invalid type for array length assignment, expected Integer");
        }
        return "Int[]";
    }
    else if(expr_node->type == "LENGTH")
    {
        Node* identifier = expr_node->children.front();
        Symbol* sym = scope->find_symbol(identifier->value);
        if(sym == nullptr)
            error("Cannot find symbol " + identifier->value);
        else if(sym->type == "Int[]")
            return "Int";
        return "Unknown";
    }
    else if(expr_node->type == "Statement")
    {
        return evaluate_expression_type(expr_node->children.front(), scope);
    }
    else {
        error("2 Expression Evaluation: " + expr_node->type + " is not implemented.");
    }
    return "Unknown";
}

void
evaluate_statement(Node* stmt_node, ST* scope)
{
    if(stmt_node->type == "Assign"){

        Node* identifier = stmt_node->children.front();
        Symbol* id_sym   = scope->find_symbol(identifier->value);
        if(id_sym == nullptr){
            error("3 Cannot find symbol " + identifier->value + " in scope (" + scope->name + ")");
            return;
        }
        Node* expr_node = stmt_node->children.back();
        string typ = evaluate_expression_type(expr_node, scope);
        if (typ != id_sym->type){
            error("4 Cannot match type " + id_sym->type + " to " + typ);
        }
    }
    else if(stmt_node->type == "IF") 
    {
        Node* cond_node = stmt_node->children.front();
        string cond_type = evaluate_expression_type(cond_node, scope);

        if(cond_type != "Bool")
            error("5 Expression is not of type Bool in IF statement");

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
            error("6 Expression is not of type Bool in WHILE statement");

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
            error("12.4 Cannot find symbol " + identifier->value);
        else if(id_sym->type != "Int[]")
            error("Cannot index assign non-array type (" + id_sym->type + ")");

        string index_expr_type = evaluate_expression_type(assign_index_node, scope);
        if(index_expr_type != "Int")
            error("Cannot index with non-integer value");

        string assign_value_type = evaluate_expression_type(assign_value_node, scope);
        if(assign_value_type != "Int")
            error("Cannot assign non-integer value to type int[]");
    }
    else if(stmt_node->value == "Empty")
    { return; }
    else {
        evaluate_expression_type(stmt_node, scope);
        //error("13 Statement Evaluation : " + stmt_node->type + " is not implemented");
    }
}

void
explore_node(Node* node, ST* scope)
{
    if(node->type == "MainClass" || node->type == "Class") 
    {
        ST* child = scope->get_child(node->value);
        if(child == nullptr)
            error("14 Cannot find method " + node->value + " in scope " + scope->name);
        scope = child;
    }
    else if(node->type == "Method")
    {
        ST* child = scope->get_child(node->value);
        if(child == nullptr)
            error("15 Cannot find method " + node->value + " in scope " + scope->name);
        scope = child;

        Node* return_type = node->children.back();
        Node* type = node->children.front();

        type = type->children.front();
        string method_type = type->type == "Identifier" ? type->value : type->type;
        if(return_type->value != "Identifier"){
            if(return_type->value != method_type)
                error("16 Invalid return type, Cannot convert " + return_type->value + " to " + method_type + " in method " + node->value);
        } 
        else {
            Node* identifier = return_type->children.front();
            Symbol* symbol = scope->find_symbol(identifier->value);

            if(symbol == nullptr)
                error("17 Cannot find symbol " + identifier->value + " in scope (" + scope->name + ")");
            else if(method_type != symbol->type)
                error("18 Invalid return type, Cannot convert " + symbol->type + " to " + method_type + " in method " + node->value);
        }
        
    } 
    else if(node->type == "Statement List")
    {    
        for(auto n = node->children.begin(); n != node->children.end(); n++)
            evaluate_statement((*n), scope);
            
        return;
    }
    else if(node->type == "Identifier")
    {
        // This part might mostly be to catch return statements where we return an identifier
        // std::cout << "Looking for identifiers, but I think this might be a case that is not used, so if you see this message then I was very wrong and should most likely get an F on this assignment.";
        // std::cout << " (" << node->type << ", " << node->value << ")\n";
        Symbol* sym = scope->find_symbol(node->value);
        if(sym == nullptr)
            error("19 Cannot find symbol " + node->value + " in scope (" + scope->name + ")");
        return;
    }
    else if(node->type == "Variable")  { /* Skip variable and parameter declarations */ return; }
    else if(node->type == "Parameter") { /* Skip variable and parameter declarations */ return; }
    else if(node->type == "Function Call") { /* evaluate_statement(node, scope); */ return; }

    for(auto c = node->children.begin(); c != node->children.end(); c++)
        explore_node((*c), scope);
}

void
semantic_analysis(Node* root, ST* symbols)
{
    explore_node(root, symbols);
}

}
#endif
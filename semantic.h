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

void 
error(string err)
{
    std::cout << "Semantic error: " << err << "\n";
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
        if(id_sym == nullptr)
            error("3 Cannot find symbol " + identifier->value + " in scope (" + scope->name + ")");
        
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

        for(auto c = if_node->children.begin(); c != if_node->children.end(); c++)
            evaluate_statement(*c, scope);
        for(auto c = else_node->children.begin(); c != else_node->children.end(); c++)
            evaluate_statement(*c, scope);
    }
    else if(stmt_node->type == "WHILE")
    {
        Node* cond_node = stmt_node->children.front();
        string cond_type = evaluate_expression_type(cond_node, scope);

        if(cond_type != "Bool")
            error("6 Expression is not of type Bool in WHILE statement");

        Node* statements = stmt_node->children.back();
        for(auto c = statements->children.begin(); c != statements->children.end(); c++)
            evaluate_statement(*c, scope);
    }
    else if(stmt_node->type == "SYS_PRINTLN")
    {
        Node* identifier = stmt_node->children.front();

        if(identifier->type == "Int")
            return;

        Symbol* sym = scope->find_symbol(identifier->value);
        if(sym == nullptr) {
            error("7 Cannot find symbol " + identifier->value + " in scope (" + scope->name + ")");
            return;
        }
        if(sym->type != "Int"){
            error("8 Cannot print non-integer values");
            return;
        }
    }
    else if(stmt_node->type == "Function Call")
    {
        std::list<Node*>::iterator it = stmt_node->children.begin();
        Node* id1 = *it; std::advance(it, 1);
        Node* id2 = *it;  std::advance(it, 1);
        Node* args = *it;

        // If the first identifier in a function call is THIS then we don't have to update our scope
        std::cout << id1->type << "\n";
        if(id1->type != "THIS")
        {
            ST* id1_scope = scope->find_scope(id1->value);
            if(id1_scope == nullptr) {
                error("9 Cannot find symbol " + id1->value + " in scope (" + scope->name + ")");
                return;
            }
            scope = id1_scope;
            std::cout << "Setting scope to " << scope->name << "\n";
        }  else {
            scope = scope->parent;
            std::cout << "Setting scope to " << scope->name << "\n";
        }

        // Find the symbol in the current scope
        Symbol* sym = scope->find_symbol(id2->value);
        if(sym == nullptr){
            error("10 Cannot find symbol " + id2->value + " in scope (" + scope->name + ")");
            return;
        }
        
        // And make sure it is a method, we cannot call on a non-method type
        if(sym->type != "Method")
        {
            error("11 Symbol " + sym->symbol + " is not a method");
            return;
        }

        ST* method_scope = scope->find_scope(sym->symbol);
        if(method_scope == nullptr){
            error("12 Cannot find a scope for " + sym->symbol);
            return;
        }

        scope = method_scope;
        std::cout << "Setting scope to " << scope->name << "\n";
        

        return;
    }
    else {
        error("13 Statement Evaluation : " + stmt_node->type + " is not implemented");
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

        if(return_type->value != "Identifier"){
            if(return_type->value != type->value)
                error("16 Invalid return type, Cannot convert " + return_type->value + " to " + type->value + " in method " + node->value);

        } else {
            Node* identifier = return_type->children.front();
            Symbol* symbol = scope->find_symbol(identifier->value);

            if(symbol == nullptr)
                error("17 Cannot find symbol " + identifier->value + " in scope (" + scope->name + ")");
            else if(type->value != symbol->type)
                error("18 Invalid return type, Cannot convert " + symbol->type + " to " + type->value + " in method " + node->value);
        }
    } 
    else if(node->type == "Variable" || node->type == "Parameter"){ /* Skip variable and parameter declarations */ return; }
    else if(node->type == "Function Call") 
    {
        // evaluate_statement(node, scope);
        return;
    }
    else if(node->type == "Identifier")
    {
        Symbol* sym = scope->find_symbol(node->value);
        if(sym == nullptr)
            error("19 Cannot find symbol " + node->value + " in scope (" + scope->name + ")");
        return;
    }
    else if(node->type == "Statement List")
    {    
        for(auto n = node->children.begin(); n != node->children.end(); n++)
        {
            evaluate_statement((*n), scope);
        }
    }
    else {
        //std::cout << "Exploring node " << node->type << "\n";
    }

    for(auto c = node->children.begin(); c != node->children.end(); c++)
    {
        explore_node((*c), scope);
    }
}

void
semantic_analysis(Node* root, ST* symbols)
{
    explore_node(root, symbols);
}

}
#endif
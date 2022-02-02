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

void
explore_node(Node* node, ST* scope)
{
    if(node->type == "MainClass" || node->type == "Class") 
    {
        ST* child = scope->get_child(node->value);
        if(child == nullptr)
            error("Cannot find method " + node->value + " in scope " + scope->name);
        scope = child;
    }
    else if(node->type == "Method")
    {
        ST* child = scope->get_child(node->value);
        if(child == nullptr)
            error("Cannot find method " + node->value + " in scope " + scope->name);
        scope = child;

        Node* return_type = node->children.back();

        if(return_type->value != "Identifier")
            return;

        Node* type = node->children.front();

        Node* identifier = return_type->children.front();
        Symbol* symbol = scope->find_symbol(identifier->value);

        if(type->value != symbol->type)
        {
            error("Invalid return type, Cannot convert " + symbol->type + " to " + type->value + " in method " + node->value);
        }

    } 
    else if(node->type == "Variable" || node->type == "Parameter"){ /* Skip variable and parameter declarations */ return; }
    else if(node->type == "Function Call") 
    {
        std::list<Node*>::iterator it = node->children.begin();
        Node* id1 = *it; std::advance(it, 1);
        Node* id2 = *it;  std::advance(it, 1);
        Node* args = *it;

        // If the first identifier in a function call is THIS then we don't have to update our scope
        if(id1->type != "THIS")
        {
            ST* id1_scope = scope->find_scope(id1->value);
            if(id1_scope == nullptr) {
                error("Cannot find symbol " + id1->value + " in scope (" + scope->name + ")");
                return;
            }
            scope = id1_scope;
        }

        // Find the symbol in the current scope
        Symbol* sym = scope->find_symbol(id2->value);
        if(sym == nullptr){
            error("Cannot find symbol " + id2->value + " in scope (" + scope->name + ")");
            return;
        }
        
        // And make sure it is a method, we cannot call on a non-method type
        if(sym->type != "Method")
        {
            error("Symbol " + sym->symbol + " is not a method");
            return;
        }
        return;
    }
    else if(node->type == "Identifier")
    {
        Symbol* sym = scope->find_symbol(node->value);
        if(sym == nullptr)
            error("Cannot find symbol " + node->value + " in scope (" + scope->name + ")");
        return;
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
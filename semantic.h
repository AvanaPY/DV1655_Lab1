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
    } 
    else if(node->type == "Variable" || node->type == "Parameter"){ /* Skip variable and parameter declarations */ return; }
    else if(node->type == "Identifier")
    {
        Symbol* sym = scope->find_symbol(node->value);
        if(sym == nullptr)
            error("Cannot find symbol " + node->value + " in scope (" + scope->name + ")");
        else
            std::cout << "Found symbol " << sym->symbol << "\n";
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
    std::cout << "Beginning semantic analysis\n";
    explore_node(root, symbols);
}

}
#endif
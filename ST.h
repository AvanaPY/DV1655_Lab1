#ifndef ST_H
#define	ST_H

#include "Node.h"
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

extern bool errored;
static int symbol_table_count = 0;

class Symbol {
public:
	string symbol, type, scope, attr;
    Symbol(string sy, string typ, string sc, string at) :  symbol(sy), type(typ), scope(sc), attr(at){}

    void print(){
        cout << "     (" << symbol << ", " << type << ", " << scope << ", " << attr << ")\n";
    }

};

class ST {
public:
	int id;
	int current_scope;

    string name;
    list<Symbol*> symbols;

    ST* parent;
    list<ST*> children;
    
    ST(string n) : name(n) {
        id = symbol_table_count;
        symbol_table_count++;

        current_scope = id;
        parent = nullptr;
    }

    ST* copy() {
        ST* st = new ST(name);

        for(auto it = symbols.begin(); it != symbols.end(); it++)
            st->symbols.push_back(*it);
        for(auto it = children.begin(); it != children.end(); it++)
            st->children.push_back(*it);

        return st;
    }

    void error(string err)
    {
        cout << "Symbol Error: " << err << "\n";
        errored = true;
    }

    void explore(Node* root){
        explore_node(root, this);
    }

    void explore_node(Node* node, ST* scope)
    {
        for(auto i=node->children.begin(); i!=node->children.end(); i++){
            Node* c = (*i);
            
            if(c->type == "MainClass" || c->type == "Class")
            {
                Symbol* new_symbol = new Symbol(c->value, "Class", scope->name, "Identifier");
                scope->add_symbol(new_symbol);

                Node* front = c->children.front();
                std::cout << "Checking if " << c->value << " extends...\n";
                if(front->type == "Class Extends")
                {
                    ST* st = scope->find_scope(front->value);

                    ST* copy = st->copy();
                    copy->name = c->value;
                    copy->parent = scope;
                    scope->children.push_back(copy);
                    explore_node(c, copy);

                } else
                {
                    // Since it's a class, create a new Symbol Table
                    ST* st = new ST(c->value);
                    st->parent = scope;
                    scope->children.push_back(st);
                    explore_node(c, st);
                }
            }
            else if(c->type == "Method")
            {
                Node* method_type = c->children.front()->children.front();
                string type = method_type->type == "Identifier" ? method_type->value : method_type->type;  

                Symbol* new_symbol = new Symbol(c->value, c->type, scope->name, type);
                scope->add_symbol(new_symbol);
                
                // Since it's a method, create a new Symbol Table
                ST* st = new ST(c->value);
                st->parent = scope;
                scope->children.push_back(st);
                explore_node(c, st);
            }
            else if(c->type == "Variable")
            {
                Node* type       = c->children.front();
                Node* identifier = c->children.back();
                Symbol* var_symbol = new Symbol(identifier->value, type->value, scope->name, "Variable");
                scope->add_symbol(var_symbol);
            }
            else if(c->type == "Parameter") 
            {
                Node* type       = c->children.front();
                Node* identifier = c->children.back();
                Symbol* var_symbol = new Symbol(identifier->value, 
                                                type->value,
                                                scope->name, "Param");
                scope->add_symbol(var_symbol);
            }
            else {
                explore_node(c, scope); 
            }
        }
    }

    void add_symbol(Symbol* sym)
    {
        Symbol* local = find_local_symbol(sym->symbol);
        if(local == nullptr)
            symbols.push_back(sym);
        else
            error("A symbol of name " + sym->symbol + " already exists");
    }

    int num_param_symbols()
    {
        int params = 0;
        for(auto s = symbols.begin(); s != symbols.end(); s++)
        {
            if((*s)->attr == "Param")
                params++;
        }
        return params;
    }

    void get_params(list<Symbol*>* params)
    {
        for(auto s = symbols.begin(); s != symbols.end(); s++)
        {
            if((*s)->attr == "Param")
                params->push_back((*s));
        }
    }

    Symbol* find_local_symbol(string symname)
    {
        for(auto sym = symbols.begin(); sym != symbols.end(); sym++)
        {
            if((*sym)->symbol == symname)
                return (*sym);
        }
        return nullptr;
    }

    Symbol* find_symbol(string symname)
    {
        for(auto sym = symbols.begin(); sym != symbols.end(); sym++)
        {
            if((*sym)->symbol == symname)
                return (*sym);
        }
        if(parent == nullptr)
            return nullptr;
        return parent->find_symbol(symname);
    }

    ST* get_child(string name)
    {
        for(auto c = children.begin(); c != children.end(); c++)
        {
            if((*c)->name == name)
                return (*c);
        }
        return nullptr;
    }

    ST* find_scope(string name)
    {
        ST* scope = get_child(name);
        if(parent != nullptr && scope == nullptr)
            scope = parent->find_scope(name);
        return scope;
    }

    void print_table(int depth=0){
        for(int i = 0; i < depth; i++)
            cout << "   ";
        cout << name << "\n";
        for(auto sym = symbols.begin(); sym != symbols.end(); sym++)
        {
            for(int i = 0; i < depth; i++)
                cout << "   ";
            (*sym)->print();
        }
        for(auto st = children.begin(); st != children.end(); st++)
        {
            (*st)->print_table(depth+1);
        }
    }
};
#endif
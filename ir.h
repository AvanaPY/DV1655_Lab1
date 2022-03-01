#include<iostream>
#include <fstream>
#include<string.h>
#include <list>

namespace IR {

class TAC {
private:
    std::string result, op, lhs, rhs;

public:
    TAC(std::string res, std::string o, std::string l, std::string r) : op(o), lhs(l), rhs(r), result(res){}
    void dump(std::ofstream& stream){
        stream  << result 
                << " := "
                << lhs << " " 
                << op << " " 
                << rhs;
    }
};

class Block {

private:
    list<TAC*> tacs;
    TAC* condition;
    Block *trueExit, *falseExit;

public:
    string name;
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

    void dump_rec(std::ofstream& stream)
    {
        stream << "  " << name << " [label=\"" << name << "\\n";
        for(auto it = tacs.begin(); it != tacs.end(); it++)
        {
            (*it)->dump(stream);
            stream << "\\n";
        }
        stream << "\\n\"];" << std::endl;

        if(trueExit != nullptr){
            stream << "  " << name << " -> " << trueExit->name << "[xlabel=\"true\"];" << std::endl;
            trueExit->dump_rec(stream);
        }
        
        if(falseExit != nullptr){
            stream << "  " << name << " -> " << falseExit->name << "[xlabel=\"false\"];" << std::endl;
            falseExit->dump_rec(stream);
        }
    }
};

void 
dump_cfg(Block* root, std::ofstream& stream)
{
    stream << "digraph {\n"
           << "  graph [splines=ortho]\n"
           << "  node [shape=box]\n";
    root->dump_rec(stream);
    stream << "}";
}

}
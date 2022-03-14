#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include "Node.h"
#include <map>

namespace IR {

void dump_block_as_jbc(IR::Block* block, std::ofstream& stream);
void generate_code(list<IR::Block*>* entry_points, std::ofstream& stream);

void
generate_code(list<IR::Block*>* entry_points, std::ofstream& stream)
{
    for(auto it = entry_points->begin(); it != entry_points->end(); it++)
    {
        (*it)->dump_code(stream);
        stream << "\n\n";
    }
}

void
dump_block_as_jbc(IR::Block* block, std::ofstream& stream)
{
    stream << block->name << ":\n";




}
};
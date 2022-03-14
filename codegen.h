#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include "Node.h"
#include <map>

namespace IR {

void generate_code(list<IR::Block*>* entry_points, std::ofstream& stream);

void
generate_code(list<IR::Block*>* entry_points, std::ofstream& stream)
{
    for(auto it = entry_points->begin(); it != entry_points->end(); it++)
    {
        (*it)->dump_code(stream);
        stream << "\n";
    }
}
};
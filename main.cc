#include<iostream>
#include<fstream>
#include "ST.h"
#include "semantic.h"
#include "ir.h"
#include "parser.tab.hh"
#include<list>

extern Node* root;
extern FILE* yyin;
extern char* yytext;
int lineno=1;

void yy::parser::error(std::string const&err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << "\n   Line no: " << lineno << "\n   YYtext: " << yytext << "\n" << std::endl;
}

int main(int argc, char **argv)
{
  //Reads from file if a file name is passed as an argument. Otherwise, reads from stdin.
  if(argc > 1) {
      if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        printf("Error could not open file");
        return 1;
      }
  }

  yy::parser parser;
  if(!parser.parse()) {
    root->generate_tree();

    ST* symbol_table = new ST("Root");
    symbol_table->explore(root);
    Semantic::semantic_analysis(root, symbol_table);

    // symbol_table->print_table();
    // root->print_tree();
    std::ofstream o ("IR.dot");
    if (o.is_open()){

      list<IR::Block*> entry_points;
      IR::traverse_ast(root, &entry_points);
      IR::dump_cfg(&entry_points, o);

      o.close();
    } else {
      std::cout << "Cannot open file\n";
    }
  }

  return 0;
}
#include<iostream>
#include<fstream>
#include "ST.h"
#include "semantic.h"
#include "ir.h"
#include "parser.tab.hh"

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

    ST* symbol_table = new ST("Root");
    symbol_table->explore(root);
    Semantic::semantic_analysis(root, symbol_table);

    root->generate_tree();
    // symbol_table->print_table();
    // root->print_tree();
    std::ofstream o ("dot.dot");
    if (o.is_open()){
      IR::Block* entry = new IR::Block("Block_0");

      entry->add_tac(new IR::TAC("_+0", "SUB", "x", "$3"));
      entry->add_tac(new IR::TAC("_+1", "MUL", "y", "y"));
      entry->add_tac(new IR::TAC("z", "ADD", "_+0", "_+1"));


      IR::Block* new_blk = new IR::Block("Block_1");
      new_blk->add_tac(new IR::TAC("_+0", "SUB", "x", "$3"));
      new_blk->add_tac(new IR::TAC("_+1", "SUB", "x", "$3"));
      new_blk->add_tac(new IR::TAC("y", "SUB", "_+0", "_+1"));

      entry->set_true_exit(new_blk);

      new_blk = new IR::Block("Block_2");
      new_blk->add_tac(new IR::TAC("_+0", "SUB", "x", "$3"));

      entry->set_false_exit(new_blk);

      IR::dump_cfg(entry, o);
      o.close();
    } else {
      std::cout << "Cannot open file\n";
    }
  }

  return 0;
}
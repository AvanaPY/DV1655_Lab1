#include<iostream>
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
        root->print_tree();
        root->generate_tree();
    }
  
  return 0;
}
#include<iostream>
#include "parser.tab.hh"

extern Node* root;
extern FILE* yyin;
int lineno=1;

void yy::parser::error(std::string const&err)
{
  std::cout << "\nCannot generate a syntax tree for this input: " << err << "\n   Line no: " << lineno << std::endl;
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
      
    printf("Parsing...\n");
    if(!parser.parse()) {
        printf("Parsed\n");
        root->print_tree();
        root->generate_tree();
    }
  
  return 0;
}
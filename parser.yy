%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
    #include <string>
    #include "Node.h"
}
%code{
    #define YY_DECL yy::parser::symbol_type yylex()
    YY_DECL;
    Node* root;
    Node* classes;
}

// definition of set of tokens. All tokens are of type string
%token <std::string> INTEGER_LITERAL 
%token <std::string> IDENTIFIER 

%token CLASS  
%token MAIN EXTENDS STRING

%token PUBLIC STATIC  

%token VOID
%token <std::string> T_Int T_Bool T_True T_False

%token RETURN LENGTH
%token IF ELSE WHILE
%token SYS_PRINTLN
%token THIS NEW

%token PLUSOP MINOP MULOP DIVOP ASSIGN_OP

%token AND OR EQ LT GT DOT NOT 

%token LHKP RHKP LP RP LMP RMP 

%token COMMA SEMICOLON 

%left PLUSOP MINOP 
%left DIVOP MULOP  

%left AND OR NOT EQ LT GT DOT

%left T_Int T_Bool
%left IDENTIFIER

%right LHKP LP
%left RHKP RP

%right ASSIGN_OP

%type <Node *> Goal MainClass 
OptionalClassList ClassDeclaration ClassBody
VarList VarDeclaration 
MethodList MethodDeclaration MethodBodyDeclaration 
MethodParameterList MethodParameterDecl
Type 
Statement StatementList
Expression 
FunctionArgumentList 
Identifier

// definition of the production rules. All production rules are of type Node

%%
Goal                :   MainClass OptionalClassList {
                            $$ = new Node("Program", "");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            root = $$;
                        }
                    |   MainClass {
                            $$ = new Node("Program", "");
                            $$->children.push_back($1);
                            root = $$;
                        }
                    ;

MainClass           : CLASS Identifier LMP PUBLIC STATIC VOID MAIN LP STRING LHKP RHKP Identifier RP LMP StatementList RMP RMP {
                                                                    $$ = new Node("MainClass", $2->value);
                                                                    Node* n = new Node("Method", "Main");
                                                                    n->children.push_back(new Node("Type", "Void"));
                                                                    n->children.push_back($15);
                                                                    n->children.push_back(new Node("Returns", "Void"));
                                                                    $$->children.push_back(n);
                                                                }
                    ;

OptionalClassList   : OptionalClassList ClassDeclaration {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            $1->children.push_back($2);
                            $$ = $1;
                        }
                    | ClassDeclaration {
                            if(classes == NULL){
                                classes = new Node("Class List", "");
                            }
                            classes->children.push_back($1);
                            $$ = classes;
                        }
                    ;

ClassDeclaration    :   CLASS Identifier LMP ClassBody RMP {
                            $$ = new Node("Class", $2->value);
                            $$->children.push_back($4);
                        }
                    |   CLASS Identifier EXTENDS Identifier LMP ClassBody RMP{
                            $$ = new Node("Class", $2->value);

                            $$->children.push_back(new Node("Class Extends", $4->value));
                            $$->children.push_back($6);
                        }
                    |   CLASS Identifier LMP RMP {
                            $$ = new Node("Class", $2->value);
                        }
                    |   CLASS Identifier EXTENDS Identifier LMP RMP {
                            $$ = new Node("Class", $2->value);
                            $$->children.push_back(new Node("Class Extends", $4->value));
                        }
                    ;

ClassBody           :   VarList {
                            $$ = new Node("Class Body", "");
                            $$->children.push_back($1);    
                        }
                    |   MethodList  {
                            $$ = new Node("Class Body", "");
                            $$->children.push_back($1);  
                        }
                    |   VarList MethodList {
                            $$ = new Node("Class Body", "");
                            $$->children.push_back($1);  
                            $$->children.push_back($2); 
                        }
                    ;

VarList             :   VarList VarDeclaration {
                            $1->children.push_back($2);
                            $$=$1;
                        }
                    |   VarDeclaration {
                            $$ = new Node("Variable List", "");
                            $$->children.push_back($1);
                        }
                    ;

VarDeclaration      : Type Identifier SEMICOLON {
                            $$ = new Node("Variable", "");
                            $$->children.push_back($2);
                            $$->children.push_back($1);
                        }
                    ;

MethodList          :   MethodList MethodDeclaration {
                            $1->children.push_back($2);
                            $$=$1;
                        }
                    |   MethodDeclaration{
                            $$ = new Node("Method List", "");
                            $$->children.push_back($1);
                        }
                    ;

MethodDeclaration   :   PUBLIC VOID Identifier LP MethodParameterList RP LMP MethodBodyDeclaration RMP {
                            $$ = new Node("Method", $3->value);
                            $$->children.push_back(new Node("Type", "Void"));
                            $$->children.push_back($5);
                            $$->children.push_back($8);
                            $$->children.push_back(new Node("Returns", "Void"));
                        }
                    |   PUBLIC Type Identifier LP MethodParameterList RP LMP MethodBodyDeclaration RETURN Expression SEMICOLON RMP {
                            $$ = new Node("Method", $3->value);
                            $$->children.push_back(new Node("Type", $2->type));
                            $$->children.push_back($5);
                            $$->children.push_back($8);

                            Node* return_node = new Node("Returns", $10->type);
                            return_node->children.push_back($10);
                            $$->children.push_back(return_node);
                        }
                    ;

MethodBodyDeclaration       :   VarList StatementList {
                                    $$ = new Node("Method Body", "");
                                    $$->children.push_back($1);
                                    $$->children.push_back($2);
                                }
                            |   StatementList {
                                    $$ = new Node("Method Body", "");
                                    $$->children.push_back($1);
                                }
                            |   VarList {
                                    $$ = new Node("Method Body", "");
                                    $$->children.push_back($1);
                                }
                            |   %empty {
                                    $$ = new Node("Method Body", "Empty");
                                }
                            ;

MethodParameterList :  MethodParameterList COMMA MethodParameterDecl{
                            $1->children.push_back($3);
                            $$=$1;
                        }
                    |   MethodParameterDecl {
                            $$ = new Node("Parameter List", "");
                            $$->children.push_back($1);
                        }
                    |   %empty {
                            $$ = new Node("Arguments", "None");
                        }
                    ;

MethodParameterDecl :   Type Identifier{
                            $$ = new Node("Parameter", "");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                        }
                    ;

Type                :   T_Int {
                                $$ = new Node("Int", "");
                            }
                    |   T_Int LHKP RHKP {
                                $$ = new Node("Int[]", "");
                            }
                    |   T_Bool {
                                $$ = new Node("Bool", "");
                            }
                    |   Identifier {
                            $$ = $1;
                        }
                    ;

StatementList       :   StatementList Statement {
                            $1->children.push_back($2);
                            $$=$1;
                        }
                    |   Statement  {
                            $$ = new Node("Statement List", "");
                            $$->children.push_back($1);
                        }
                    ;

Statement           :   LMP StatementList RMP {
                            $$ = $2;
                        }
                    |   LMP RMP {
                            $$ = new Node("Empty", "");                        
                        }
                    |   IF LP Expression RP Statement ELSE Statement {
                                $$ = new Node("IF", "");
                                $$->children.push_back($3);
                                $$->children.push_back($5);
                                $$->children.push_back($7);
                            }
                    |   WHILE LP Expression RP Statement {
                                $$ = new Node("WHILE", "");
                                $$->children.push_back($3);
                                $$->children.push_back($5);
                            }
                    |   SYS_PRINTLN LP Expression RP SEMICOLON {
                                $$ = new Node("SYS_PRINTLN", "");
                                $$->children.push_back($3);
                            }
                    |   Identifier ASSIGN_OP Expression SEMICOLON { 
                                $$ = new Node("Assign", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    |   Identifier LHKP Expression RHKP ASSIGN_OP Expression SEMICOLON {
                                $$ = new Node("Assign[]", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                $$->children.push_back($6);
                            }
                    |   Expression SEMICOLON {
                            $$ = $1;
                        }
                    ;

Expression          : Expression AND Expression {
                                $$ = new Node("AND", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    | Expression OR Expression {
                                $$ = new Node("OR", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    | Expression LT Expression {
                                $$ = new Node("LT", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    | Expression GT Expression {
                                $$ = new Node("GT", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    | Expression EQ Expression {
                                $$ = new Node("EQ", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    | Expression PLUSOP Expression {
                                $$ = new Node("PLUS", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    | Expression MINOP Expression {
                                $$ = new Node("MINUS", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    | Expression MULOP Expression {
                                $$ = new Node("MULT", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    | Expression DIVOP Expression {
                                $$ = new Node("DIV", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    | Expression LHKP Expression RHKP {
                                $$ = new Node("Indexing", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                            }
                    | Expression DOT LENGTH {
                                $$ = new Node("Length Of", "");
                                $$->children.push_back($1);
                            }
                    | Expression DOT Identifier LP FunctionArgumentList RP{
                                $$ = new Node("Function Call", "");
                                $$->children.push_back($1);
                                $$->children.push_back($3);
                                $$->children.push_back($5);
                            }
                    | NEW T_Int LHKP Expression RHKP{
                                $$ = new Node("new[]", $2);
                                $$->children.push_back($4);
                            }
                    | NEW Identifier LP RP{
                                $$ = new Node("new()", "");
                                $$->children.push_back($2);
                            }
                    | NOT Expression {
                                $$ = new Node("NOT", "");
                                $$->children.push_back($2);
                            }
                    | LP Expression RP{
                                $$ = new Node("Statement", "");
                                $$->children.push_back($2);
                            }
                    | Identifier {
                                $$ = new Node("Identifier", $1->value);
                            }
                    | INTEGER_LITERAL{
                                $$ = new Node("Int", $1);
                            }
                    | T_True{
                                $$ = new Node("Bool", $1);
                            }
                    | T_False {
                                $$ = new Node("Bool", $1);
                            }
                    | THIS {
                                $$ = new Node("THIS", "");
                            }
                    ;

FunctionArgumentList : FunctionArgumentList COMMA Expression {
                                $1->children.push_back($3);
                                $$=$1;
                            }
                        | Expression{
                                $$ = new Node("Function Arguments", "");
                                $$->children.push_back($1);
                            }
                        |   %empty {
                                $$ = new Node("Function Arguments", "Empty");
                            }
                        ;
Identifier          :   IDENTIFIER {
                                $$ = new Node("Identifier", $1);
                            }
                    |   MAIN    {
                                $$ = new Node("Identifier", "Main");
                            }
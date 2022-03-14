compiler: lex.yy.c parser.tab.o main.cc
		g++ -g -w -o compiler parser.tab.o lex.yy.c main.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -g -w -c parser.tab.cc -std=c++14
parser.tab.cc: parser.yy
		bison -v parser.yy
lex.yy.c: lexer.l parser.tab.cc
		flex lexer.l
tree: 
		dot -Tpdf tree.dot -otree.pdf
		dot -Tpdf IR.dot -oIR.pdf
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh tree.dot tree.pdf
		rm -fR compiler.dSYM
		rm -fR *.dot
		rm -fR IR.pdf
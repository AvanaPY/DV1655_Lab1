compiler: lex.yy.c y.tab.o main.cc
		g++ -g -w -ocompiler y.tab.o lex.yy.c main.cc -std=c++14
y.tab.o: y.tab.c
		g++ -g -w -c y.tab.c -std=c++14
y.tab.c: parser.yy
		bison -vdty parser.yy
lex.yy.c: lexer.l y.tab.c
		flex lexer.l
tree: 
		 dot -Tpdf tree.dot -otree.pdf
clean:
		rm -f y.tab.* lex.yy.c* compiler stack.hh tree.dot tree.pdf *.output
		rm -fR compiler.dSYM
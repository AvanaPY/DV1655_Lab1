make -s clean && make -s

mkdir pdfs

./compiler < examples/factorial.java && dot -Tpdf tree.dot -o pdfs/factorial.pdf
./compiler < examples/linked.java && dot -Tpdf tree.dot -o pdfs/linked.pdf

./compiler < examples/multi_class.java && dot -Tpdf tree.dot -o pdfs/multi_class.pdf
./compiler < examples/multi_method.java && dot -Tpdf tree.dot -o pdfs/multi_method.pdf
./compiler < examples/nested_while.java && dot -Tpdf tree.dot -o pdfs/nested_while.pdf

./compiler < examples/works.java && dot -Tpdf tree.dot -o pdfs/works.pdf

./compiler < examples/empty_main.java
./compiler < examples/empty_method.java

./compiler < examples/lexical.java
./compiler < examples/notworks.java 
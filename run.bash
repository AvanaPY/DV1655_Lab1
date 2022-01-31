make -s clean && make -s

mkdir pdfs

./compiler < examples/factorial.java && dot -Tpdf tree.dot -o pdfs/factorial.pdf
./compiler < examples/linked.java && dot -Tpdf tree.dot -o pdfs/linked.pdf

./compiler < examples/multi_class.java && dot -Tpdf tree.dot -o pdfs/multi_class.pdf
./compiler < examples/multi_method.java && dot -Tpdf tree.dot -o pdfs/multi_method.pdf
./compiler < examples/nested_while.java && dot -Tpdf tree.dot -o pdfs/nested_while.pdf

./compiler < examples/works.java && dot -Tpdf tree.dot -o pdfs/works.pdf

echo "Empty Main Class test:"
./compiler < examples/empty_main.java

echo "Empty Main Method test :"
./compiler < examples/empty_method.java

echo "Lexical Error test:"
./compiler < examples/lexical.java

echo "Invalid syntax test:"
./compiler < examples/notworks.java 
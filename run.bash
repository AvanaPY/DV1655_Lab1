make -s clean && make -s

mkdir pdfs

./compiler < examples/works.java && dot -Tpdf tree.dot -o pdfs/works.pdf
./compiler < examples/factorial.java && dot -Tpdf tree.dot -o pdfs/factorial.pdf
./compiler < examples/linked.java && dot -Tpdf tree.dot -o pdfs/linked.pdf

./compiler < examples/lexical.java
./compiler < examples/notworks.java 
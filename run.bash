make -s clean && make -s

mkdir -p pdfs

run_test() {
    printf "\nRunning $1\n"
    ./compiler < $1 
}

run_test "examples/factorial.java"
run_test "examples/linked.java"

run_test "examples/multi_class.java"
run_test "examples/multi_method.java"
run_test "examples/nested_while.java"

run_test "examples/works.java"

run_test "examples/empty_main.java"
run_test "examples/empty_method.java"
run_test "examples/lexical.java"
run_test "examples/notworks.java "
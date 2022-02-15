

make -s clean && make -s

mkdir -p pdfs

BLACK=$(tput setaf 0)
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
YELLOW=$(tput setaf 3)
LIME_YELLOW=$(tput setaf 190)
POWDER_BLUE=$(tput setaf 153)
BLUE=$(tput setaf 4)
MAGENTA=$(tput setaf 5)
CYAN=$(tput setaf 6)
WHITE=$(tput setaf 7)
BRIGHT=$(tput bold)
BLINK=$(tput blink)
REVERSE=$(tput smso)
UNDERLINE=$(tput smul)
normal=$(tput sgr0)

printf "\n%10s" "${WHITE}Running valid test files"
for filename in ./semantics_tests/valid/*
do
    printf "\n%10s" "${MAGENTA}Running "
    printf "%40s\n" "${CYAN}$filename${GREEN}"
    ./compiler < $filename    
done

printf "\n%10s" "${WHITE}Running invalid test files"
for filename in ./semantics_tests/invalid/*
do
    printf "\n%10s" "${MAGENTA}Running "
    printf "%40s\n" "${CYAN}$filename${RED}"
    ./compiler < $filename    
done

printf "\n%10s" "${WHITE}Running Cambrige Files"
for filename in ./semantics_tests/java/*
do
    printf "\n%10s" "${MAGENTA}Running "
    printf "%40s\n" "${CYAN}$filename${POWDER_BLUE}"
    ./compiler < $filename    
done
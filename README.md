name-search
===========

Simple name occurrence search within text file.

Usage:
------

    > make
    gcc -Wall -c -g -pg name-search.c
    Building target: name-search
    gcc  -o name-search name-search.o -lm -Wall -Wextra -g -pg
    Finished building target: name-search

    > ./name-search users.txt Norah
    354 bytes read
    50 occurences in file
    5 occurences found

    > make clean
    Cleaning targets: name-search.o name-search gmon.out name-search.tar
    rm -rf name-search.o name-search gmon.out name-search.tar
    Finished cleaning targets

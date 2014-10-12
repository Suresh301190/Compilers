#!/bin/bash

lex example.l
yacc -d example.y
gcc y.tab.c -ll -ly
./a.out < input.c > output.txt

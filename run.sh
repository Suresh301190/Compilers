#!/bin/bash

reset
yacc -d sample.y
flex sample.lex
yacc -v sample.y
gcc y.tab.c -ll -ly
./a.out < input2.c

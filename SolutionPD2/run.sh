#!/bin/bash

reset
yacc -d gram.y
flex gram.l
yacc -v gram.y
gcc y.tab.c -ll -ly
./a.out < input.c

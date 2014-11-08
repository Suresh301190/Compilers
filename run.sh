#!/bin/bash

reset
yacc -d sample.y
flex sample.l
yacc -v sample.y
gcc y.tab.c -ll -ly
./a.out < input.c

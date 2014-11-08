#!/bin/bash

reset
yacc -d example.y
flex example.l
yacc -v example.y
gcc y.tab.c -ll -ly
./a.out < input.c

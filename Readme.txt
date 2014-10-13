/*
 * Project Deliverable 2: Compilers
 * @author
 * Suresh Rangaswamy
 * MT13017
 * 13 October 2014
 *
 *
 * Usage: (1.a) $ yacc -d sample.y
 *        (1.b) $ flex sample.lex
 *        (1.c) $ yacc -v sample.y
 *        (1.d) $ gcc y.tab.c -ll -ly
 *        (1.e) $ ./a.out
 *            stdin> whatever you like
 *	      stdin> Ctrl-D
 *        (2) $ ./a.out < input_file
 *        (3) $ ./run.sh it will run all 5 commands as stated above
 *  and input will be input.c file
 *
 * Sample input.c is included with the package.
 *
 *  Modifications to the grammer
 *  1. Done a great deal of modifications to remove all the conflicts in the grammer.
 *  2. Broken down the grammer into partial nonterminals symbols to remove conflicts.
 *  3. Implemented the precedence of operators in expressions.
 *  4. Made a few changes like using semicolon in for loop and some basic C syntax like structure.
 *  5.
 *
 * For part 2 regex to DFA then verify run the command
 * java -jar Regex-Verify.jar "a.a*|b.b*" "aaaa"
 *
 * Note: regex needs to be properly escaped. Provide it in quotes "your_regex"
 * I have done soft checking for validation of a regex.
 *
 * Compilers contains the eclipse project which contains the source code.
 */

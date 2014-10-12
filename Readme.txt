/*
 * Project Deliverable 1: Compilers
 * @author
 * Suresh Rangaswamy
 * MT13017
 * 15 September 2014
 *
 * Added some of my own operators as well like unary_op to match (++|--),
 * const keyword, and C Pointers as well, like const char *c.
 *
 * Usage: (1.a) $ flex sample.lex
 *        (1.b) $ gcc lex.yy.c -lfl
 *        (1.c) $ ./a.out
 *            stdin> whatever you like
 *	      stdin> Ctrl-D
 *        (2) $ ./a.out < input_file
 *        (3) $ ./run.sh it will run all three commands as stated above
 *  and input will be input.c file
 *
 * Sample input.c is included with the package.
 *
 * For part 2 regex to NFA run the command
 * java -jar regextonfa.jar "a.a*|b.b*"
 *
 * Note: regex needs to be properly escaped. Provide it in quotes "your_regex"
 * I have done soft checking for validation of a regex.
 *
 * Compilers contains the eclipse project which contains the source code.
 */
 

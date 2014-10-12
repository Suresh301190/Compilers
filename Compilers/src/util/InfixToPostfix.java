package util;

import java.util.HashMap;
import java.util.Stack;

public class InfixToPostfix {

	final static HashMap<Character, Integer> SPECIAL = new HashMap<Character, Integer>();

	static{
		SPECIAL.put('(', 1);
		SPECIAL.put('|', 2);
		SPECIAL.put('.', 3);
		SPECIAL.put('?', 5);
		SPECIAL.put('*', 5);
		SPECIAL.put('+', 5);
	}

	final private String regex;
	private String postfix;

	public InfixToPostfix(String s){
		regex = s;
	}

	public String getPostFixExpr(){
		return postfix != null? postfix: convert();
	}

	private String convert(){
		StringBuilder sb = new StringBuilder();
		Stack<Character> stack = new Stack<Character>();

		for(int i = 0; i < regex.length(); i++){
			char c = regex.charAt(i);
			switch(c){
			case '(':
				stack.push(c);
				break;
			case ')':
				while(!stack.peek().equals('(')){
					sb.append(stack.pop());
				}
				stack.pop();
				break;
			default:
				if(SPECIAL.containsKey(c)){
					if(!stack.isEmpty()){
						if(SPECIAL.get(c) >= SPECIAL.get(stack.peek())){
							stack.push(c);
						}
						else{
							while(!stack.isEmpty() && SPECIAL.get(c) < SPECIAL.get(stack.peek())){
								sb.append(stack.pop());
							}
							stack.push(c);
						}						
					}
					else 
						stack.push(c);
				}
				else sb.append(c);
				break;
			}
		}
		
		while(!stack.isEmpty()){
			if(stack.peek() == '(') 
				throw new IllegalArgumentException("Not a Valid Regular Exception");
			sb.append(stack.pop());
		}

		return postfix = sb.toString();
	}
}

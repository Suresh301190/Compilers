package util;

import java.util.LinkedList;
import java.util.Stack;

public class NFA {
	
	private static int state = 0; 
	public static final String epsilon = "_e_";
	Node start, end;
	private String expr;
	static final StringBuffer sb = new StringBuffer();
	
	public String getExpr(){
		return expr;
	}
	
	public static NFA createNFA(String posix, boolean DEBUG){
		Stack<NFA> stack = new Stack<NFA>();
		
		for(int i = 0; i < posix.length(); i++){
			char c = posix.charAt(i);
			switch(c){
			case '|':
				if(!isOK(stack, 2)) {
					return null;
				}
				stack.push(merge_OR(stack.pop(), stack.pop()));
				break;
			case '.':
				if(!isOK(stack, 2)) {
					return null;
				}
				stack.push(merge_AND(stack.pop(), stack.pop()));
				break;
			case '+':
				if(!isOK(stack, 1)) {
					return null;
				}
				stack.push(make_star_plus(stack.pop(), false));
				break;
			case '*':
				if(!isOK(stack, 1)) {
					return null;
				}
				stack.push(make_star_plus(stack.pop(), true));
				break;
			case '[':
				int s = i;
				while(posix.charAt(++i) != ']');
				if(!isOK(stack, 1)) {
					return null;
				}
				stack.push(getNFA_X(posix.substring(s, i + 1)));
				break;
			default:
				stack.push(getNFA_X(c + ""));
			}
			if(DEBUG)
				sb.append("\nBuilding NFA for " + stack.peek().expr);
		}
		
		if(stack.size() != 1){
			System.out.println("Not a valid Expression");
			return null; 
		}
		
		System.out.println(sb.toString());
		sb.setLength(0);
		
		return stack.pop();
	}
	
	private static boolean isOK(Stack<NFA> stack, int i) {
		// TODO Auto-generated method stub
		if(stack.size() < i) {
			System.out.println("Not a valid Expression");
			return false;
		}
		return true;
	}

	private NFA(){}
	
	public static NFA getNFA_X(String consume){
		NFA nfa = new NFA();
		nfa.expr = consume;
		nfa.start = new Node(getNextState());
		nfa.end = new Node(getNextState());
		nfa.start.addEdge(nfa.end, consume);
		nfa.end.setFinal();
		
		return nfa;
	}
	
	public static NFA merge_AND(NFA nfa2, NFA nfa1){
		nfa1.expr = "(" + nfa1.expr + "." + nfa2.expr + ")";
		nfa1.end.unSetFinal();
		nfa1.end.mergeNode(nfa2.start);
		nfa1.end = nfa2.end;
		return nfa1;
	}
	
	public static NFA merge_OR(NFA nfa1, NFA nfa2){
		nfa1.expr = "(" + nfa2.expr + "|" + nfa1.expr + ")";
		Node s, e;
		s = new Node(getNextState());
		e = new Node(getNextState());
		e.setFinal();
		
		s.addEdge(nfa1.start, epsilon);
		s.addEdge(nfa2.start, epsilon);
		
		nfa1.end.unSetFinal();
		nfa2.end.unSetFinal();
		
		nfa1.end.addEdge(e, epsilon);
		nfa2.end.addEdge(e, epsilon);
		
		nfa1.start = s;
		nfa1.end = e;
		
		return nfa1;
	}
	
	public static NFA make_star_plus(NFA nfa, boolean isStar){
		if(isStar)
			nfa.expr = "(" + nfa.expr + ")*";
		else
			nfa.expr = "(" + nfa.expr + ")+";
		Node s, e;
		s = new Node(getNextState());
		e = new Node(getNextState());
		
		e.setFinal();		
		
		if(isStar) 
			s.addEdge(e, epsilon);
		
		nfa.end.addEdge(nfa.start, epsilon);
		nfa.end.unSetFinal();
		
		s.addEdge(nfa.start, epsilon);
		nfa.end.addEdge(e, epsilon);		
		
		nfa.start = s;
		nfa.end = e;
		
		return nfa;
	}
	
	private static int getNextState(){
		return state++;
	}

	static class Node{
		final int id;
		boolean isFinal = false;
		LinkedList<Edge> edges;
		
		public Node(int id){
			this.id = id;
			edges = new LinkedList<Edge>();
		}
		
		public void addEdge(Node dst, String consume){
			Edge edge = new Edge(dst, consume);
			edges.add(edge);
		}
		
		public void setFinal(){
			isFinal = true;
		}
		
		public void unSetFinal(){
			isFinal = false;
		}
		
		public void mergeNode(Node node){
			edges.addAll(node.edges);
		}
		
		@Override
		public String toString(){
			return id + "=" + edges.toString() + (isFinal?"-F":"");
		}
	}
	
	static class Edge{
		final Node dst;
		final String consume;
		
		public Edge(Node dst, String consume) {
			this.dst = dst;
			this.consume = consume;
		}
		
		boolean isEpsilon(){
			return consume.equals(epsilon);
		}
		
		public String toString(){
			return consume + "->" + dst.id;
		}

		public boolean isConsumable(String con) {
			// TODO Auto-generated method stub
			return consume.equals(con);
		}
	}
}

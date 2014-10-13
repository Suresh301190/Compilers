package util;

import java.io.PrintStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.TreeMap;

import util.NFA.Edge;
import util.NFA.Node;

public class DFA {

	private static final PrintStream ps = System.out;

	private HashMap<Integer, Node> id_node;
	private TreeMap<State, State[]> graph = new TreeMap<State, State[]>();
	private TreeMap<State, State> s_s = new TreeMap<State, State>();
	private final NFA nfa;
	private int nextState;
	private HashMap<String, Integer> consumable;
	private final State start, error, tmp;
	
	public boolean isValid(String s){
		if(s == null)
			return false;
		ps.println("Parsing the input = { " + s + " }");
		
		String[] tokens = s.split("");
		State st = start;
		for(int i = 1; i < tokens.length; i++){
			if(!consumable.containsKey(tokens[i]) || st.id == error.id)
				return false;			
			st = graph.get(st)[consumable.get(tokens[i])];			
		}
		return st.isFinal;
	}

	private DFA(NFA nfa){
		id_node = new HashMap<Integer, Node>();
		this.nfa = nfa;
		nextState = 0;
		consumable = new HashMap<String, Integer>();
		setPairs();
		start = new State(getNextState());
		start.setStates(getStartState());
		error = new State(-1);
		tmp = new State(Integer.MIN_VALUE);
		error.states = new Node[0];
	}

	private int getNextState(){
		return nextState++;
	}

	public static DFA NFA_to_DFA(NFA nfa, boolean DEBUG){
		if(DEBUG)
			ps.println("Building DFA for" + nfa.getExpr());
		DFA dfa = new DFA(nfa);
		//ps.println(dfa.consumable);
		//ps.println(dfa.id_node);
		return dfa.makeGraph();		
	}

	private DFA makeGraph() {
		// TODO Auto-generated method stub
		LinkedList<State> queue = new LinkedList<State>();
		queue.add(start);
		s_s.put(start, start);
		s_s.put(error, error);
		while(!queue.isEmpty()){
			State src = queue.poll();
			graph.put(src, new State[consumable.size()]);
			for(Iterator<String> it = consumable.keySet().iterator(); it.hasNext(); ){
				String con = it.next();
				setState(queue, con, consumable.get(con), src);
			}
		}
		//printGraph();

		return this;
	}

	private void setState(LinkedList<State> queue, String con, int index, State src) {
		// TODO Auto-generated method stub
		State[] states = graph.get(src);
		HashSet<Node> nextState = new HashSet<Node>(), eClosure = new HashSet<Node>();
		for(Node source : src.states){
			for(Iterator<Edge> it = source.edges.iterator(); it.hasNext(); ){
				Edge e = it.next();
				if(e.isConsumable(con)){
					nextState.add(e.dst);
				}
			}
		}
		eClosure.addAll(nextState);
		for(Iterator<Node> it = nextState.iterator(); it.hasNext(); ){
			e_closure(it.next(), eClosure, false);
		}
		
		tmp.setStates(eClosure.toArray(new Node[eClosure.size()]));

		if(!s_s.containsKey(tmp)){
			State sNew = new State(getNextState());
			sNew.setStates(tmp.states);
			s_s.put(sNew, sNew);
			states[index] = sNew;
			queue.add(sNew);
		}
		else states[index] = s_s.get(tmp);
	}

	private void printGraph(){
		for(Entry<State, State[]> en : graph.entrySet()){
			ps.println(en.getKey().id + "->" + Arrays.toString(en.getValue()));
		}
	}

	private void setPairs(){
		e_closure(nfa.start, new HashSet<Node>(), true);
	}

	private Node[] getStartState(){
		HashSet<Node> s = e_closure(nfa.start, new HashSet<Node>(), false);
		Node[] n = s.toArray(new Node[s.size()]);
		return n;
	}

	private HashSet<Node> e_closure(Node node, HashSet<Node> visited, boolean setPairs){
		LinkedList<Node> queue = new LinkedList<Node>();
		queue.add(node);
		int i = 0;
		while(!queue.isEmpty()){
			Node src = queue.poll();
			if(setPairs) 
				id_node.put(src.id, src);
			for(Iterator<Edge> it = src.edges.iterator(); it.hasNext(); ){
				Edge edge = it.next();
				if(setPairs && !edge.isEpsilon() && !consumable.containsKey(edge.consume)){
					consumable.put(edge.consume, i++);
				}
				if(setPairs || edge.isEpsilon()){
					if(!visited.contains(edge.dst)){
						visited.add(edge.dst);
						queue.add(edge.dst);
					}
				}
			}
		}

		return visited;		
	}	

	static class State implements Comparable<State>{
		Node[] states;
		final int id;
		boolean isFinal = false;

		public State(int id){
			this.id = id;
		}

		public void setStates(Node[] state) {
			// TODO Auto-generated method stub
			this.states = state;
			for(int i = 0; i < state.length; i++){
				if(state[i].isFinal) 
					isFinal = true;
			}
			sort();
		}

		@Override
		public int compareTo(State o) {
			// TODO Auto-generated method stub
			if(states.length < o.states.length) return -1;
			else if(states.length > o.states.length) return 1;
			for(int i = 0; i < states.length; i++){
				if(states[i].id < o.states[i].id) return -1;
				else if(states[i].id > o.states[i].id) return 1;
			}
			return 0;
		}

		private static final Comparator<Node> c = new Comparator<Node>() {

			@Override
			public int compare(Node o1, Node o2) {
				// TODO Auto-generated method stub
				return o1.id - o2.id;
			}
		};

		void sort(){
			Arrays.sort(states, c);
		}

		public String toString(){
			return id + "->" + Arrays.toString(states) + (isFinal?"-F":"");
		}
	}
}

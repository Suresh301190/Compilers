package util;

public class ParserArithmatic {

	static String current_token;
	static final String PLUS = "+", MINUS = "-", ID = "id", DIV = "/", TIMES = "*", NUM = "";
	final String[] tokens;
	int cPos;
	boolean error = false;
	
	public static void main(String[] args){
		ParserArithmatic pa = new ParserArithmatic("");
		if(pa.verify()) System.out.println("OK");
		else System.out.println("ERROR");
	}

	public ParserArithmatic(final String input) {
		// TODO Auto-generated constructor stub
		this.tokens = new String[]{"id", "*", "id", "*", "id", "$"};
		cPos = 0;
		read_next_token();
	}
	
	public boolean verify(){
		error = false;
		E();
		return current_token == "$" && !error;
	}

	void E () {
		if(error) return;
		System.out.println("E ->T E'");
		T(); 
		Eprime(); 
	}

	void Eprime () {
		if(error) return;
		if (current_token == PLUS) { 
			System.out.println("E' -> + T E'");
			read_next_token(); 
			T(); 
			Eprime(); 
		}
		else if (current_token == MINUS){
			System.out.println("E' -> -T E'");
			read_next_token(); 
			T(); 
			Eprime();
		};
	}
	void T () { 
		if(error) return;
		System.out.println("T -> F T'");
		F();
		Tprime(); 
	}
	void Tprime() {
		if(error) return;
		if (current_token == TIMES){
			System.out.println("T' -> * F T'");
			read_next_token(); 
			F(); 
			Tprime(); 
		}
		else if (current_token == DIV) {
			System.out.println("T -> / F T'");
			read_next_token(); 
			F(); 
			Tprime(); 
		};
	}
	void F () {
		if(error) return;
		if (current_token == NUM || current_token == ID){
			System.out.println("F -> id");
			read_next_token();
		}
		else error();
	}
	private void error() {
		// TODO Auto-generated method stub
		error = true;
	}
	private void read_next_token() {
		// TODO Auto-generated method stub
		if(cPos >= tokens.length) return;
		current_token = tokens[cPos++];
	}
}

/**
 * @author Suresh Rangaswamy MT13017
 */

package testApp;

import util.InfixToPostfix;
import util.NFA;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		new Test().work(args);
	}

	private void work(String[] args) {
		// TODO Auto-generated method stub

		if(args.length != 1){
			System.out.println("Please provide args[0]=\"regex\"");
			return;
		}

		try{
			InfixToPostfix ipos = new InfixToPostfix(args[0]);
			@SuppressWarnings("unused")
			NFA nfa = NFA.createNFA(ipos.getPostFixExpr(), true);
		}catch(Exception e){
			System.out.println("Regular Expression is Invalid or not properly excaped try enclosing it in \"regex\" ");
		}
	}

}

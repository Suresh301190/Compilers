/**
 * @author Suresh Rangaswamy MT13017
 */

package testApp;

import util.DFA;
import util.InfixToPostfix;
import util.NFA;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		new Test().work(args);
	}

	private void work(String[] args) {
		// TODO Auto-generated method stub

		if(args.length != 2){
			System.out.println("Please provide args[0]=\"regex\" and args[1]=\"StringToVerify\"");
			return;
		}

		try{
			//InfixToPostfix ipos = new InfixToPostfix(args[0]);
			InfixToPostfix ipos = new InfixToPostfix(args[0]);
			NFA nfa = NFA.createNFA(ipos.getPostFixExpr(), false);
			DFA dfa = DFA.NFA_to_DFA(nfa, true);
			System.out.print(dfa.isValid(args[1])?"accepted":"rejected");
		}catch(Exception e){
			e.printStackTrace();
			System.out.println("Regular Expression is Invalid or not properly excaped try enclosing it in \"regex\" ");
		}
	}

}

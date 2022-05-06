import java.util.Scanner;
public class Bank {
	public static final double OVERDRAWN_PENALTY = 8.00;
	public static final double INTEREST_RATE = 0.02;

	public static void main(String[] args) {
		double balance;
		
		System.out.print("Enter your checking account balance: $");
		Scanner keyboard = new Scanner(System.in);
		balance = keyboard.nextDouble();
		System.out.println("Original balance $"+balance);
		
		if(balance>=0)
			balance = balance + (INTEREST_RATE*balance)/12;
		else
			balance = balance - OVERDRAWN_PENALTY;
		
		System.out.println(balance);
	}

}

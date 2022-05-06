import java.util.Scanner;

public class FirstProject {
	public static void main(String[] args) {
		System.out.println("Hello out there.");
		System.out.println("I will add two number for you.");
		System.out.println("Enter two whole numbers on a line:");
		
		int n1,n2;
		
		Scanner keyboard = new Scanner(System.in);
		n1 = keyboard.nextInt();
		n2 = keyboard.nextInt();
		
		System.out.println("The sum of those two numbers is");
		System.out.println(n1+n2);
		
		keyboard.close();
	}

}

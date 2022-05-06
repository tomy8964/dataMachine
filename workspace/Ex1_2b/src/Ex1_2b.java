import java.util.Scanner;

public class Ex1_2b {
	public static void main(String[] args) {
		System.out.println("Input two integer");
		int n1,n2;
		
		Scanner keyboard = new Scanner(System.in);
		n1 = keyboard.nextInt();
		n2 = keyboard.nextInt();
		
		System.out.println("The number of integers between them, including themselves");
		System.out.println(n2-n1+1);

		keyboard.close();
	}
}

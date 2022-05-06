import java.util.Scanner;

public class Ex1_2a {
	public static void main(String[] args) {
		System.out.println("Birth year?");
		
		int by;
		
		Scanner keyboard = new Scanner(System.in);
		by = keyboard.nextInt();
		
		System.out.println("Your age is = "+(2021-by));

		keyboard.close();
	}
}

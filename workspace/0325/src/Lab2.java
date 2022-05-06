import java.util.Scanner;
public class Lab2 {

	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		
		System.out.println("Enter two whole numbers");
		System.out.println("separated by one or more spaces:");
		
		int n1 = keyboard.nextInt();
		int n2 = keyboard.nextInt();

		System.out.println(n1+" and " + n2);
		
		System.out.println("Enter two whole numbers");
		System.out.println("separated by one or more spaces:");
		
		double d1 = keyboard.nextDouble();
		double d2 = keyboard.nextDouble();

		System.out.println(d1+" and " + d2);
		
		System.out.println("Enter two whole numbers");
		System.out.println("separated by one or more spaces:");
		
		String s1 = keyboard.next();
		String s2 = keyboard.next();

		System.out.println(s1+" and " + s2);
		s1 = keyboard.nextLine();
		
		System.out.println("Enter two whole numbers");
		System.out.println("separated by one or more spaces:");
		
		s1 = keyboard.nextLine();
		
		System.out.println(s1);
		keyboard.close();
	}

}

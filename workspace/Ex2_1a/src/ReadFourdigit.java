import java.util.Scanner;

public class ReadFourdigit {

	public static void main(String[] args) {
		int num;
		double Fa,C;
		
		Scanner keyboard = new Scanner(System.in);
		System.out.println("four digit int");
		num = keyboard.nextInt();
		System.out.println(num/1000);
		System.out.println((num%1000)/100);
		System.out.println(((num%1000)%100)/10);
		System.out.println(((num%1000)%100)%10);
		
		System.out.println("Fahrenheit");
		Fa = keyboard.nextDouble();
		
		C = (5.0 * (Fa - 32.0)) / 9.0;
		System.out.println(C);
		
		keyboard.close();

	}

}

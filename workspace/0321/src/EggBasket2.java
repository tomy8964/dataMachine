import java.util.Scanner;

public class EggBasket2 {

	public static void main(String[] args) {
		int numOfBaskets, eggsPerBasket, totalEggs;
		
		int hoursWorked = 40;
		double payRate = 8.25;
		System.out.println(hoursWorked*payRate);
		
		double resultSum = 1/2 + 1/2;
		
		System.out.println(resultSum);
		
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter the number of eggs in each basket:");
		eggsPerBasket = keyboard.nextInt();
		System.out.println("Enter the number of baskets:");
		numOfBaskets = keyboard.nextInt();
		
		totalEggs = eggsPerBasket * numOfBaskets;
		
		System.out.println("If you have");
		System.out.println(eggsPerBasket+" eggs per basket and");
		System.out.println(numOfBaskets+" baskets, then");
		System.out.println("the total number of eggs is "+totalEggs);
		
		System.out.println("Now we take two eggs out of each basket.");
		eggsPerBasket=eggsPerBasket-2;
		totalEggs = eggsPerBasket * numOfBaskets;
		
		System.out.println("You now have");
		System.out.println(eggsPerBasket+" eggs per basket and");
		System.out.println(numOfBaskets+" baskets.");
		System.out.println("The new total number of eggs is "+totalEggs);
		
	}

}

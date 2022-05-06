import java.util.Scanner;
/*
 * Program to compute area of a circle.
 * Author: Jane Q. Programmer.
 * E-mail Address: Janeq@someachine.etc.etc.
 * Programming Assignment 2.
 * Last Changed: October 7, 2008.
 */
public class Circle {
	public static final double PI = 3.14159;
	public static void main(String[] args) {
		double radius,area;
		Scanner keyboard = new Scanner(System.in);

		System.out.println("Enter the radius of a circle in inches:");

		radius = keyboard.nextDouble();
		area = radius * radius * PI;

		System.out.println(area);

		keyboard.close();
	}

}

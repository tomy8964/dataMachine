/**
 * Write a program to read a list of nonnegative integers and to display the largest 
 * integer, the smallest integer, and the average of all the integers.
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 5.
 * Last Change: April 15, 2022.
 */
import java.util.Scanner;
public class p5 {

	public static void main(String[] args) {
		int small=10000,larg=0,count=0,sum=0;
		double avg=0.0;
		// 스캐너 객체 keyboard 생성
		Scanner keyboard = new Scanner(System.in);
		System.out.println("This program allows you to enter a list of nonnegative integers and to display the largest \r\n"
				+ "integer, the smallest integer, and the average of all the integers.");
		
		// use loop to enter a number
		while(true)
		{
			System.out.println("Please enter a positive integer, or -1 to quit:");
			// input num
			int num = keyboard.nextInt();
			
			// -1 break
			if(num<=-1) break;
			// else plus count
			else count++;
			
			//calculate smallest
			if(num<small) {
				small=num;
			}// calculate largest
			else larg=num;
			
			//calculate average
			sum = sum + num;
	        avg = (sum / count);
		}
		//print
		System.out.println("For the "+count+" numbers you entered");
		System.out.println("the largest value = "+larg);
		System.out.println("the smallest value = "+small);
		System.out.println("and the average is = "+avg);
		keyboard.close();
	}
}











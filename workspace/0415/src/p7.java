/**
 * program that asks the user to enter the size of a triangle
 * display the triangle by writing lines fo asterisks.
* Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 7.
 * Last Change: April 15, 2022.
 */
import java.util.Scanner;
public class p7 {

	public static void main(String[] args) {
		// num �ʱ�ȭ
		int num=0;
		// ��ĳ�� ��ü keyboard ����
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter an integer from 1 to 50:");
		// num input
		num = keyboard.nextInt();
		for (int i = 0; i < num; i++) {
		    for (int f = 0; f <= i; f++) {
		    	//print *
		        System.out.print("*");
		    }
		    //next line
		    System.out.println();
		}
		for (int i = num-1; i > 0; i--) {
		    for (int f = 0; f < i; f++) {
		    	//print *
		        System.out.print("*");
		    }
		    //next line
		    System.out.println();
		}
		//close object
		keyboard.close();
	}
}










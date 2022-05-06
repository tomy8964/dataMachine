/**
 *Write a program to read a list of exam scores given 
 *as integer percentages in the range 0 to 100. 
 *Display the total number of grades and the number 
 *of grades in each letter-grade category
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 6.
 * Last Change: April 15, 2022.
 */
import java.util.Scanner;
public class p6 {

	public static void main(String[] args) {
		// 변수들 초기화
		int count=0,a=0,b=0,c=0,d=0,f=0;
		// 스캐너 객체 keyboard 생성
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter numerical grades\nin the range of 0 to 100 - integers, only, please!");
		
		//loop
		while(true)
		{
			// enter a score
			System.out.println("Please enter a score from 0 to 100 or -1 to quit:");
			int score = keyboard.nextInt();
			
			// -1 break
			if(score<=-1) break;
			// keep going plus count
			else count++;
			
			// divide range and plus count by category
			if(score>89) a++;
			else if(score>79) b++;
			else if(score>69) c++;
			else if(score>59) d++;
			else f++;
		}
		//print info
		System.out.println("Total number of grages = "+count);
		System.out.println("Number of A's = "+a);
		System.out.println("Number of B's = "+b);
		System.out.println("Number of C's = "+c);
		System.out.println("Number of D's = "+d);
		System.out.println("Number of F's = "+f);
		keyboard.close();
	}
}











/**
 * Write a program that reads a one-line sentence as input 
 * and then displays  If the sentence ends with a question mark 
 * (?) and the input contains an even 
 * number of characters, display the word Yes. 
 * If the sentence ends with a question mark 
 * and the input contains an odd number of characters, 
 * display the word No. If the 
 * sentence ends with an exclamation point (!), display the word Wow.
 In all other cases, display the words You always say followed by the input string enclosed in quotes.
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 2.
 * Last Change: April 15, 2022.
 */
import java.util.Scanner;
public class p2 {

	public static void main(String[] args) {
		// 스캐너 객체 keyboard 생성
		Scanner keyboard = new Scanner(System.in);
		// String 변수 선언
		String sLast;
		System.out.println("Please enter a one line question or statement.");
		// input string s
		String s = keyboard.nextLine();
		// input last character of s to sLast
		sLast = s.substring(s.length() - 1);
		//check if the sentence ends with ?
		if (sLast.equals("?"))
			{//and has even number of characters
				if(s.length()%2==0)
				{System.out.println("Yes");}
				else System.out.println("No");
			}
		//check if the sentence ends with !
		else if (sLast.equals("!"))
			{
				System.out.println("Wow");
			}
		else
			{// all other cases
				System.out.println("You always say \""+s+"\"");
			}
		keyboard.close();
	}
}











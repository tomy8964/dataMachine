/**
 * program that reads three strings from the keyboard. Although the strings 
 * are in no particular order, display the string that would be second if they were 
 * arranged lexicographically.
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 1.
 * Last Change: April 15, 2022.
 */
import java.util.Scanner;
public class p1 {

	public static void main(String[] args) {
		// ��ĳ�� ��ü keyboard ����
		Scanner keyboard = new Scanner(System.in);
		//middle string 
		String middle="";
		// three words input
		System.out.println("Please enter three words separated by spaces");
		// three words save
		String s1 = keyboard.next();
		String s2 = keyboard.next();
		String s3 = keyboard.next();
		
		//calculate lexicographically order
		// s1 is smaller than s2
		if((s1.compareTo(s2)<0))
		{
			//s1 compare with s3
			if((s1.compareTo(s3)<0)) {
				//s1, s2 s3
				if((s2.compareTo(s3)<0)) {
					middle = s2;
				}//s1, s3, s2
				else middle = s3;
			}//s1, s2, s3
			else middle = s2;
		}//s2 is smaller than s1
		else
		{	//s2 compare with s3
			//s3, s2, s1
			if((s2.compareTo(s3)<0))
			{
				middle = s2;
			}
			else {
				//s2, s1, s3
				if((s1.compareTo(s3)<0))
				{
					middle = s1;
				}// s2, s3, s1
				else middle =s3;
			}
		}
		// print middle words
		System.out.println("The middle word is "+middle);
		keyboard.close();
	}
}










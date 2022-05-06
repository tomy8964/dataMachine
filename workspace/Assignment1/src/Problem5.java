/**
 * Program input 4-bit binary number and
 * convert to decimal and output
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 5.
 * Last Change: March 30, 2022.
 */
import java.util.Scanner;
public class Problem5 {

	public static void main(String[] args) {
		// ½ºÄ³³Ê °´Ã¼ keyboard »ý¼º
		Scanner keyboard = new Scanner(System.in);
		// input 4-bit binary number
		System.out.println("Input 4-bit binary num");
		String binaryString = keyboard.nextLine();
		// break string into substrings
		String s1 = binaryString.substring(0,1);
		String s2 = binaryString.substring(1,2);
		String s3 = binaryString.substring(2,3);
		String s4 = binaryString.substring(3,4);
		
		//convert each substring and calculate each position
		int n1 = Integer.parseInt(s1)*8;
		int n2 = Integer.parseInt(s2)*4;
		int n3 = Integer.parseInt(s3)*2;
		int n4 = Integer.parseInt(s4);
		// calculate sum
		int decimal = n1+n2+n3+n4;
		//print decimal num
		System.out.println(decimal);
		// keyboard ´ÝÀ½
		keyboard.close();
	}

}

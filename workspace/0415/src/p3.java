/**
 * Write a program that allows the user to convert a temperature given in degrees from 
 * either Celsius to Fahrenheit or Fahrenheit to Celsius.
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 3.
 * Last Change: April 15, 2022.
 */
import java.util.Scanner;
public class p3 {

	public static void main(String[] args) {
		// 스캐너 객체 keyboard 생성
		Scanner keyboard = new Scanner(System.in);
		// 변수 선언
		Double input,convertInput;
		String type;
		
		System.out.println("Enter a temperature in degress (for example 29.6) :");
		// 온도 입력
		input = keyboard.nextDouble();
		// F인지 C인지 물어보는 구절 프린트
		System.out.println("Enter 'F' (or 'f')  for Fahrenheit or 'C' (or 'c') for Celsius");
		// 공백 한줄 제거
		type = keyboard.nextLine();
		// 타입에 대해 입력 받음
		type = keyboard.nextLine();
		
		// type is F
		if(type.equalsIgnoreCase("F"))
		{
			//use formula
			convertInput = 5 * (input - 32) / 9;
			System.out.println(input+" degrees "+type+" = "+convertInput+" degress Celsius.");
		}// type is C
		else if(type.equalsIgnoreCase("C"))
		{
			convertInput = 9 * (input / 5) + 32;
			System.out.println(input+" degrees "+type+" = "+convertInput+" degress Fahrenheit.");
		}// error occurs
		else System.out.println("error");
		
		keyboard.close();
	}
}











/**
 * Program to change word to another word
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 1.
 * Last Change: March 30, 2022.
 */
import java.util.Scanner;

public class Problem1 {

	public static void main(String[] args) {
		// 스캐너 객체 keyboard 생성
		Scanner keyboard = new Scanner(System.in);
		
		// 텍스트를 써달라고 안내
		System.out.println("Enter a line of text");
		// 입력받은 문자열을 저장
		String string = keyboard.nextLine();
		// replaceFirst 함수를 통해 입력받은 문자열에서 'hate'를 'love'로 바꾸고 다시 저장
		string = string.replaceFirst("hate", "love");
		// 문자열이 바뀌었다고 안내
		System.out.println("I have rephrased that line to read:");
		// 바뀐 문자열 출력
		System.out.println(string);
		
		// keyboard 닫음
		keyboard.close();
	}
}

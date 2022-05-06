/**
 * Program to move first word to the end
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 2.
 * Last Change: March 30, 2022.
 */
import java.util.Scanner;
public class Problem2 {

	public static void main(String[] args) {
		// 스캐너 객체 keyboard 생성
		Scanner keyboard = new Scanner(System.in);
		// 텍스트를 써달라고 안내
		System.out.println("Enter a line of text. No punctuation please");
		// 첫번째 단어 저장
		String s1 = keyboard.next();
		// 그 이후의 문자열 저장
		String s2 = keyboard.nextLine();
		// 문자열 앞의 공백 제거
		s2 = s2.trim();
		// 문자열 첫글자와 나머지 분리
		String s3 = s2.substring(0,1);
		String s4 = s2.substring(1);
		// 문자열 첫글자를 대문자로 변환
		s3 = s3.toUpperCase();
		// 문자열을 다시 합침
		s2 = s3 + s4;
		// 첫 번째 단어를 맨 뒤로 보내고 문자열과 합침
		s3 = s2 +" "+ s1;
		// 문자열이 바뀌었다고 안내
		System.out.println("I have rephrased that line to read:");
		// 바뀐 문자열 출력
		System.out.println(s3);
		//keyboard 닫음
		keyboard.close();
	}
}

/**
 * Program to asks user to enter favorite color, food,
 * animal and the first name of a friend
 * then print string with those words.
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 3.
 * Last Change: March 30, 2022.
 */
import java.util.Scanner;
public class Problem3 {

	public static void main(String[] args) {
		// 스캐너 객체 keyboard 생성
		Scanner keyboard = new Scanner(System.in);
		// color를 써달라고 안내
		System.out.println("favorite color?");
		// color 단어 저장
		String color = keyboard.nextLine();
		// food를 써달라고 안내
		System.out.println("favorite food?");
		// food 저장
		String food = keyboard.nextLine();
		// animal을 써달라고 안내
		System.out.println("favorite animal?");
		// animal 저장
		String animal = keyboard.nextLine();
		// name을 써달라고 안내
		System.out.println("The first name of a friend?");
		// name 저장
		String name = keyboard.nextLine();
		// 맞는 곳에 넣어서 출력
		System.out.println("I had a dream that "+name+" ate a "+color+" "+animal+" and said it tasted like "+food+"!");
		// keyboard 객체 닫음
		keyboard.close();
	}
}

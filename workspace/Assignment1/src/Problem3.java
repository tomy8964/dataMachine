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
		// ��ĳ�� ��ü keyboard ����
		Scanner keyboard = new Scanner(System.in);
		// color�� ��޶�� �ȳ�
		System.out.println("favorite color?");
		// color �ܾ� ����
		String color = keyboard.nextLine();
		// food�� ��޶�� �ȳ�
		System.out.println("favorite food?");
		// food ����
		String food = keyboard.nextLine();
		// animal�� ��޶�� �ȳ�
		System.out.println("favorite animal?");
		// animal ����
		String animal = keyboard.nextLine();
		// name�� ��޶�� �ȳ�
		System.out.println("The first name of a friend?");
		// name ����
		String name = keyboard.nextLine();
		// �´� ���� �־ ���
		System.out.println("I had a dream that "+name+" ate a "+color+" "+animal+" and said it tasted like "+food+"!");
		// keyboard ��ü ����
		keyboard.close();
	}
}

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
		// ��ĳ�� ��ü keyboard ����
		Scanner keyboard = new Scanner(System.in);
		
		// �ؽ�Ʈ�� ��޶�� �ȳ�
		System.out.println("Enter a line of text");
		// �Է¹��� ���ڿ��� ����
		String string = keyboard.nextLine();
		// replaceFirst �Լ��� ���� �Է¹��� ���ڿ����� 'hate'�� 'love'�� �ٲٰ� �ٽ� ����
		string = string.replaceFirst("hate", "love");
		// ���ڿ��� �ٲ���ٰ� �ȳ�
		System.out.println("I have rephrased that line to read:");
		// �ٲ� ���ڿ� ���
		System.out.println(string);
		
		// keyboard ����
		keyboard.close();
	}
}

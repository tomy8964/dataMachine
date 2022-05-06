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
		// ��ĳ�� ��ü keyboard ����
		Scanner keyboard = new Scanner(System.in);
		// �ؽ�Ʈ�� ��޶�� �ȳ�
		System.out.println("Enter a line of text. No punctuation please");
		// ù��° �ܾ� ����
		String s1 = keyboard.next();
		// �� ������ ���ڿ� ����
		String s2 = keyboard.nextLine();
		// ���ڿ� ���� ���� ����
		s2 = s2.trim();
		// ���ڿ� ù���ڿ� ������ �и�
		String s3 = s2.substring(0,1);
		String s4 = s2.substring(1);
		// ���ڿ� ù���ڸ� �빮�ڷ� ��ȯ
		s3 = s3.toUpperCase();
		// ���ڿ��� �ٽ� ��ħ
		s2 = s3 + s4;
		// ù ��° �ܾ �� �ڷ� ������ ���ڿ��� ��ħ
		s3 = s2 +" "+ s1;
		// ���ڿ��� �ٲ���ٰ� �ȳ�
		System.out.println("I have rephrased that line to read:");
		// �ٲ� ���ڿ� ���
		System.out.println(s3);
		//keyboard ����
		keyboard.close();
	}
}

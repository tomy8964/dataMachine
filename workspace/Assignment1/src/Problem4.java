/**
 * Program that calculate the chage of (1 dollar - price)
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 4.
 * Last Change: March 30, 2022.
 */
import java.util.Scanner;
public class Problem4 {

	public static void main(String[] args) {
		// ��ĳ�� ��ü keyboard ����
		Scanner keyboard = new Scanner(System.in);
		// ����� ������ ���� �� �ʱ�ȭ
		int price,totalChange=0,quarter=0,dimes=0,nickel=0;
		// ��ǰ�� ������ �Է¹���
		System.out.println("Enter price of item");
		System.out.println("(from 25 cents to a dollar, in 5-cent increments): ");
		price = keyboard.nextInt();
		
		// �ܵ��� �� ��Ʈ�� ���
		totalChange = 100 - price;
		// ���� ��� �� ����
		quarter = totalChange/25;
		// ���͸� ����ϰ� �������� �ܵ��� ������Ʈ
		totalChange = totalChange%25;
		// dimes ��� �� ����
		dimes = totalChange/10;
		// dimes ��� �� �ܵ� ������Ʈ
		totalChange = totalChange%10;
		// nickel ��� �� ����
		nickel = totalChange/5;
		
		// �ܵ� ���
		System.out.println("You bought an item for "+price+" cent and gave me a dallar,");
		System.out.println("so your chage is");
		System.out.println(quarter+" quarters,");
		System.out.println(dimes+" dimes, and");
		System.out.println(nickel+" nickel.");
		
		// keyboard ����
		keyboard.close();
	}

}

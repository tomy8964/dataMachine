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
		// 스캐너 객체 keyboard 생성
		Scanner keyboard = new Scanner(System.in);
		// 사용할 변수들 선언 및 초기화
		int price,totalChange=0,quarter=0,dimes=0,nickel=0;
		// 상품의 가격을 입력받음
		System.out.println("Enter price of item");
		System.out.println("(from 25 cents to a dollar, in 5-cent increments): ");
		price = keyboard.nextInt();
		
		// 잔돈의 총 센트를 계산
		totalChange = 100 - price;
		// 쿼터 계산 및 저장
		quarter = totalChange/25;
		// 쿼터를 계산하고 나머지의 잔돈을 업데이트
		totalChange = totalChange%25;
		// dimes 계산 및 저장
		dimes = totalChange/10;
		// dimes 계산 후 잔돈 업데이트
		totalChange = totalChange%10;
		// nickel 계산 및 저장
		nickel = totalChange/5;
		
		// 잔돈 출력
		System.out.println("You bought an item for "+price+" cent and gave me a dallar,");
		System.out.println("so your chage is");
		System.out.println(quarter+" quarters,");
		System.out.println(dimes+" dimes, and");
		System.out.println(nickel+" nickel.");
		
		// keyboard 닫음
		keyboard.close();
	}

}

/**
 * Write a program that reads a string from the 
 * keyboard and tests whether it contains a valid date. 
 * Author : 201835546 Hamgeonwook
 * E-mail Address : tomy8964@naver.com
 * Programming Assignment 4.
 * Last Change: April 15, 2022.
 */
import java.util.Scanner;
public class p4 {
	
	public static void main(String [ ] args){
	    System.out.println("please enter a date to be checked");
		String date="";
		// Scanner object
		Scanner keyboard = new Scanner(System.in);
		  
		//변수 초기화
		int mm = 00;
		int dd = 00;
		int yy = 0000;
		
		// date 입력
		date = keyboard.nextLine();
		// date를 mm/dd/yy 형식으로 나눠서 저장
		String[] ip = date.split("/");
		mm = Integer.parseInt(ip[0]);
		dd = Integer.parseInt(ip[1]);
		yy = Integer.parseInt(ip[2]);
		
		//print
		System.out.println("date is "+mm+":"+dd+":"+yy);
		System.out.println("Your date was " + date);
		
		//leapyear boolean으로 변수 초기화
		boolean isLeapYear=false;
		// is leapyear = true
		if(yy%4==0 && (!(yy%100==0) || yy%400==0))
		{
			isLeapYear=true;
		}
		// mm 값이 올바른지 확인
		if((mm<13) && (mm>0))
		{
			//dd 값이 올바른지 확인
			if((dd>31 && dd<1))
			{
				System.out.println("You have entered an invalid day. Please try again.");
				
			}
			else
			{
				// 9, 4, 6, 11월이 31일 이상이면 오류라고 판단.
				if((mm==9 || mm==4 || mm==6 || mm==11) && (dd>30))
				{
				   System.out.println("It is not a valid date.");
				   System.out.println("September, April, June, and November each have 30 days.");
				}// 2월 이며 leap year이 아닌데 28일을 넘으면 오류 
				else if((mm==2 && (dd>28)) && isLeapYear==false)
				{
					System.out.println("It is not a valid date.");
				    System.out.println("The reason it is invalid: The day value is greater than 28 in February in a non leap year.");
				}//2월 이며 leap year이면 29일을 넘으면 오류
				else if((mm==2 && (dd>29)) && isLeapYear==true)
				{
					System.out.println("It is not a valid date.");
					System.out.println("The reason it is invalid: The day value is greater than 29 in February in a leap year.");
				}// 오류 해당사항 없음 정상적인 날짜
				else System.out.println("It is a valid date.");
				}
			}
		else // mm 값 오류 출력
		{
			System.out.println("It is not a valid date.");
			System.out.println("The reason it is invalid: The month value is not from 1 to 12.");
		}
		}
	}











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
		  
		//���� �ʱ�ȭ
		int mm = 00;
		int dd = 00;
		int yy = 0000;
		
		// date �Է�
		date = keyboard.nextLine();
		// date�� mm/dd/yy �������� ������ ����
		String[] ip = date.split("/");
		mm = Integer.parseInt(ip[0]);
		dd = Integer.parseInt(ip[1]);
		yy = Integer.parseInt(ip[2]);
		
		//print
		System.out.println("date is "+mm+":"+dd+":"+yy);
		System.out.println("Your date was " + date);
		
		//leapyear boolean���� ���� �ʱ�ȭ
		boolean isLeapYear=false;
		// is leapyear = true
		if(yy%4==0 && (!(yy%100==0) || yy%400==0))
		{
			isLeapYear=true;
		}
		// mm ���� �ùٸ��� Ȯ��
		if((mm<13) && (mm>0))
		{
			//dd ���� �ùٸ��� Ȯ��
			if((dd>31 && dd<1))
			{
				System.out.println("You have entered an invalid day. Please try again.");
				
			}
			else
			{
				// 9, 4, 6, 11���� 31�� �̻��̸� ������� �Ǵ�.
				if((mm==9 || mm==4 || mm==6 || mm==11) && (dd>30))
				{
				   System.out.println("It is not a valid date.");
				   System.out.println("September, April, June, and November each have 30 days.");
				}// 2�� �̸� leap year�� �ƴѵ� 28���� ������ ���� 
				else if((mm==2 && (dd>28)) && isLeapYear==false)
				{
					System.out.println("It is not a valid date.");
				    System.out.println("The reason it is invalid: The day value is greater than 28 in February in a non leap year.");
				}//2�� �̸� leap year�̸� 29���� ������ ����
				else if((mm==2 && (dd>29)) && isLeapYear==true)
				{
					System.out.println("It is not a valid date.");
					System.out.println("The reason it is invalid: The day value is greater than 29 in February in a leap year.");
				}// ���� �ش���� ���� �������� ��¥
				else System.out.println("It is a valid date.");
				}
			}
		else // mm �� ���� ���
		{
			System.out.println("It is not a valid date.");
			System.out.println("The reason it is invalid: The month value is not from 1 to 12.");
		}
		}
	}











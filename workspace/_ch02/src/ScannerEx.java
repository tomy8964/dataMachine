import java.util.Scanner;
class ScannerEx {
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		System.out.print("�� �ڸ� ������ �ϳ� �Է��ϼ���");
		String input = scanner.nextLine();
		int num = Integer.parseInt(input);
		
		System.out.println("�Է³��� :"+input);
		System.out.printf("num=%d\n",num);
				
	}
}
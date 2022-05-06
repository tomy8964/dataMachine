
public class Ex2_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int year=1000;
		int age=100;
		System.out.println("year="+ year +" age="+age);
		int tmp;
		tmp =year;
		year =age;
		age =tmp;
		System.out.println("year="+ year +" age="+age);
		System.out.printf("year:%d",year);
	}

}

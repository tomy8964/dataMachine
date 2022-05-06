
public class DogDemo {

	public static void main(String[] args) {
		Dog balto = new Dog();
		balto.name = "Balto";
		balto.age = 8;
		balto.breed = "Siberian Husky";
		balto.writeOutPut();
		
		int humanAge = balto.getAgeInHumanYears();
		System.out.println(humanAge);
	}

}

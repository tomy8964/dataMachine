package tangible;

import java.io.IOException;
import java.util.*;

public class GlobalMembersSand
{
	
	public static int[] PlayerScore= {0,0,0}; //플레이어 스코어 저장 변수
	public static int[] Castle= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // 게임판 배열
	public static int[] ProposeNum = { 0,0,0,0,0 }; // 컴퓨터가 제공하는 5개의 숫자 배열
	public static int trapNumber = 0; // 고르면 패배하는 수(함정수) 제공하는 변수
	public static int PlayNum = 0; // 플레이어 번호 변수
	public static int GamePlaying = 0; // 게임 종료를 위한 변수
	public static int[] finalSelectNum = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  
	// 이미 고른 수를 컴퓨터가 제공하지 않도록 기억하는 배열
	public static int remain = 100; // 고를 수가 몇개 남았는지 확인하는 변수
	
	// 게임판을 리셋하는 함수
	public static void setCastle()
	{
		Arrays.fill(Castle, 0);
		int num = 0;
		for (int i = 0; i < 100; i++)
		{
			num++;
			Castle[i] = num;
		}
	
		tangible.RandomNumbers.seed(time(null));
		trapNumber = Math.abs(tangible.RandomNumbers.nextNumber() % 100 + 1); // 함정수 설정
		GamePlaying = 1; // 게임 진행중
	}

	// 게임판을 보이게 하는 함수
	public static void displayCastle()
	{
		System.out.print("\n               게임판 현황\n");
	for (int i = 0; i < 100; i++)
	{
	
		if (i % 10 == 0 && i != 0)
		{
			System.out.print("\n");
		}
		System.out.printf("%3d ", Castle[i]);
	}
	System.out.print("\n");
	}

	// 게임 메뉴 - 숫자 고르기와 내가 고른 숫자를 선택 가능
	public static void menu(int playerNum) throws IOException
	{
		int num=0;
	while (true)
	{
		System.out.print("1. 숫자 선택, 2. 내 점수 : ");
		String tempVar = ConsoleInput.scanfRead();
		if (tempVar != null)
		{
			num = Integer.parseInt(tempVar);
		}
		if (num == 1)
		{
			return;
		}
		else if (num == 2)
		{
			System.out.println(PlayerScore[playerNum]);
			
			return;
		}
		
		else
		{
			System.out.print("잘못된 입력입니다. 다시 입력해주세요.\n");
				continue;
			}
		}
	}

	// 컴퓨터가 숫자를 제공하는 함수
	public static void numberPropose()
	{
		tangible.RandomNumbers.seed(time(null));
		for (int i = 0; i < 5; i++)
		{
			ProposeNum[i] = Math.abs((tangible.RandomNumbers.nextNumber() % 100) + 1);
			for (int j = 0; j < i; j++)
			{ // 이미 제공된 수라면 다시 반복
			if (ProposeNum[i] == ProposeNum[j])
			{
				i--;
			}
		}
		for (int k = 0; k < 100; k++)
		{ // 이미 이전에 고른 수라면 다시 반복
			if (ProposeNum[i] == finalSelectNum[k])
			{
				i--;
			}
		}
	}
	
	// 제공하는 수를 화면에 출력
	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
		{
			System.out.printf("%d\n", ProposeNum[i]);
		}
		else
		{
			System.out.printf("%d, ", ProposeNum[i]);
			}
		}
	}

	private static int time(Object object) {
		// TODO Auto-generated method stub
		return 0;
	}

	// 사용자로부터 숫자를 입력 받아서 그 수를 게임판에서 제거하는 함수
	public static void numberSelectDelete(int playerNum) throws IOException
	{
		int num = 0;
		// 몇개를 입력받을지 확인
		System.out.print("선택할 숫자의 개수를 입력해주세요(1 ~ 5) : ");
		
		while (true)
		{
			try { 
			
			String tempVar = ConsoleInput.scanfRead();
			if (tempVar != null)
			{
				num = Integer.parseInt(tempVar);
				break;
			}
			if (num > 5 || num < 1)
			{
				System.out.print("잘못된 입력입니다.\n");
				continue;
			}
			else
			{
				break;
			}
		} catch(NumberFormatException e) {
			
		} catch (Exception e) {
			
		}
	}

	// 입력받은 개수만큼 숫자 입력(컴퓨터가 제공한 수가 아닌 수도 입력이 가능하다는 단점이 있음)
	int[] selectNum = new int[num];
	int k=0;
	System.out.printf("%d개의 숫자를 입력해주세요.\n", num);
	
	while(true)
	{
		String tempVar2 = ConsoleInput.scanfRead();
		if (tempVar2 != null)
		{
			if(k==num)
			{
				break;
			}
			try {
				selectNum[k] = Integer.parseInt(tempVar2);
				k++;
			} catch(NumberFormatException e) {
				
			} catch (Exception e) {
				
			}
		}
	}
	k=0;
	//

	// 입력 받은 수는 최종 고른 수들의 배열에 편입
	for (int i = 100 - remain; i < 100 - remain + num; i++)
	{
		finalSelectNum[i] = selectNum[i - 100 + remain];
	}
	remain = remain - num;

	// 함정수를 골랐을 경우 함수 종료(GamePlaying변수로 인해서 게임종료)
	for (int i = 0; i < num; i++)
	{
		if (selectNum[i] == trapNumber)
		{
			GamePlaying = 0;
			System.out.printf("%d은 함정수였습니다.\n", trapNumber);
			return;
		}
	}

	// 함정수를 고르지 않았을 경우 함수 지속
	System.out.print("고른 숫자에 함정수는 없었습니다.\n");
	// 입력받은 개수만큼 점수 더함
	PlayerScore[PlayNum-1]=PlayerScore[PlayNum-1]+num;

	// 해당 고른 숫자들은 게임판에서 제거
	for (int i = 0; i < num; i++)
	{
		Castle[selectNum[i]-1] = 0;
	}
}

public final class ConsoleInput
{
private static boolean goodLastRead = false;
public static boolean lastReadWasGood()
{
	return goodLastRead;
}

public static String readToWhiteSpace(boolean skipLeadingWhiteSpace) throws IOException
{
	String input = "";
	char nextChar;
	while (Character.isWhitespace(nextChar = (char)System.in.read()))
	{
		//accumulate leading white space if skipLeadingWhiteSpace is false:
		if (!skipLeadingWhiteSpace)
		{
			input += nextChar;
		}
	}
	//the first non white space character:
	input += nextChar;
	
	//accumulate characters until white space is reached:
	while (!Character.isWhitespace(nextChar = (char)System.in.read()))
	{
		input += nextChar;
	}

	goodLastRead = input.length() > 0;
	return input;
}

public static String scanfRead() throws IOException
{
	return scanfRead(null, -1);
}

public static String scanfRead(String unwantedSequence) throws IOException
{
	return scanfRead(unwantedSequence, -1);
}
	
public static String scanfRead(String unwantedSequence, int maxFieldLength) throws IOException
{
	String input = "";

	char nextChar;
	if (unwantedSequence != null)
	{
		nextChar = '\0';
		for (int charIndex = 0; charIndex < unwantedSequence.length(); charIndex++)
		{
			if (Character.isWhitespace(unwantedSequence.charAt(charIndex)))
			{
				//ignore all subsequent white space:
				while (Character.isWhitespace(nextChar = (char)System.in.read()))
				{
				}
			}
			else
			{
				//ensure each character matches the expected character in the sequence:
						nextChar = (char)System.in.read();
						if (nextChar != unwantedSequence.charAt(charIndex))
							return null;
					}
				}

				input = (new Character(nextChar)).toString();
				if (maxFieldLength == 1)
					return input;
			}

			while (!Character.isWhitespace(nextChar = (char)System.in.read()))
			{
				input += nextChar;
				if (maxFieldLength == input.length())
					return input;
			}

			return input;
		}
}
	
	

public static void main(String[] args) throws IOException
{
	setCastle();
	System.out.print("게임판이 리셋되었습니다.\n");
	System.out.printf("함정수는 %d\n", trapNumber); // 이 부분은 테스트를 위해 삽입한 문장
	displayCastle();
	System.out.print("\n게임 시작\n");
	
	while (true)
	{
		PlayNum = PlayNum % 3+1;
		System.out.printf("\n%d번째 플레이어의 차례입니다.\n", PlayNum);
		menu(PlayNum-1);
		System.out.printf("\n%d번째 플레이어에게 제안된 숫자\n", PlayNum);
		numberPropose();
		numberSelectDelete(PlayNum-1);
	if (GamePlaying == 0)
	{
		System.out.printf("%d번째 플레이어 게임 패배!", PlayNum);
		break; // 함정수를 골라서 GamePlaying이 0이 되는 경우 무한루프를 빠져나가 게임 종료
	}
	displayCastle();
	
	}
	System.out.println("\n게임 종료!\n");
	for(int i=0;i<3;i++)
	{
		System.out.printf("%d번째 플레이어 점수 : ",i+1);
		System.out.println(PlayerScore[i]);
	}
}
}
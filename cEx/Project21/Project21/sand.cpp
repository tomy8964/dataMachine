#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Castle[100] = { 0, }; // 게임판 배열
int ProposeNum[5] = { 0, }; // 컴퓨터가 제공하는 5개의 숫자 배열
int trapNumber = 0; // 고르면 패배하는 수(함정수) 제공하는 변수
int PlayNum = 0; // 플레이어 번호 변수
int GamePlaying = 0; // 게임 종료를 위한 변수
int finalSelectNum[100] = { 0, }; // 이미 고른 수를 컴퓨터가 제공하지 않도록 기억하는 배열
int remain = 100; // 고를 수가 몇개 남았는지 확인하는 변수

typedef struct Player { // player의 정보를 담을 구조체를 선언(아직 넣지 않음)
	int score;
	int selectNum2[20];
}Player;
Player player[3] = { 0, };

// 게임판을 리셋하는 함수
void setCastle()
{
	int num = 0;
	for (int i = 0; i < 100; i++)
	{
		num++;
		Castle[i] = num;
	}

	srand(time(NULL));
	trapNumber = rand() % 100 + 1; // 함정수 설정
	GamePlaying = 1; // 게임 진행중
}

// 게임판을 보이게 하는 함수
void displayCastle()
{
	printf("\n               게임판 현황\n");
	for (int i = 0; i < 100; i++)
	{

		if (i % 10 == 0 && i != 0)
		{
			printf("\n");
		}
		printf("%3d ", Castle[i]);
	}
	printf("\n");
}

// 게임 메뉴 - 숫자 고르기와 내가 고른 숫자를 선택 가능 (확인 기능은 아직 미구현)
void menu(Player* player)
{
	int num;
	//int Confirm = 0;
	while (1)
	{
		printf("1. 숫자 선택, 2. 내가 골랐던 숫자 확인(확인 기능 미구현) : ");
		scanf("%d", &num);
		if (num == 1)
			return;
		/*else if (num == 2)
		{
			for (int i = 0; i < 100; i++)
			{
				if (*player->selectNum <= 0 || player->selectNum >= 100)
					break;
				printf("%d ", player->selectNum);
				Confirm = 1;
			}
			if (Confirm == 0)
			{
				printf("아직 고른 숫자가 없습니다.\n");
			}
			return;
		}*/
		else
		{
			printf("잘못된 입력입니다. 다시 입력해주세요.\n");
			continue;
		}
	}
}

// 컴퓨터가 숫자를 제공하는 함수
void numberPropose()
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		ProposeNum[i] = (rand() % 100) + 1;
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
			printf("%d\n", ProposeNum[i]);
		else
			printf("%d, ", ProposeNum[i]);
	}
}

// 사용자로부터 숫자를 입력 받아서 그 수를 게임판에서 제거하는 함수
void numberSelectDelete()
{
	int num;
	while (1)
	{ // 몇개를 입력받을지 확인
		printf("선택할 숫자의 개수를 입력해주세요(1 ~ 5) : ");
		scanf("%d", &num);
		if (num > 5 || num < 1)
		{
			printf("잘못된 입력입니다.\n");
			continue;
		}
		else
			break;
	}

	// 입력받은 개수만큼 숫자 입력(컴퓨터가 제공한 수가 아닌 수도 입력이 가능하다는 단점이 있음)
	int* selectNum = (int*)malloc(sizeof(int) * num);
	printf("%d개의 숫자를 입력해주세요.\n", num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &selectNum[i]);
	}

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
			printf("%d은 함정수였습니다.\n", trapNumber);
			return;
		}
	}

	// 함정수를 고르지 않았을 경우 함수 지속
	printf("고른 숫자에 함정수는 없었습니다.\n");

	// 해당 고른 숫자들은 게임판에서 제거
	for (int i = 0; i < num; i++)
	{
		Castle[selectNum[i] - 1] = 0;
	}
}

int main()
{
	setCastle();
	printf("게임판이 리셋되었습니다.\n");
	printf("함정수는 %d\n", trapNumber); // 이 부분은 테스트를 위해 삽입한 문장
	displayCastle();


	printf("\n게임 시작\n");
	while (1)
	{
		PlayNum = PlayNum % 3 + 1;
		printf("\n%d번째 플레이어의 차례입니다.\n", PlayNum);
		menu(&player[PlayNum]);
		printf("\n%d번째 플레이어에게 제안된 숫자\n", PlayNum);
		numberPropose();
		numberSelectDelete();
		if (GamePlaying == 0)
		{
			printf("%d번째 플레이어 게임 패배!", PlayNum);
			break; // 함정수를 골라서 GamePlaying이 0이 되는 경우 무한루프를 빠져나가 게임 종료
		}
		displayCastle();
		/*for (int i = 0; i < 100; i++)
		{
			if (finalSelectNum[i] == 0)
				continue;
			else
				printf("%d ", finalSelectNum[i]);
		}*/ // 이 부분은 테스트를 위해 삽입한 문장
	}
	printf("\n게임 종료!\n");

	return 0;
}
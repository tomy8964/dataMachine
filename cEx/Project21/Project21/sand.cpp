#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Castle[100] = { 0, }; // ������ �迭
int ProposeNum[5] = { 0, }; // ��ǻ�Ͱ� �����ϴ� 5���� ���� �迭
int trapNumber = 0; // ���� �й��ϴ� ��(������) �����ϴ� ����
int PlayNum = 0; // �÷��̾� ��ȣ ����
int GamePlaying = 0; // ���� ���Ḧ ���� ����
int finalSelectNum[100] = { 0, }; // �̹� �� ���� ��ǻ�Ͱ� �������� �ʵ��� ����ϴ� �迭
int remain = 100; // �� ���� � ���Ҵ��� Ȯ���ϴ� ����

typedef struct Player { // player�� ������ ���� ����ü�� ����(���� ���� ����)
	int score;
	int selectNum2[20];
}Player;
Player player[3] = { 0, };

// �������� �����ϴ� �Լ�
void setCastle()
{
	int num = 0;
	for (int i = 0; i < 100; i++)
	{
		num++;
		Castle[i] = num;
	}

	srand(time(NULL));
	trapNumber = rand() % 100 + 1; // ������ ����
	GamePlaying = 1; // ���� ������
}

// �������� ���̰� �ϴ� �Լ�
void displayCastle()
{
	printf("\n               ������ ��Ȳ\n");
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

// ���� �޴� - ���� ����� ���� �� ���ڸ� ���� ���� (Ȯ�� ����� ���� �̱���)
void menu(Player* player)
{
	int num;
	//int Confirm = 0;
	while (1)
	{
		printf("1. ���� ����, 2. ���� ����� ���� Ȯ��(Ȯ�� ��� �̱���) : ");
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
				printf("���� �� ���ڰ� �����ϴ�.\n");
			}
			return;
		}*/
		else
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			continue;
		}
	}
}

// ��ǻ�Ͱ� ���ڸ� �����ϴ� �Լ�
void numberPropose()
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		ProposeNum[i] = (rand() % 100) + 1;
		for (int j = 0; j < i; j++)
		{ // �̹� ������ ����� �ٽ� �ݺ�
			if (ProposeNum[i] == ProposeNum[j])
			{
				i--;
			}
		}
		for (int k = 0; k < 100; k++)
		{ // �̹� ������ �� ����� �ٽ� �ݺ�
			if (ProposeNum[i] == finalSelectNum[k])
			{
				i--;
			}
		}
	}
	// �����ϴ� ���� ȭ�鿡 ���
	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
			printf("%d\n", ProposeNum[i]);
		else
			printf("%d, ", ProposeNum[i]);
	}
}

// ����ڷκ��� ���ڸ� �Է� �޾Ƽ� �� ���� �����ǿ��� �����ϴ� �Լ�
void numberSelectDelete()
{
	int num;
	while (1)
	{ // ��� �Է¹����� Ȯ��
		printf("������ ������ ������ �Է����ּ���(1 ~ 5) : ");
		scanf("%d", &num);
		if (num > 5 || num < 1)
		{
			printf("�߸��� �Է��Դϴ�.\n");
			continue;
		}
		else
			break;
	}

	// �Է¹��� ������ŭ ���� �Է�(��ǻ�Ͱ� ������ ���� �ƴ� ���� �Է��� �����ϴٴ� ������ ����)
	int* selectNum = (int*)malloc(sizeof(int) * num);
	printf("%d���� ���ڸ� �Է����ּ���.\n", num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &selectNum[i]);
	}

	// �Է� ���� ���� ���� �� ������ �迭�� ����
	for (int i = 100 - remain; i < 100 - remain + num; i++)
	{
		finalSelectNum[i] = selectNum[i - 100 + remain];
	}
	remain = remain - num;

	// �������� ����� ��� �Լ� ����(GamePlaying������ ���ؼ� ��������)
	for (int i = 0; i < num; i++)
	{
		if (selectNum[i] == trapNumber)
		{
			GamePlaying = 0;
			printf("%d�� �����������ϴ�.\n", trapNumber);
			return;
		}
	}

	// �������� ���� �ʾ��� ��� �Լ� ����
	printf("�� ���ڿ� �������� �������ϴ�.\n");

	// �ش� �� ���ڵ��� �����ǿ��� ����
	for (int i = 0; i < num; i++)
	{
		Castle[selectNum[i] - 1] = 0;
	}
}

int main()
{
	setCastle();
	printf("�������� ���µǾ����ϴ�.\n");
	printf("�������� %d\n", trapNumber); // �� �κ��� �׽�Ʈ�� ���� ������ ����
	displayCastle();


	printf("\n���� ����\n");
	while (1)
	{
		PlayNum = PlayNum % 3 + 1;
		printf("\n%d��° �÷��̾��� �����Դϴ�.\n", PlayNum);
		menu(&player[PlayNum]);
		printf("\n%d��° �÷��̾�� ���ȵ� ����\n", PlayNum);
		numberPropose();
		numberSelectDelete();
		if (GamePlaying == 0)
		{
			printf("%d��° �÷��̾� ���� �й�!", PlayNum);
			break; // �������� ��� GamePlaying�� 0�� �Ǵ� ��� ���ѷ����� �������� ���� ����
		}
		displayCastle();
		/*for (int i = 0; i < 100; i++)
		{
			if (finalSelectNum[i] == 0)
				continue;
			else
				printf("%d ", finalSelectNum[i]);
		}*/ // �� �κ��� �׽�Ʈ�� ���� ������ ����
	}
	printf("\n���� ����!\n");

	return 0;
}
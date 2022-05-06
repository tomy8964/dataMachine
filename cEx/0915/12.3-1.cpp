#include<stdio.h>
/* 지난 일수를 계산하기 위한 변수를 전역변수로 정의*/
int d1, m, y, ps;

struct date {
	int month;
	int day;
	int year;
};

int days(struct date* date1)
{

	int py, pd, pm = 0;

	if (date1->year > 2000)
	{
		py = date1->year - 2000;
	}
	else {
		py = 2000 - date1->year;
	}
	pm = date1->month - 1;
	pd = date1->day - 1;

	y = py * 360;
	m = pm * 30;
	d1 = pd;
	ps = d1 + m + y;

	return ps;

}

int main() {
	struct date date1;

	printf("type month\n");
	scanf_s("%d", &date1.month);
	printf("type day\n");
	scanf_s("%d", &date1.day);
	printf("type year\n");
	scanf_s("%d", &date1.year);

	ps = days(&date1);
	printf("입력하신 날짜는 2000.01.01 이후로 %d 일 지났습니다", ps);

	return 0;
}

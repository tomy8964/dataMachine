#include<stdio.h>
/* 지난 일수를 계산하기 위한 변수를 전역변수로 정의*/

int fm, fd, fy, sm, sd, sy;

struct date {
	int fm;
	int fd;
	int fy;
	int sm;
	int sd;
	int sy;
};

int recent(struct date* date1)
{
	if (date1->fy == date1->sy)
	{
		if (date1->fm == date1->sm) {
			if (date1->fd < date1->sd) {
				printf("later date is %d %d %d", date1->sy, date1->sm, date1->sd);
			}
			else {
				printf("later date is % d % d % d", date1->fy, date1->fm, date1->fd);
			}
		}
		else if (date1->fm < date1->sm)
		{
			printf("later date is %d %d %d", date1->sy, date1->sm, date1->sd);
		}
		else {
			printf("later date is % d % d % d", date1->fy, date1->fm, date1->fd);
		}
	}
	else if (date1->fy < date1->sy) {
		printf("later date is %d %d %d", date1->sy, date1->sm, date1->sd);
	}
	else {
		printf("later date is % d % d % d", date1->fy, date1->fm, date1->fd);
	}

	return 0;

}

int main() {
	struct date date1;

	printf("type first month\n");
	scanf_s("%d", &date1.fm);
	printf("type first day\n");
	scanf_s("%d", &date1.fd);
	printf("type first year\n");
	scanf_s("%d", &date1.fy);
	printf("type second month\n");
	scanf_s("%d", &date1.sm);
	printf("type second day\n");
	scanf_s("%d", &date1.sd);
	printf("type second year\n");
	scanf_s("%d", &date1.sy);

	recent(&date1);

	return 0;
}

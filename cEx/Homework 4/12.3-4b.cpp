#include<stdio.h>
/* 지난 일수를 계산하기 위한 변수를 전역변수로 정의*/

int fm, fd, fy, sm, sd, sy, ld, lm, ly;

struct date {
	int fm;
	int fd;
	int fy;
	int sm;
	int sd;
	int sy;
};

struct laterdate {
	int ld;
	int lm;
	int ly;
};

int recent(struct date* date1, struct laterdate* date2)
{
	if (date1->fy == date1->sy)
	{
		if (date1->fm == date1->sm) {
			if (date1->fd < date1->sd) {
				printf("later date is %d %d %d", date1->sy, date1->sm, date1->sd);
				date2->ld = date1->sd;
				date2->lm = date1->sm;
				date2->ly = date1->sy;
			}
			else {
				printf("later date is % d % d % d", date1->fy, date1->fm, date1->fd);
				date2->ld = date1->fd;
				date2->lm = date1->fm;
				date2->ly = date1->fy;
			}
		}
		else if (date1->fm < date1->sm)
		{
			printf("later date is %d %d %d", date1->sy, date1->sm, date1->sd);
			date2->ld = date1->sd;
			date2->lm = date1->sm;
			date2->ly = date1->sy;
		}
		else {
			printf("later date is % d % d % d", date1->fy, date1->fm, date1->fd);
			date2->ld = date1->fd;
			date2->lm = date1->fm;
			date2->ly = date1->fy;
		}
	}
	else if (date1->fy < date1->sy) {
		printf("later date is %d %d %d", date1->sy, date1->sm, date1->sd);
		date2->ld = date1->sd;
		date2->lm = date1->sm;
		date2->ly = date1->sy;
	}
	else {
		printf("later date is % d % d % d", date1->fy, date1->fm, date1->fd);
		date2->ld = date1->fd;
		date2->lm = date1->fm;
		date2->ly = date1->fy;
	}

	printf("\nlatetdate struct member value is %d %d %d", date2->ly, date2->lm, date2->ld);

	return 0;

}

int main() {
	struct date date1;
	struct laterdate date2;
	int latedate;

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

	recent(&date1, &date2);



	return 0;
}

#include "common.h"

void logprint(int n)
{
	switch (n)
	{
	case 1:
		printf("* 보물을 찾았습니다!");
		break;
	case 2:
		printf("* 동전을 주웠습니다!");
		break;
	case 3:
		printf("* 함정에 빠졌습니다!");
		break;
	case 4:
		printf("* 미끄러 넘어졌습니다!");
		break;
	case 5:
		printf("* 음식을 찾았습니다!");
		break;
	}
}

void logreset(int * log)
{
	for (int i = 0; i < 5; i++) {
		log[i] = 0;
	}
	gotoxy(0, -8);
	printf("                               ");
	gotoxy(0, -7);
	printf("                               ");
	gotoxy(0, -6);
	printf("                               ");
	gotoxy(0, -5);
	printf("                               ");
	gotoxy(0, -4);
	printf("                               ");
}

void logupdate(int n, int log[5])
{
	for (int i = 3; i >= 0 ; i--) {
		log[i + 1] = log[i];
	}

	log[0] = n;

	gotoxy(0, -8);
	printf("                               ");
	gotoxy(0, -8);
	logprint(log[0]);

	gotoxy(0, -7);
	printf("                               ");
	gotoxy(0, -7);
	logprint(log[1]);

	gotoxy(0, -6);
	printf("                               ");
	gotoxy(0, -6);
	logprint(log[2]);

	gotoxy(0, -5);
	printf("                               ");
	gotoxy(0, -5);
	logprint(log[3]);

	gotoxy(0, -4);
	printf("                               ");
	gotoxy(0, -4);
	logprint(log[4]);
}
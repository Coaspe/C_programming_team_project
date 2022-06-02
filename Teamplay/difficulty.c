#include "common.h"

void difficulty(int* dif)
{
	int yes = 1;
	int ch;

	emptyinfo();

	while (1) {
		gotoxy(15, 16);
		printf("난이도를 선택하세요");

		gotoxy(15, 14);
		printf("1. 쉬움");

		gotoxy(15, 12);
		printf("2. 보통");

		gotoxy(15, 10);
		printf("3. 어려움");

		gotoxy(15, 8);
		printf("4. 매우 어려움");

		gotoxy(44, 17);
		printf("↑, ↓ 로 이동");

		gotoxy(44, 16);
		printf("Enter로 결정");

		while (1) {
			gotoxy(15, (15 - (2 * *dif)));
			printf("-------------------");

			ch = _getch();
			gotoxy(15, (15 - (2 * *dif)));
			printf("                   ");

			if (ch == 224) {
				ch = _getch();
				switch (ch) {
				case 72:
					if (*dif != 1) {
						*dif -= 1;
					}
					else {
						*dif = 4;
					}
					break;
				case 80:
					if (*dif != 4) {
						*dif += 1;
					}
					else {
						*dif = 1;
					}
					break;
				}
			}
			else if (ch == 13)
				break;
		}

		for (int i = 0; i < YAXIS; i++) {
			for (int j = 0; j < XAXIS; j++) {
				gotoxy(j, i);
				printf("  ");
			}
		}

		gotoxy(15, 16);

		switch (*dif) {
		case 1:
			printf("쉬움");
			break;
		case 2:
			printf("보통");
			break;
		case 3:
			printf("어려움");
			break;
		case 4:
			printf("매우 어려움");
			break;
		}
		printf("으로 하시겠습니까?");

		gotoxy(15, 14);
		printf("1. 예");

		gotoxy(15, 12);
		printf("2. 아니요");

		while (1) {
			gotoxy(15, 12 + yes);
			printf("-------------------");

			ch = _getch();

			gotoxy(15, 12 + yes);
			printf("                   ");

			if (ch == 224) {
				ch = _getch();
				switch (ch) {
				case 72:
				case 80:
					yes *= -1;
					break;
				}
			}
			else if (ch == 13)
				break;
		}

		for (int i = 0; i < YAXIS; i++) {
			for (int j = 0; j < XAXIS; j++) {
				gotoxy(j, i);
				printf("  ");
			}
		}

		if (yes == 1)
			break;
		else
			continue;
	}
}
#include "common.h"

void place(int x, int y)
{
	gotoxy(x, y);
	printf("□");
}

void replace(int x, int y)
{
	gotoxy(x, y);
	printf("  ");
}

void setmovement(int*movement, int*level, int*dif)
{
	*movement = MOVEMAX - ((*level / 5) * *dif * 5);
}

// 타일의 특성
void tile(int position, int log[5], int* point, int* level, int* health)
{
	switch (position) 
	{
	case 1:
		*point += *level * 100;
		logupdate(1, log);
		break;
	case 2:
		*point += *level * 10;
		logupdate(2, log);
		break;
	case 3:
		*point -= *level * 50;
		*health -= 1;
		logupdate(3, log);
		break;
	case 4:
		*point -= *level * 5;
		*health -= 1;
		logupdate(4, log);
		break;
	case 5:
		*point += *level * 5;
		if (*health != 5) *health += 1;
		logupdate(5, log);
		break;
	}
}

int input(int*playerx, int*playery, int table[40][20], int* movement, int* health, int* log, int* point, int* level)
{
	int ch;
	int r = 0;

	ch = _getch();
	if (ch == 224) {
		ch = _getch();
		table[*playerx][*playery] = 0;
		switch (ch) {
		case 72:
			if (*playery == 19)
				break;
			else {
				replace(*playerx, *playery);
				*playery += 1;
				place(*playerx, *playery);
				*movement -= 1;
				break;
			}
		case 80:
			if (*playery == 0)
				break;
			else {
				replace(*playerx, *playery);
				*playery -= 1;
				place(*playerx, *playery);
				*movement -= 1;
				break;
			}
		case 75:
			if (*playerx == 0)
				break;
			else {
				replace(*playerx, *playery);
				*playerx -= 1;
				place(*playerx, *playery);
				*movement -= 1;
				break;
			}
		case 77:
			if (*playerx == 39)
				break;
			else {
				replace(*playerx, *playery);
				*playerx += 1;
				place(*playerx, *playery);
				*movement -= 1;
				break;
			}
		}
	}
	else if (ch == 27) {
		return pausemenu(table);
	}

	tile(table[*playerx][*playery], log, point, level, health); //이동한 위치 이벤트 실행

	if (table[*playerx][*playery] == 1) //목표 도달
		r = 5;

	table[*playerx][*playery] = -1;

	if (r == 0 && *health <= 0)
		r = 1; //게임오버

	else if (r == 0 && movement <= 0)
		r = 1;

	return r;
}
#include "common.h"

void gotoxy(int x, int y)
{
	x = 2 * x + 2;
	y = YAXIS - y;
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
#include "common.h"


void tableset(int* dif, int*level, int table[40][20])
{
	int x, y;

	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 20; j++) {
			table[i][j] = 0;
		}
	}

	table[0][0] = -1;

	for (int i = 0; i < (*level / 5 + 1) * (*dif / 2 + 1) + 2; i++) {
		x = rand_x();
		y = rand_y();

		if (table[x][y] != 0)
			continue;

		table[x][y] = rand_t();
	}

	while (1) {
		x = rand_x();
		y = rand_y();

		if (table[x][y] != 0)
			continue;
		else
			table[x][y] = 1;
			break;
	}
}

void tableprint(int table[40][20])
{
	for (int j = 0; j < 20; j++) {
		gotoxy(0, j);
		for (int i = 0; i < 40; i++) {
			if (table[i][j] == 0) {
				printf("  ");
			}
			else if (table[i][j] == -1) {
				printf("¡à");
			}
			else {
				printf("¢¹");
			}
		}
	}
}

void stat(int* level, int* point, int* movement, int* health)
{
	gotoxy(50, 17);
	printf("%6d", *level);

	gotoxy(50, 16);
	printf("%6d", *point);

	gotoxy(50, 15);
	printf("%6d", *movement);

	gotoxy(50, 14);
	for (int i = 0; i < 5 - *health; i++) {
		printf("¢½");
	}
	for (int i = 0; i < *health; i++) {
		printf("¢¾");
	}
}
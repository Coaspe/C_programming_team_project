#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#define XAXIS 40
#define YAXIS 20
#define MOVEMAX 250

struct highsc {
	char name[4];
	int score;
};

void cursorview(void); //제출시 지우기

void difficulty(int*);
int rand_x(void);
int rand_y(void);
int rand_t(void);
void run(void);
void title(void);
void tableset(int*,int*, int table[40][20]);
void tableprint(int table[40][20]);
void gotoxy(int, int);
int input(int*, int*, int table[40][20], int*, int*, int*, int*, int*);
void tile(int, int*, int*, int*, int*);
void stat(int*, int*, int*, int*);
void logupdate(int, int log[5]);
void logreset(int*);
void emptyscreen(void);
void emptyinfo(void);
void screenchange(void);
void infoprint(void);
void levelshow(int*);
int pausemenu(int table[40][20]);
int gameover(int*);
void setmovement(int*, int*, int*);

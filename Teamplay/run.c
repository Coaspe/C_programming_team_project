#include "common.h"

int table[40][20] = { 0 }; // 현재 위치 -1, 빈칸 0, 목표지점 1, 나머지 타일 2 ~ (rand_t)
int log[5] = { 0 }; //게임 로그

int dif = 1; //난이도
int* pDif = &dif;

int playerx = 0; //현재 플레이어 x축 좌표
int *pPlayerx = &playerx;
int playery = 0; //현재 플레이어 y축 좌표
int* pPlayery = &playery;

int level = 0; //현재 레벨
int* pLevel = &level;

int point; //점수
int* pPoint = &point;

int movement = 0; //남은 이동 횟수
int* pMovement = &movement;

int health = 5; //체력
int* pHealth = &health;

void run(void)
{
	int r; //게임 진행/종료 판단하는 변수. 0 = 계속, 1 = 게임오버, 2 = 난이도선택으로, 3 = 타이틀로, 4 = 게임종료, 5 = 클리어

	cursorview(); //커서 안보이게 하는 함수, 제출시 지우기

	emptyscreen(); //비어있는 ui 출력: screen.c

	while (1) {
		title(); //타이틀 화면, 이 함수에서 Enter 받으면 while break: screen.c

		while (1) {
			screenchange(); //화면전환: screen.c
			difficulty(pDif); //난이도 선택 dif 설정 후 밑의 while로 진행: difficulty.c
			emptyinfo(); //우측 정보란 지우는 함수: screen.c
			*pLevel = 0;
			*pHealth = 0;

			while (1) {
				// 플레이어 위치 초기화 x
				*pPlayerx = 0;
				// 플레이어 위치 초기화 y
				*pPlayery = 0;

				*pHealth = 5;
				*pLevel += 1;
				tableset(pDif, pLevel, table); //맵에 깃발 위치 설정: table.c

				screenchange();
				tableprint(table); //게임 테이블 출력: table.c
				infoprint(); //우측 정보 ui 출력: screen.c
				setmovement(pMovement, pLevel, pDif);  // 이동 횟수 설정: input.c
				stat(pLevel, pPoint, pMovement, pHealth); //우측 정보 수치 출력: table.c

				levelshow(pLevel); //현재 레벨 보여주는 
				tableprint(table);

				do {
					r = input(pPlayerx, pPlayery, table, pMovement, pHealth, log, pPoint, pLevel); //입력받는 함수: input.c
					stat(pLevel, pPoint, pMovement, pHealth);
				} while (r == 0); //r = 0일때 계속하기

				if (r == 1)
					r = gameover(pPoint); //r = 1일때 게임오버: screen.c

				if (r != 5) //r = 5 일때 다음 레벨로
					break;
			}

			if (r == 3 || r == 4) //r = 2 일때 난이도선택으로
				break;
		}
		if (r == 3) //r = 3 일때 타이틀로
			screenchange();

		else if (r == 4) //r = 4 일때 게임 종료
			break;
	}
}
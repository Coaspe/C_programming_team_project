#include "common.h"

int table[40][20] = { 0 }; // ���� ��ġ -1, ��ĭ 0, ��ǥ���� 1, ������ Ÿ�� 2 ~ (rand_t)
int log[5] = { 0 }; //���� �α�

int dif = 1; //���̵�
int* pDif = &dif;

int playerx = 0; //���� �÷��̾� x�� ��ǥ
int *pPlayerx = &playerx;
int playery = 0; //���� �÷��̾� y�� ��ǥ
int* pPlayery = &playery;

int level = 0; //���� ����
int* pLevel = &level;

int point; //����
int* pPoint = &point;

int movement = 0; //���� �̵� Ƚ��
int* pMovement = &movement;

int health = 5; //ü��
int* pHealth = &health;

void run(void)
{
	int r; //���� ����/���� �Ǵ��ϴ� ����. 0 = ���, 1 = ���ӿ���, 2 = ���̵���������, 3 = Ÿ��Ʋ��, 4 = ��������, 5 = Ŭ����

	cursorview(); //Ŀ�� �Ⱥ��̰� �ϴ� �Լ�, ����� �����

	emptyscreen(); //����ִ� ui ���: screen.c

	while (1) {
		title(); //Ÿ��Ʋ ȭ��, �� �Լ����� Enter ������ while break: screen.c

		while (1) {
			screenchange(); //ȭ����ȯ: screen.c
			difficulty(pDif); //���̵� ���� dif ���� �� ���� while�� ����: difficulty.c
			emptyinfo(); //���� ������ ����� �Լ�: screen.c
			*pLevel = 0;
			*pHealth = 0;

			while (1) {
				// �÷��̾� ��ġ �ʱ�ȭ x
				*pPlayerx = 0;
				// �÷��̾� ��ġ �ʱ�ȭ y
				*pPlayery = 0;

				*pHealth = 5;
				*pLevel += 1;
				tableset(pDif, pLevel, table); //�ʿ� ��� ��ġ ����: table.c

				screenchange();
				tableprint(table); //���� ���̺� ���: table.c
				infoprint(); //���� ���� ui ���: screen.c
				setmovement(pMovement, pLevel, pDif);  // �̵� Ƚ�� ����: input.c
				stat(pLevel, pPoint, pMovement, pHealth); //���� ���� ��ġ ���: table.c

				levelshow(pLevel); //���� ���� �����ִ� 
				tableprint(table);

				do {
					r = input(pPlayerx, pPlayery, table, pMovement, pHealth, log, pPoint, pLevel); //�Է¹޴� �Լ�: input.c
					stat(pLevel, pPoint, pMovement, pHealth);
				} while (r == 0); //r = 0�϶� ����ϱ�

				if (r == 1)
					r = gameover(pPoint); //r = 1�϶� ���ӿ���: screen.c

				if (r != 5) //r = 5 �϶� ���� ������
					break;
			}

			if (r == 3 || r == 4) //r = 2 �϶� ���̵���������
				break;
		}
		if (r == 3) //r = 3 �϶� Ÿ��Ʋ��
			screenchange();

		else if (r == 4) //r = 4 �϶� ���� ����
			break;
	}
}
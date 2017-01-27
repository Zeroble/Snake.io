// Snake.io.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

typedef enum g_gmaeStatus {
	INTRO, RUNNING, END
}gameStatus;
gameStatus gStatus = INTRO;

typedef enum g_gameDirection {
	UP,LEFT,RIGHT,DOWN
}gameDirection;
gameDirection gDirection = RIGHT;

typedef enum g_itemOnOff {
	ON,OFF
}gameItemOnOff;
gameItemOnOff gItemoo = OFF;

typedef struct g_item {
	int x, y;
}gameItem;
gameItem gItem;


void startIntro() {
	//                                                                 ..
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("                                                   N a d e k o . i o                                                   \n");//17
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("                                                                                                                       \n");
	printf("                                                         상 : 8                                                        \n");
	printf("                                                         하 : 5                                                        \n");
	printf("                                                         좌 : 4                                                        \n");
	printf("      ■■■■■     ⓤ                                  우 : 6                                                        \n");
	printf("      ■                                                                                                               \n");
	printf("      ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■                                       \n");
	printf("                                                                              ■                                       \n");
	printf("                                                                              ■                                       \n");
	printf("                                                                              ■                                       \n");
	printf("                                                                              ■                                       \n");
	printf("                                                                              ■■■■■■                             \n");
	printf("                                                                                        ■                             \n");
	printf("                                                                                        ■                             \n");
	printf("                                        ■■■■■■                                    ■■■■■■■■■■■         \n");
	printf("                                                  ■                                                        ■         \n");
	printf("                                                  ■                                                        ■         \n");
	printf("                                                  ■                                                        ■         \n");
	printf("                                                  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■         \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       ");
	_getch();
}
void end(int score) {
	system("cls");
	printf("                                                         E N D                                                         \n");
	printf("                                                    S C O R E : %3d                                                    \n",score);
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       ");
	_getch();
}
int main()
{
	//120*100
	int x[180];
	int y[180];
	int Ix, Iy;
	int snakeLen = 1;

	char nKey;

	clock_t curTime, oldTime;
	oldTime = clock();

	startIntro();
	gStatus = RUNNING;

	x[0] = 60;
	y[0] = 15; //초기위치값
	
	while (1)
	{
		if (gStatus == END)
			break;

		if (_kbhit())
		{
			nKey = _getch();
			switch (nKey)
			{
			case '8': //위
				gDirection = UP;
				break;

			case '4': //왼쪽
				gDirection = LEFT;
				break;

			case '6': //오른쪽
				gDirection = RIGHT;
				break;

			case '5': //아래
				gDirection = DOWN;
				break;
			}
		}
	
		Ix = x[0];
		Iy = y[0];

		switch (gDirection)
		{
		case UP :
			y[0]--;
			if (y[0] < 0)
				gStatus = END;
			break;
		case LEFT :
			x[0]--;
			x[0]--;
			if (x[0] < 0)
				gStatus = END;
			break;
		case RIGHT :
			x[0]++;
			x[0]++;
			if (x[0] > 118)
				gStatus = END;
			break;
		case DOWN :
			y[0]++;
			if (y[0] > 29)
				gStatus = END;
			break;
		}
		for (int i = snakeLen - 1; i > 1; i--) {
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[1] = Ix;
		y[1] = Iy;
		if (x[0] == gItem.x && y[0] == gItem.y) {//먹는판정
			snakeLen++;
			gItemoo = OFF;
		} 

		if (gItemoo == OFF) { //u재생성
			gItemoo = ON;
			while (1) 
			{
				srand(time(NULL));
				int check = 0;
				gItem.x = (rand() % 60) * 2;
				gItem.y = rand() % 30;
				for (int i = 0; i < snakeLen; i++) {
					if (x[i] == gItem.x && y[i] == gItem.y) {
						check = 1;
						break;
					}
				}
				if (check == 0)
					break;
			}
		}

		for (int i = 1; i < snakeLen; i++) { //자기몸과의 충돌판정
			if (x[0] == x[i] && y[0] == y[i])
				gStatus = END;
		}
		system("cls");
		for (int i = 1; i < snakeLen; i++) {
			gotoxy(x[i], y[i]);
			printf("■");
		}
		gotoxy(x[0],y[0]);
		printf("□");
		gotoxy(gItem.x,gItem.y);
		printf("ⓤ");
		while (1)
		{
			curTime = clock();
			if (curTime - oldTime > 120-(snakeLen/3)) {
				oldTime = curTime;
				break;
			}
		}
	}
	end(snakeLen);
	
    return 0;
}


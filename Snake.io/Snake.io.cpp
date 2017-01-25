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
	printf("                                                         하 : 2                                                        \n");
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
}

int main()
{
	//120*100
	int x[60];
	int y[30];

	char nKey;

	clock_t curTime, oldTime;
	oldTime = clock();

	startIntro();
	gStatus = RUNNING;
	for (int i = 0; i < 60; i++)
		x[i] = -10;
	for (int i = 0; i < 30; i++)
		y[i] = -10;

	x[0] = 30;
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

			case '2': //아래
				gDirection = DOWN;
				break;
			}
		}
		switch (gDirection)
		{
		case UP :
			y[0]--;
			if (y[0] < 0)
				y[0] = 29;
			break;
		case LEFT :
			x[0]--;
			x[0]--;
			if (x[0] < 0)
				x[0] = 118;
			break;
		case RIGHT :
			x[0]++;
			x[0]++;
			if (x[0] > 118)
				x[0] = 0;
			break;
		case DOWN :
			y[0]++;
			if (y[0] > 29)
				y[0] = 0;
			break;
		}
		system("cls");
		gotoxy(x[0], y[0]);
		printf("■");
		while (1)
		{
			curTime = clock();
			if (curTime - oldTime > 100) {
				oldTime = curTime;
				break;
			}
		}
	}
    return 0;
}


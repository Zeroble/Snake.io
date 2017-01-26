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
}

int main()
{
	//120*100
	int x[180];
	int y[180];
	int snakeLen = 1;

	char nKey;

	clock_t curTime, oldTime;
	oldTime = clock();

	startIntro();
	_getch();
	gStatus = RUNNING;

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

			case '5': //아래
				gDirection = DOWN;
				break;
			}
		}
		for (int i = snakeLen - 1; i > 0; i--) {
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
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
		if (x[0] == gItem.x && y[0] == gItem.y) {
			snakeLen++;
			gItemoo = OFF;
		}
		if (gItemoo == OFF) {
			gItemoo = ON;
			srand(time(NULL));
			gItem.x = (rand() % 60)*2;
			gItem.y = rand() % 30;
		}

		system("cls");
		for (int i = 0; i < snakeLen; i++) {
			gotoxy(x[i], y[i]);
			printf("■");
		}
		gotoxy(gItem.x,gItem.y);
		printf("ⓤ");
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


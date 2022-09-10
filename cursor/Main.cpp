#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"Winmm.lib")
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <random>
#include "Header.h"
#include <chrono>
#include <fstream>
// 22.02.2022
using namespace std;
void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int weight = 120;
int height = 50;
int g=0;
char s[3] = { 32,32,32 };
char w[3] = { 32,32,32 };
char n[3] = { 32,32,32 };
int color=15;
int l = 0;
bool restarting = false;
bool click = false;
unsigned int start_time = 0;

void cls(HANDLE hConsole)
{
	COORD coordScreen = { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer. 

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
		return;
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.

	if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ',
		dwConSize, coordScreen, &cCharsWritten))
		return;

	// Get the current text attribute.

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
		return;

	// Set the buffer's attributes accordingly.

	if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten))
		return;

	// Put the cursor at its home coordinates.

	SetConsoleCursorPosition(hConsole, coordScreen);
}

COORD makeCoord(int x, int y) {
	COORD coord = { (short)x,(short)y };
	return coord;
}
BOOL ShowConsoleCursor(BOOL bShow)
{
	CONSOLE_CURSOR_INFO cci;
	HANDLE hiStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hiStdOut == INVALID_HANDLE_VALUE)
		return FALSE;
	if (!GetConsoleCursorInfo(hiStdOut, &cci))
		return FALSE;
	cci.bVisible = bShow;
	if (!SetConsoleCursorInfo(hiStdOut, &cci))
		return FALSE;
	return TRUE;
}
int main()
{
	
	ofstream out("hello.txt", ios::app);
	string name;
	ifstream fin;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> EnemyY((weight-115), (weight - 5));
	uniform_int_distribution<> EnemyX((height-45), (height - 5));
	int xEnemy, yEnemy;
	int x = 10, y = 5;
	int upT = 0, upS = 0;
	int downT = 0, downS = 0;
	int rightT = 0, rightS = 0;
	int leftT = 0, leftS = 0;

	bool Tshoot;
	Tshoot = false;
	xEnemy = EnemyX(gen);
	yEnemy = EnemyY(gen);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size;
	size.X = weight;
	size.Y = height;
	int xShoot, yShoot, xShootx, yShooty;
	int index = 0;
	int n = (10 + rand() % 40);
	BOOL resize = SetConsoleScreenBufferSize(hStdout, size);
	SetPos(0, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	int score = 0;
	
	bool bMenu = true;

	
	system("mode con cols=226 lines=77");
	menu();
	
	restart:
	if (g==1) {
		system("mode con cols=226 lines=77");
		system("cls");
		start_time = clock();
		while (true) {
			
			ShowConsoleCursor(FALSE);
			for (int i = 0; i < weight; i++) {
				for (int j = 0; j < height; j++) {
					xShoot = x;
					yShoot = y;
					map(i, j, hStdout);
					tank(i, j, x, y, hStdout);
					enemy(i, j, xEnemy, yEnemy, hStdout);
					
				

				}
				cout << endl;
			}

			for (int i = 0; i < weight; i++) {
				for (int j = 0; j < height; j++) {
					
					if (i == yShoot && j == xShoot) {
						xShootx = xShoot;
						yShooty = yShoot;
						if (upS == 1) {
							int k = 3;
							index = 2;
							
							while (Tshoot == true) {
								
								SetPos(i+1, j-k);
								

								cout << char(253);
								SetPos(i + 1, j - k);



								Sleep(10);
								cout << " ";
								k++;
								//xShootx = k;
								xShootx--;
								
								if (k == (0 + (xShoot + 1))) {
									Tshoot = false;
									
									system("cls");

								}else if (xShootx == (xEnemy+2) && (yShooty == (yEnemy) || yShooty == (yEnemy + 1) || yShooty == (yEnemy-1))) {
									Tshoot = false;
									PlaySound("kill.wav", NULL, SND_ASYNC);
									system("cls");
									xEnemy = EnemyX(gen);
									yEnemy = EnemyY(gen);
									enemy(i, j, xEnemy, yEnemy, hStdout);
									l++;
									score++;
								}
								

							}

						}

					}

					if (i == yShoot && j == xShoot) {
						xShootx = xShoot;
						yShooty = yShoot;
						if (downS==1) {
							int k = 3;
							index = 2;

							while (Tshoot == true) {
								SetPos(i + 1, j + k);

								cout << char(253);
								SetPos(i + 1, j + k);

								

								Sleep(10);
								cout << " ";
								k++;
								xShootx++;
								index++;
								if (k == (height - (xShoot + 1))) {
									Tshoot = false;
									
									break;

								}
								else if (xShootx == (xEnemy -2) && (yShooty == (yEnemy) || yShooty == (yEnemy + 1) || yShooty == (yEnemy - 1))) {
									Tshoot = false;
									PlaySound("kill.wav", NULL, SND_ASYNC);
									system("cls");
									xEnemy = EnemyX(gen);
									yEnemy = EnemyY(gen);
									enemy(i, j, xEnemy, yEnemy, hStdout);
									score++;
									l++;
								}
								
							}
						}

					}
					if (leftS == 1) {
						xShootx = xShoot;
						yShooty = yShoot;
						if (i == yShoot && j == xShoot) {
							int k = 3;
							index = 2;

							while (Tshoot == true) {
								SetPos(i -k, j);

								cout << char(253);
								SetPos(i - k, j);



								Sleep(10);
								cout << " ";
								k++;
								index++;
								yShooty--;
								if (k == (0 + (yShoot + 1))) {
									Tshoot = false;
									
									break;

								}
								else if (yShooty == (yEnemy +2) && (xShootx == (xEnemy) || xShootx == (xEnemy + 1) || xShootx == (xEnemy - 1))) {
									Tshoot = false;
									PlaySound("kill.wav", NULL, SND_ASYNC);
									system("cls");
									xEnemy = EnemyX(gen);
									yEnemy = EnemyY(gen);
									enemy(i, j, xEnemy, yEnemy, hStdout);
									score++;
									l++;
								}
								
							}
						}

					}
					if (rightS == 1) {
						xShootx = xShoot;
						yShooty = yShoot;
						if (i == yShoot && j == xShoot) {
							int k = 3;
							index = 2;

							while (Tshoot == true) {
								SetPos(i + k, j);

								cout << char(253);
								SetPos(i + k, j);



								Sleep(10);
								cout << " ";
								k++;
								index++;
								yShooty++;
								if (k == (weight - (yShoot + 1))) {
									Tshoot = false;
									
									system("cls");

								}
								else if (yShooty == (yEnemy -2) && (xShootx == (xEnemy) || xShootx == (xEnemy + 1) || xShootx == (xEnemy - 1))) {
									Tshoot = false;
									PlaySound("kill.wav", NULL, SND_ASYNC);
									system("cls");
									xEnemy = EnemyX(gen);
									yEnemy = EnemyY(gen);
									enemy(i, j, xEnemy, yEnemy, hStdout);
									score++;
									l++;
								}
								
							}
						}

					}
				}
			}
			
			scoreT(score);
					
					
				
			
			if ((x == xEnemy || x == (xEnemy + 1) || x == (xEnemy - 1)) && y == (yEnemy - 2)) { y--; }
			if ((x == xEnemy || x == (xEnemy + 1) || x == (xEnemy - 1)) && y == (yEnemy + 2)) { y++; }
			if (x == (xEnemy - 2) && (y == yEnemy || y == (yEnemy + 1) || y == (yEnemy - 1))) { x--; }
			if (x == (xEnemy + 2) && (y == yEnemy || y == (yEnemy + 1) || y == (yEnemy - 1))) { x++; }

			/*if ((x == xEnemy + n || x == (xEnemy + (n + 1)) || x == (xEnemy + (n - 1))) && y == (yEnemy + (n - 2))) { y--; }
			if ((x == xEnemy + n || x == (xEnemy + (n + 1)) || x == (xEnemy + (n - 1))) && y == (yEnemy + (n + 2))) { y++; }
			if (x == (xEnemy + (n - 2)) && (y == yEnemy + n || y == (yEnemy + (n + 1)) || y == (yEnemy + (n - 1)))) { x--; }
			if (x == (xEnemy + (n + 2)) && (y == yEnemy + n || y == (yEnemy + (n + 1)) || y == (yEnemy + (n - 1)))) { x++; }*/
			
			if (x == 1) { x++; }
			else if (y == (weight - 3)) { y--; }
			else if (x == (height - 2)) { x--; }
			else if (y == 0) { y++; }
			if (_kbhit()) { //keylog

				switch (_getch()) // ждёт нажатия на клаву без Enter после этого
				{
				case 72: //вверх
					x--;
					upT = 1;
					upS = 1; rightS = 0; downS = 0; leftS = 0;
					location(upT, downT, rightT, leftT);
					upT = 0;
					cls(hStdout);
					break;
				case 80: //вниз
					x++;
					downT = 1;
					upS = 0; rightS = 0; downS = 1; leftS = 0;
					location(upT, downT, rightT, leftT);
					downT = 0;
					cls(hStdout);
					break;

				case 75: //влево 
					y--;
					leftT = 1;
					upS = 0; rightS = 0; downS = 0; leftS = 1;
					location(upT, downT, rightT, leftT);
					leftT = 0;
					cls(hStdout);
					break;
				case 77: //вправо
					y++;
					rightT = 1;
					upS = 0; rightS = 1; downS = 0; leftS = 0;
					location(upT, downT, rightT, leftT);
					rightT = 0;
					cls(hStdout);
					break;

				case 32:
					Tshoot = true;
					PlaySound("Sound_00375 (mp3cut.net).wav", NULL, SND_ASYNC);
					break;
				case 27:
					exit(0);
					break;
				}

			}//end key log
			
			unsigned int end_time = clock();
			if (((end_time - start_time) / 1024) == 60) {
				g = 0;
				
				
				
				timeout(score);
				if (restarting == true) {
					
					goto restart;
				}
				if (click) {
					statP(fin);
					break;
				}
				else { 
					
					return 0; 
				}
				
				
			}
			
		}
		
		fflush(stdout);
	}
	
	out.close();
	fin.close();
}


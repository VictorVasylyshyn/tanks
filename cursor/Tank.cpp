#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Header.h"
#include <chrono>
using namespace std;


void tank(int i, int j, int x, int y, HANDLE hStdout) {
	
	if (j == x - 1 && i == y) {
		SetPos(i, j);
		

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		for (int k = 0; k < 3; k++) {
			cout << w[k];
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);

	}
	else if (j == x && i == y) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
		SetPos(i, j);
		for (int k = 0; k < 3; k++) {
			cout << s[k];

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);

	}
	else if (j == x + 1 && i == y) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		SetPos(i, j);
		for (int k = 0; k < 3; k++) {
			cout << n[k];
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	}
	
}


void enemy(int i, int j, int xEnemy, int yEnemy, HANDLE hStdout) {
	char wE[3] = { 201,210 , 187 };
	char sE[3] = { 198,206 ,181 };
	char nE[3] = { 200,208 ,188 };

	if (j == xEnemy - 1 && i == yEnemy) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		SetPos(i, j);
		for (int k = 0; k < 3; k++) {
			cout << wE[k];
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	}
	if (j == xEnemy && i == yEnemy) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		SetPos(i, j);
		for (int k = 0; k < 3; k++) {
			cout << sE[k];
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	}
	if (j == xEnemy + 1 && i == yEnemy) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		SetPos(i, j);
		for (int k = 0; k < 3; k++) {
			cout << nE[k];
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	}

}
		
	

	


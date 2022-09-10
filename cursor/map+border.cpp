#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Header.h"
using namespace std;



void map(int i, int j, HANDLE hStdout) {
	if (j == (height - 1) || j == 0) {
		SetPos(i, j);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x55);
		cout << char(196);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	}

	else if (i == (weight - 1) || i == 0) {
		SetPos(i, j);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x55);
		cout << char(179);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	}


}



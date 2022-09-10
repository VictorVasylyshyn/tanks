#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "Header.h"
using namespace std;
	
	
void menu() {
	bool COLORS = false;
	int k = 15;
	int COLOREXIT = 15, COLORSTART = 15, COLORSETTING = 15, COLORTANK = 15,COLORYEL=15,COLORGRE=15,COLORBLU=15,COLORRED=15;
	const char* MENU[]{
	" ##    ###   ###   #######   ###  ###   ##    ##    ## ",
	"   ##  ###   ###   ##        #### ###   ##    ##  ##   ",
	"###### ## ### ##   ######    ##  ####   ##    ## ######",
	"   ##  ##  #  ##   ##        ##   ###   ##    ##  ##   ",
	" ##    ##     ##   #######   ##    ##    ######     ## ",
	};
	const char* TANK[]{
		"##    ##    ##",
		"##    ##    ##",
		"##  ######  ##",
		"#####    #####",
		"#####    #####",
		"##  ######  ##",
		"##          ##",
		"##          ##",
	};
	const char* SETTING[]{
	" ######   #######   ########  ########  ########  ###   ##   ###### ",
	"##        ##           ##        ##        ##     ####  ##  ##      ",
	" ######   #####        ##        ##        ##     ## #####  ##   ###",
	"      ##  ##           ##        ##        ##     ##   ###  ##    ##",
	" ######   #######      ##        ##     ########  ##    ##   ###### ",
	};
	const char* START[]{
		" ######   ########   #####   #######   ########      ######    ######   ###   ### #######",
		"##           ##     ##   ##  ##    ##     ##        ##        ##    ##  ###   ### ##     ",
		" ######      ##     #######  #######      ##        ##   ###  ########  ## ### ## ###### ",
		"      ##     ##     ##   ##  ##    ##     ##        ##    ##  ##    ##  ##  #  ## ##     ",
		" ######      ##     ##   ##  ##    ##     ##         ######   ##    ##  ##     ## #######",
	};
	const char* EXIT[]{
		"#######   ###  ###   ########  ########      ######    ######   ###   ### #######",
		"##         #####        ##        ##        ##        ##    ##  ###   ### ##     ",
		"#######     ###         ##        ##        ##   ###  ########  ## ### ## ###### ",
		"##         #####        ##        ##        ##    ##  ##    ##  ##  #  ## ##     ",
		"#######   ###  ###   ########     ##         ######   ##    ##  ##     ## #######",

	};
	const char* COLOR[][5]{
		{
"###  ###   #####   ##        ##         #####    ##     ## ",
" ######    ##      ##        ##        ##   ##   ##     ## ",
"   ##      ####    ##        ##        ##   ##   ## ##  ## ",
"   ##      ##      ##        ##        ##   ##   ######### ",
"   ##      #####   #######   #######    #####     ### ###  ",
},
		{
"      ######   #######   #######   #######   ###  ###      ",
"     ##        ##    ##  ##        ##        #### ###      ",
"     ##   ###  #######   ######    ######    ##  ####      ",
"     ##    ##  ##    ##  ##        ##        ##    ##      ",
"      ######   ##    ##  #######   #######   ##    ##      ",

		},
		{
"           #######   ##        ##    ##  #######           ",
"           ##    ##  ##        ##    ##  ##                "  ,
"           #######   ##        ##    ##  ######            ",
"           ##    ##  ##        ##    ##  ##                "  ,
"           #######   ########   ######   #######           ",
},
		{
"               #######    #######   #######                ",
"               ##    ##   ##        ##    ##               ",
"               ######     ######    ##    ##               ",
"               ##    ##   ##        ##    ##               ",
"               ##    ##   #######   #######                ",
		},
	};
	POINT p;
	
	
	while (g != 1) {
		GetCursorPos(&p);
		for (int i = 0; i < 5; i++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
			SetPos(92, 1 + i);
			cout << MENU[i];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
		}
		for (int i = 0; i < 5; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLORSTART);
			SetPos(75, 10 + i);
			cout << START[i];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		for (int i = 0; i < 5; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLORSETTING);
			SetPos(85, 20 + i);
			cout << SETTING[i];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		for (int i = 0; i < 5; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOREXIT);
			SetPos(80, 30 + i);
			cout << EXIT[i];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (p.x >= 458 && p.x <= 988 && p.y >= 119 && p.y <= 155) {
			COLORSTART = 6;
		}
		else { COLORSTART = 15; }
		if (p.x >= 518 && p.x <= 921 && p.y >= 207 && p.y <= 256) {
			COLORSETTING = 6;
		}
		else { COLORSETTING = 15; }
		if (p.x >= 488 && p.x <= 969 && p.y >= 298 && p.y <= 333) {
			COLOREXIT = 6;
		}
		else { COLOREXIT = 15; }

		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (p.x >= 458 && p.x <= 988 && p.y >= 119 && p.y <= 155) {
				g = 1;
			}
			if (p.x >= 488 && p.x <= 969 && p.y >= 298 && p.y <= 333) {
				return;
			}
			if (p.x >= 518 && p.x <= 921 && p.y >= 207 && p.y <= 256) {
				system("cls");
				COLORS = true;
				}
				
			while (COLORS==true) {
				k = 15;
				for (int i = 0; i < 8; i++) {
					SetPos(97, 4 + i);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLORTANK);
					cout << TANK[i];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				for (int i = 0; i < 4; i++) {
					if (i==0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLORYEL);
					}
					else if (i == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLORGRE);
					}
					else if (i == 2) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLORBLU);
					}
					else if (i == 3) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLORRED);
					}
				
					for (int j = 0; j < 5; j++) {
						SetPos(75, k + (j + 1));
						cout << COLOR[i][j];

					}

					k += 10;
				}
				GetCursorPos(&p);
				if (p.x >= 458 && p.x <= 802 && p.y >= 171 && p.y <= 209) {
					COLORYEL = 14;
					COLORTANK = 14;
				}
				else { COLORYEL = 15; COLORTANK = 15; }
				if (p.x >= 490 && p.x <= 772 && p.y >= 261 && p.y <= 298) {
					COLORGRE = 2;
					COLORTANK = 2;
				}
				else { COLORGRE = 15; }
				if (p.x >= 525 && p.x <= 741 && p.y >= 351 && p.y <= 388) {
					COLORBLU = 1;
					COLORTANK = 1;
				
				}
				else { COLORBLU = 15; }
				if (p.x >= 549 && p.x <= 716 && p.y >= 441 && p.y <= 478) {
					COLORRED = 4;
					COLORTANK = 4;
				}
				else { COLORRED = 15; }
				if (GetAsyncKeyState(VK_LBUTTON)) {
					if (p.x >= 458 && p.x <= 802 && p.y >= 171 && p.y <= 209) { color = 14; COLORS = false;system("cls");}
					if (p.x >= 490 && p.x <= 772 && p.y >= 261 && p.y <= 298) { color = 2; COLORS = false;system("cls") ;}
					if (p.x >= 525 && p.x <= 741 && p.y >= 351 && p.y <= 388) { color = 1; COLORS = false;system("cls") ;}
					if (p.x >= 549 && p.x <= 716 && p.y >= 441 && p.y <= 478) { color = 4; COLORS = false;system("cls") ;}
				}
				
			}
		}
	}

	
}

void timeout(int score) {
	system("cls");
	int colorE = 15,colorR=15;
	const char* timeo[]{
	"############   ########   ###   ###   ########            #########     ##      ##   ############",
	"     ##           ##      #### ####   ##                ###       ###   ##      ##        ##     ",
	"     ##           ##      ## ### ##   ##                ###       ###   ##      ##        ##     ",
	"     ##           ##      ##  #  ##   ########          ###       ###   ##      ##        ##     ",
	"     ##           ##      ##     ##   ##                ###       ###   ##      ##        ##     ",
	"     ##           ##      ##     ##   ##                ###       ###   ##      ##        ##     " ,
	"     ##        ########   ##     ##   ########            #########      ########         ##     ",

	};
	const char* Score[]{
   "###  ###     ######     ##    ##    ######         ######     #####      ######     ######      #######     ",
   " ##  ##     ##    ##    ##    ##    ##    ##      ##         ##   ##    ##    ##    ##    ##    ##       ## ",
   "   ##       ##    ##    ##    ##    ##    ##      ##         ##   ##    ##    ##    ##    ##    ##       ## ",
   "   ##       ##    ##    ##    ##    #######        #####     ##         ##    ##    #######     #######     ",
   "   ##       ##    ##    ##    ##    ##    ##           ##    ##   ##    ##    ##    ##    ##    ##       ## ",
   "   ##       ##    ##    ##    ##    ##    ##           ##    ##   ##    ##    ##    ##    ##    ##       ## ",
   "   ##        ######      ######     ##    ##      ######      #####      ######     ##    ##    #######     ",


	};
	const char* restart[]{
	"######   ######    #####   ########   #####   ######   ########",
	"##   ##  ##       ##          ##     ##   ##  ##   ##     ##",
	"######   ######    #####      ##     #######  ######      ##",
	"##   ##  ##            ##     ##     ##   ##  ##   ##     ##",
	"##   ##  ######    #####      ##     ##   ##  ##   ##     ##",
	};
	const char* EXIT[]{
		"#######   ###  ###   ########  ########      ######    ######   ###   ### #######",
        "##         #####        ##        ##        ##        ##    ##  ###   ### ##     ",
        "#######     ###         ##        ##        ##   ###  ########  ## ### ## ###### ",
        "##         #####        ##        ##        ##    ##  ##    ##  ##  #  ## ##     ",
        "#######   ###  ###   ########     ##         ######   ##    ##  ##     ## #######",

	};
	for (int i = 0; i < 7; i++)
	{
		SetPos(64, 15+i);
		for (int j = 0; j < 98; j++)
		{
			cout << timeo[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < 7; i++)
	{
		SetPos(48, 25 + i);
		for (int j = 0; j < 109; j++)
		{
			cout << Score[i][j];
		}
		cout << endl;
	}

	for (int q = 0; q < 7; q++) {
		
		SetPos(158,24+(q+1));
		
		for (int v = 0; v < 10; v++) {

			if (score < 10) {
				
				cout << A[l][q][v];
				

			}
			else if (score < 20) {
				
				SetPos(158 + v,24+ (q + 1));
				cout << A[1][q][v];
				SetPos(168 + v, 24+(q + 1));
				cout << A[l][q][v];
				
			}
			else if (score < 30) {
				
				SetPos(158 + v, 24+(q + 1));
				cout << A[2][q][v];
				SetPos(168 + v , 24+(q + 1));
				cout << A[l][q][v];
			
			}
			else if (score < 40) {
				
				SetPos(158 + v,24+ (q + 1));
				cout << A[3][q][v];
				SetPos((168 + v),24+ (q + 1));
				cout << A[l][q][v];
				
			}
		
		}
		cout << endl;

	}
	cout << endl;


	POINT p;
	while (g != 1) {
		for (int i = 0; i < 5; i++) {
			SetPos(20, 45 + (i + 1));
			for (int j = 0; j < 64; j++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorR);
				cout << restart[i][j];
			}

			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		for (int i = 0; i < 5; i++) {
			SetPos(116, 45 + (i + 1));
			for (int j = 0; j < 82; j++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorE);
				cout << EXIT[i][j];
			}
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		GetCursorPos(&p);
		if (p.x >= 705 && p.x <= 1184 && p.y >= 435 && p.y <= 480) {
			colorE = 14;
		}
		else{ colorE = 15; }
			if (p.x >=129 && p.x <= 505 && p.y >= 435 && p.y <= 480) {
				colorR = 12;
			}
		else { colorR = 15; }

		
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (p.x >= 705 && p.x <= 1184 && p.y >= 435 && p.y <= 480) {
				g = 1;
				restarting = false;
				
			}
			 if(p.x >= 129 && p.x <= 505 && p.y >= 435 && p.y <= 480){
				 g = 1;
				 score = 0;
				 l = 0;
				 start_time = 0;
				 restarting = true;
			}
		}
	}
	
	
	
	
}


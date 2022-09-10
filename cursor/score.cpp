#include <iostream>
#include "Header.h"
using namespace std;

char A[10][7][10] = {
	  { " ###### ", "##    ##","##    ##","##    ##","##    ##", "##    ##", " ######", },//0
	  { "      ##","   ## ##"," ##   ##","      ##","      ##","      ##","      ##",  },//1
	  { " ######", "       #","       #"," ######", "#      ","#      ", " ######", },//2
	  {"####### ","      ##","      ##","#######","      ##","      ##","#######", },//3
	  { "##    ##",  "##    ##","##    ##", "########", "      ##", "      ##", "      ##", },//4
	  { " ######", "#      ","#      "," ######", "       #", "       #", " ######",}, //5
	  {" ######","#      ","#      "," ######","#      #", "#      #"," ######",},//6
	  { "#######", "      #","     # ","    #  ", "   #   ","  #    ", " #     ",},//7
	  {" ###### ","#      #", "#      #"," ######","#      #","#      #"," ######",},//8
	  {" ###### ","#      #", "#      #"," ######", "       #","       #", " ######",},//9
};

const char* syst[]{
   " ######      #####      ######     ######      #######     ",
   "##          ##   ##    ##    ##    ##    ##    ##       ## ",
   "##          ##   ##    ##    ##    ##    ##    ##       ## ",
   " #####      ##         ##    ##    #######     #######     ",
   "      ##    ##   ##    ##    ##    ##    ##    ##       ## ",
   "      ##    ##   ##    ##    ##    ##    ##    ##       ## ",
   " ######      #####      ######     ##    ##    #######     ",
};
void scoreT(int score)
{

	for (int q = 0; q < 7; q++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
		SetPos(125, (q + 1));
		cout << syst[q] << "   ";
		for (int v = 0; v < 10; v++) {

			if (score < 10) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
				cout << A[l][q][v];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);

			}
			else if (score < 20) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
				SetPos(125 + (v + 65), (q + 1));
				cout << A[1][q][v];
				SetPos((125 + (v + 75)),  (q + 1));
				cout << A[l][q][v];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			}
			else if (score < 30) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0D);
				SetPos(125 + (v + 65), (q + 1));
				cout << A[2][q][v];
				SetPos((125 + (v + 75)), (q + 1));
				cout << A[l][q][v];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			}
			else if (score < 40) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
				SetPos(125 + (v + 65), (q + 1));
				cout << A[3][q][v];
				SetPos((125 + (v + 75)), (q + 1));
				cout << A[l][q][v];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
		}
		cout << endl;

	}
	cout << endl;
	if (l == 10) {
		l = 0;
	}
}
               

       


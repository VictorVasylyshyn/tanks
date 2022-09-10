#pragma once
#include <Windows.h>
#define RED RGB(255,0,0)
#define GRN RGB(0,255,0)
#define BLU RGB(0,0,255)
#define YEL RGB(249,215,28)
#define BLK RGB(0,0,0)
#define WHT RGB(255,255,255)
extern char w[3];
extern char s[3];
extern char n[3];
extern const char* syst[];
extern char A[10][7][10];
extern int height;
extern int weight;
extern int l;
extern int g;
extern int color;
extern bool restarting;
extern bool click;
extern unsigned int start_time;
void map(int, int, HANDLE);
void tank(int, int, int, int, HANDLE);
void location(int, int, int, int);
void enemy(int, int, int, int, HANDLE);
void shootT(int, int, int, int, HANDLE,bool,int,int,int,int,int);
COORD makeCoord(int x, int y);
void DrawMenu(HDC hDC, RECT pRECT, int iSEL, int iTITLE);
void DrawSettings(HDC hDC, RECT pRECT, int iSEL, int iTITLE);
void menu();
void SetPos(int x, int y);
void scoreT(int);
void timeout(int);
void stat(std::string, int, std::ofstream&out);
void statP(std::ifstream& fin);
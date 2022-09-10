#include <iostream>
#include <fstream>
#include "Header.h"
#include <algorithm>
using namespace std;
void stat(string name, int score, ofstream &out) {
	int x=0, y=60;
	SetPos(x, y);
	cout << "Enter name: ";
	cin >> name;
	pair<int, string>arr(score, name);
	out << arr.second << "\t\t" <<  arr.first << "\n";
	
}

void statP(ifstream&fin) {
	fin.open("hello.txt");
	char ch;
	
	while (fin.get(ch)) {
		cout << ch;
	}
}
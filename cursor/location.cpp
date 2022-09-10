#include <iostream>
#include "Header.h"
using namespace std;



void location(int upT, int downT, int rightT, int leftT) {
	if (upT == 1) {
		for (int k = 0; k < 3; k++) {
			if (k == 0) {
				w[k] = 186;
				s[k] = 204;
				n[k] = 186;
			}
			if (k == 1) {
				w[k] = 179;
				s[k] = 178;
				n[k] = 32;
			}
			if (k == 2) {
				w[k] = 186;
				s[k] = 185;
				n[k] = 186;
			}
		}
	}
	if (downT == 1) {
		for (int k = 0; k < 3; k++) {
			if (k == 0) {
				w[k] = 186;
				s[k] = 204;
				n[k] = 186;
			}
			if (k == 1) {
				w[k] = 32;
				s[k] = 178;
				n[k] = 179;
			}
			if (k == 2) {
				w[k] = 186;
				s[k] = 185;
				n[k] = 186;
			}
		}
	}
	if (rightT == 1) {
		for (int k = 0; k < 3; k++) {
			if (k == 0) {
				w[k] = 205;
				s[k] = 32;
				n[k] = 205;
			}
			if (k == 1) {
				w[k] = 203;
				s[k] = 178;
				n[k] = 202;
			}
			if (k == 2) {
				w[k] = 205;
				s[k] = 196;
				n[k] = 205;
			}
		}
	}
	if (leftT == 1) {
		for (int k = 0; k < 3; k++) {
			if (k == 0) {
				w[k] = 205;
				s[k] = 196;
				n[k] = 205;
			}
			if (k == 1) {
				w[k] = 203;
				s[k] = 178;
				n[k] = 202;
			}
			if (k == 2) {
				w[k] = 205;
				s[k] = 32;
				n[k] = 205;
			}
		}
	}
}
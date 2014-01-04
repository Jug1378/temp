#include "stdafx.h"
#include <iostream>
using namespace std;

int countHanoiMoves(int n);

int main() {
	cout << "Please the number of disks: ";
	int n;
	cin >> n;
	cout << "The number of moves is: " << countHanoiMoves(n) << endl;
	system("pause");
	return 0;
}

int countHanoiMoves(int n) {
	if (n == 0) return 0;
	else return 2 * countHanoiMoves(n - 1) + 1;
}
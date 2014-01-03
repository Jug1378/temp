#include "stdafx.h"
#include <iostream>
using namespace std;

int digitSum(int n);
int digitRoot(int n);
int pascaltri(int n, int k);

int main() {
	cout << "Please enter the number?" << endl;
	int n;
	cin >> n;
	cout << "The sum of digits is " << digitSum(n) << endl;
	cout << "The digit root is " << digitRoot(n) << endl;
	cout << "Calculate c(6, 2): " << pascaltri(6, 2) << endl;
	system("pause");
	return 0;
}

int digitSum(int n) {
	if (n / 10 == 0) return n % 10;
	else return n % 10 + digitSum(n / 10);
}

int digitRoot(int n) {
	if (n / 10 == 0) return n;
	else return digitRoot(digitSum(n));
}

int pascaltri(int n, int k) {
	if ((k == 0) || (n == k)) return 1;
	else return pascaltri(n - 1, k - 1) + pascaltri(n - 1, k);
}
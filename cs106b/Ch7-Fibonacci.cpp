// Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int MIN_INDEX = 0;
const int MAX_INDEX = 20;

int fib(int n);
int fib2(int n);
int additiveSequence(int n, int a, int b);

int main() {
	cout << "This program list the Fibonacci sequence." << endl;
	for (int i = MIN_INDEX; i <= MAX_INDEX; i++) {
		if (i < 10) cout << " ";
		cout << "fib(" << i << ")";
		cout << " = " << setw(4) << fib2(i) << endl;
	}
	system("pause");
	return 0;
}

int fib(int n) {
	if (n < 2) {
		return n;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

int fib2(int n) {
	return additiveSequence(n, 0, 1);
}

int additiveSequence(int n, int a, int b) {
	if (n == 0) return a;
	if (n == 1) return b;
	return additiveSequence(n - 1, b, a + b);
}
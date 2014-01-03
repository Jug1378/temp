// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool isPrime(int n)
{
	if (n == 1) return false;
	else if (n == 2 && n == 3) return true;
	int root = sqrt(n);
	for (int i = 2; i < root; i++)
	{
		if (n % i == 0)	return false;
	}
	return true;
}

void getPrimeFactor(int n)
{
	int i = 2;
	while (n != 1)
	{
		if (isPrime(i) && (n % i == 0))
		{
			n /= i;
			cout << i;
			if (n != 1)
				cout << " x ";
			i--;
		}
		i++;
	}
	cout << endl;
}

int main()
{
	cout << "This program factors a number." << endl;
	cout << "Enter a number to be factored: ";
	int num;
	cin >> num;
	getPrimeFactor(num);
	system("pause");
	return 0;
}


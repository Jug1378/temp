#include "stdafx.h"
#include <iostream>
using namespace std;

double CalcPi(int n)
{
	int x = -1;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		x *= -1;
		sum += 1.0 / (2 * i + 1) * x;
	}
	return sum * 4;
}

int main()
{
	cout << "Aproximation of Pi" << endl;
	cout << CalcPi(10000) << endl;
	system("Pause");
	return 0;
}

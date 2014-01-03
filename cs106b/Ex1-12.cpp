#include "stdafx.h"
#include <iostream>
using namespace std;

double getPow(double i)
{
	return i * i;
}

double getPi(int n)
{
	double i = 2.0 / n;
	double x = i / 2;
	double sum = 0;
	while (x < 2.0)
	{
		sum += sqrt(4 - getPow(x)) * i;
		x += i;
	}
	return sum;
}

//int main()
//{
//	cout << "Aproximation of Pi" << endl;
//	cout << getPi(10000) << endl;
//	system("Pause");
//	return 0;
//}
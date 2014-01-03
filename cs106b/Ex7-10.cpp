#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void reverse(string &str);
void subreverse(string &str, int p1, int p2);

int main() {
	cout << "Please enter the string to be reversed?" << endl;
	string str;
	cin >> str;
	reverse(str);
	cout << str << endl;
	system("pause");
	return 0;
}

void reverse(string &str) {
	subreverse(str, 0, str.length() - 1);
}

void subreverse(string &str, int p1, int p2) {
	if (p1 >= p2) return;
	else{
		string s = str;
		str[p1] = s[p2];
		str[p2] = s[p1];
		subreverse(str, ++p1, --p2);
	}
}
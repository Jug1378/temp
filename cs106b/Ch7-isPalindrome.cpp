#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool isPalindrome(string str);
bool isPalindrome2(string str);
bool isSubstringPalindrome(string str, int p1, int p2);

int main() {
	cout << "Please enter a word to check?" << endl;
	string str;
	cin >> str;
	if (isPalindrome2(str)) cout << "It is!" << endl;
	else cout << "It is not!" << endl;
	system("pause");
	return 0;
}

bool isPalindrome(string str) {
	int len = str.length();
	if (len < 2) return true;
	else return (str[0] == str[len - 1]) && isPalindrome(str.substr(1, len - 2));
}

bool isPalindrome2(string str) {
	return isSubstringPalindrome(str, 0, str.length() - 1);
}

bool isSubstringPalindrome(string str, int p1, int p2) {
	if (p1 >= p2) return true;
	else return (str[p1] == str[p2]) && isSubstringPalindrome(str, ++p1, --p2);
}
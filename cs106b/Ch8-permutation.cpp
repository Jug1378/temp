#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> generatePermutations(string str);

int main() {
	set<string> strs;
	string str;
	cout << "Enter a string: ";
	cin >> str;
	strs = generatePermutations(str);
	for each (string s in strs)
	{
		cout << "\"" << s << "\"" << endl;
	}
	system("pause");
	return 0;
}

set<string> generatePermutations(string str) {
	set<string> result;
	if (str == "") result.insert("");
	else {
		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			string rest = str.substr(0, i) + str.substr(i + 1);
			for each (string s in generatePermutations(rest))
			{
				result.insert(ch + s);
			}
		}
	}
	return result;
}
#include "stdafx.h"
#include "set.h"
#include <iostream>
using namespace std;

int countSubsetSumWays(Set<int> &set, int target);

int main() {
	Set<int> set;
	int element;
	int target;
	cout << "Please enter the integer element: ";
	while (true) {
		cin >> element;
		if (element == 0) {
			cout << "Please enter the target number: ";
			cin >> target;
			cout << "The number of ways is : " << countSubsetSumWays(set, target) << endl;
			break;
		}
		else set.insert(element);
	}
	system("pause");
	return 0;
}

int countSubsetSumWays(Set<int> &set, int target) {
	if (set.isEmpty()) return target == 0 ? 1 : 0;
	else{
		int i = set.first();
		Set<int> rest = set - i;
		return countSubsetSumWays(rest, target) + countSubsetSumWays(rest,target - i);
	}
}
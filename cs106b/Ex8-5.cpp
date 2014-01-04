#include "stdafx.h"
#include <iostream>
#include "vector.h"
using namespace std;

bool isMeasurable(int target, Vector<int> & weight);

int main() {
	Vector<int> vect;
	int element;
	int target;
	cout << "Please enter the integer element: ";
	while (true) {
		cin >> element;
		if (element == 0) {
			cout << "Please enter the target number: ";
			cin >> target;
			cout << "The number of ways is : " << isMeasurable(target, vect) << endl;
			break;
		}
		else vect.add(element);
	}
	system("pause");
	return 0;
}

bool isMeasurable(int target, Vector<int> & weight) {
	if (weight.isEmpty()) return target == 0;
	else {
		int i = weight[0];
		weight.remove(0);
		return isMeasurable(target, weight) || isMeasurable(target + i, weight) ||
			isMeasurable(target - i, weight);

	}
}
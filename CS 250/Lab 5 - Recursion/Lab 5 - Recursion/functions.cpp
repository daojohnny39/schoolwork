#include "functions.h"
#include <iostream>

using namespace std;

int power(int base, int exponent) {
	if (exponent == 0) {
		return 1;
	}
	else {
		return base * power(base, exponent - 1);
	}
}

int sum(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return n + sum(n - 1);
	}
}

void displaySequence(int start, int step, int stop) {
	if (stop <= 0) {
		return;
	}
	else {
		cout << start << " ";
		displaySequence(start + step, step, stop - 1);
	}
}

int sumTheDigits(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return n % 10 + sumTheDigits(n / 10);
	}
}
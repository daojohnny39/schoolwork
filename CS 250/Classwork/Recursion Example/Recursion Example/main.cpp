#include <iostream>

using namespace std;

void countdown(int startNum);
void countdownR(int startNum);
int fib(int term);

int main() {

	for (int i = 1; i <= 10; i++) {
		cout << fib(i) << " ";
	}

	return 0;
}

void countdown(int startNum) {
	for (int i = startNum; i > 0; i--) {
		cout << i << endl;
	}
}

void countdownR(int startNum) {
	if (startNum == 1) {
		cout << "1" << endl;
	}
	else {
		cout << startNum << endl;
		countdownR(startNum - 1);
	}
}

int fib(int term) {
	if (term == 1 || term == 2) {
		return (term - 1);
	}
	else {
		return (fib(term - 1) + fib(term - 2));
	}
}
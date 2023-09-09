#include <iostream>
#include "functions.h"
using namespace std;

int main() {

	cout << "***** TESTING POWER() *****" << endl;

	cout << "power(5,0) = " << power(5, 0)
		<< " [should be 1]" << endl;
	cout << "power(2,9) = " << power(2, 9)
		<< " [should be 512]" << endl;
	cout << "power(7,6) = " << power(7, 6)
		<< " [should be 117649]" << endl << endl;

	
	cout << "***** TESTING SUM() *****" << endl;

	cout << "sum(0) = " << sum(0)
		<< " [should be 0]" << endl;
	cout << "sum(17) = " << sum(17)
		<< " [should be 153]" << endl;
	cout << "sum(100) = " << sum(100)
		<< " [should be 5050]" << endl << endl;

	cout << "***** TESTING DISPLAYSEQUENCE() *****" << endl;

	cout << "displaySequence(1, 1, 0):" << endl;
	displaySequence(1, 1, 0);
	cout << endl << "[above should be blank]" << endl << endl;

	cout << "displaySequence(1, 1, 15):" << endl;
	displaySequence(1, 1, 15);
	cout << endl << "[above should be 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15]" << endl << endl;

	cout << "displaySequence(10, -2, 10):" << endl;
	displaySequence(10, -2, 10);
	cout << endl << "[above should be 10 8 6 4 2 0 -2 -4 -6 -8]" << endl << endl;

	cout << "***** TESTING SUMTHEDIGITS() *****" << endl;

	cout << "sumTheDigits(3) = " << sumTheDigits(3)
		<< " [should be 3]" << endl;
	cout << "sumTheDigits(3201) = " << sumTheDigits(3201)
		<< " [should be 6]" << endl;
	cout << "sumTheDigits(90160) = " << sumTheDigits(90160)
		<< " [should be 16]" << endl;
	cout << "sumTheDigits(1122334455) = " << sumTheDigits(1122334455)
		<< " [should be 30]" << endl;

	return 0; 
}

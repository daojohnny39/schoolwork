#ifndef FUNCTION_UTILITIES_HPP
#define FUNCTION_UTILITIES_HPP

/**
* Author: Johnny (Nhat) Dao
**/

#include <iostream>
#include <string>

using namespace std;

// FUNCTION DECLARATIONS
void divLine(string input, string funcDesc);
void subDivLine(string input);
void subDivLineEnd();
void actualOutput();
void expectedOutput();

// FUNCTION DEFINITIONS
void divLine(string input, string funcDesc) {

	for (int i = 0; i < 80; i++) {
		cout << "-";
	}

	cout << endl;

	for (int i = 0; i < input.size(); i++) {
		input[i] = toupper(input[i]);
	}

	cout << input << " - " << funcDesc << endl;

	for (int i = 0; i < 80; i++) {
		cout << "-";
	}
	cout << endl << endl;

}

void subDivLine(string input) {

	cout << endl;

	for (int i = 0; i < input.size(); i++) {
		input[i] = toupper(input[i]);
	}

	cout << input << endl;

	for (int i = 0; i < 80; i++) {
		cout << "-";
	}
	cout << endl << endl;

}

void subDivLineEnd() {

	cout << endl;

	for (int i = 0; i < 80; i++) {
		cout << "-";
	}
	cout << endl << endl;

}

void actualOutput() {
	cout << "ACTUAL OUTPUT:" << endl;
	for (int i = 0; i < 50; i++) {
		cout << "-";
	}
	cout << endl;
}

void expectedOutput() {
	cout << endl;
	cout << "EXPECTED OUTPUT:" << endl;
	for (int i = 0; i < 50; i++) {
		cout << "-";
	}
	cout << endl;
}

#endif // !FUNCTION_UTILITIES_HPP

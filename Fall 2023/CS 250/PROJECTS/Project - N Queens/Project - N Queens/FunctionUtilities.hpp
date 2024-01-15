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

#endif // !FUNCTION_UTILITIES_HPP

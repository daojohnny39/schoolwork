#include <iostream>
#include "setFunctions.h"
using namespace std;

// COMPLETE THIS FILE

bool containsElement(char* set, int size, char itemToCheck) {
	for (int i = 0; i < size; i++)
	{
		if (set[i] == itemToCheck)
		{
			return true;
		}
	}
	return false;
}

void display(char* set, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << set[i] << " ";
	}
	cout << endl;
}

char* addElement(char* set, int size, char itemToAdd, int& resultSize) {
	
}
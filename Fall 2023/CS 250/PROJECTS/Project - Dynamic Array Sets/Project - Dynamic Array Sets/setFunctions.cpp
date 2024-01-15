/**
* Author: Johnny (Nhat) Dao
**/

#include <iostream>
#include "setFunctions.h"
using namespace std;

// COMPLETE THIS FILE

bool containsElement(char* set, int size, char itemToCheck) {
	for (int i = 0; i < size; i++) {
		if (set[i] == itemToCheck) {
			return true;
		}
	}
	return false;
}

void display(char* set, int size) {
	cout << "{";

	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			cout << set[i];
			break;
		}
		else {
			cout << set[i] << ", ";
		}
	}

	cout << "}";
	cout << endl;

	// OUTPUT FORMAT: {a, b, c, d, e, f, g, h, i, j}
}

char* addElement(char* set, int size, char itemToAdd, int& resultSize) {
	// checks if the element is already in the array
	if (containsElement(set, size, itemToAdd)) { 
		resultSize = size;
		// creates a new array with the same size as the old array
		char* newSet = new char[resultSize];

		for (int i = 0; i < size; i++) {
			newSet[i] = set[i];
		}

		return newSet;
	}
	else {
		resultSize = size + 1;
		// creates a new array with the size of the old array + 1
		char* newSet = new char[resultSize];

		for (int i = 0; i < size; i++) {
			newSet[i] = set[i];
		}

		newSet[size] = itemToAdd;

		return newSet;
	}
}

char* setUnion(char* setA, int sizeA, char* setB, int sizeB, int& resultSetSize) {
	// creates a new array with the size of both arrays combined
	char* resultSet = new char[sizeA + sizeB]; 
	int index = 0;

	// adds all elements from setA to the new array
	for (int i = 0; i < sizeA; i++) { 
		resultSet[index] = setA[i];
		index++;
	}

	// adds all elements from setB to the new array
	for (int i = 0; i < sizeB; i++) { 
		// checks if the element is already in the new array
		if (!containsElement(setA, sizeA, setB[i])) { 
			resultSet[index] = setB[i];
			index++;
		}
	}

	resultSetSize = index;
	return resultSet;
}

char* setIntersect(char* setA, int sizeA, char* setB, int sizeB, int& resultSetSize) {
	// creates a new array with the size of both arrays combined
	char* resultSet = new char[sizeA + sizeB]; 
	int index = 0;

	// adds all elements from setA to the new array
	for (int i = 0; i < sizeA; i++) {
		// checks if the element is in setB
		if (containsElement(setB, sizeB, setA[i])) {
			resultSet[index] = setA[i];
			index++;
		}
	}

	resultSetSize = index;
	return resultSet;
}

// NEED TO DO???
/*bool equal(char* setA, int sizeA, char* setB, int sizeB) {
		for (int i = 0; i < sizeA; i++) {
			// checks if the element is in setB
			if (!containsElement(setB, sizeB, setA[i])) {
				return false;
			}
			else {
				return true;
			}
		}
} */
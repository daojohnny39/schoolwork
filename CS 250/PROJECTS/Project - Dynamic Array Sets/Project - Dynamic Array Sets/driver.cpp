#include <iostream>
#include "setFunctions.h"
using namespace std;

int main()
{
	/***************************************************************************
	* You are welcome to edit this file and do not need to upload it with your
	* finished project. You may want to comment out some of the tests below
	* as you develop incrementally. In the end, you do want your code to 
	* successfully pass all the included tests.
	***************************************************************************/

	int setASize = 0;
	char* setA = nullptr;

	int setBSize = 0;
	char* setB = nullptr;

	int setCSize = 0;
	char* setC = nullptr;

	int resultSize = 0;
	char* resultSet = nullptr;

	cout << "Performing a series of adds to populate setA..." << endl;

	// Load setA with 'a' through 'j'
	for (int i = 0; i < 10; i++)
	{
		resultSet = addElement(setA, setASize, i + 97, resultSize); // using ASCII values
		delete[] setA;
		setA = resultSet;
		setASize = resultSize;
		
		// Uncomment below to see the set after every add
		//display(setA, setASize);
	}

	cout << "setA size: " << setASize << " [should be 10]" << endl;
	cout << "setA is below - order matters! It should be: {a, b, c, d, e, f, g, h, i, j}" << endl;
	display(setA, setASize);
	cout << endl;

	cout << "Performing a series of adds to populate setB..." << endl;

	// Load setB with 'g' through 'p'
	for (int i = 0; i < 10; i++)
	{
		resultSet = addElement(setB, setBSize, i + 103, resultSize); // using ASCII values
		delete[] setB;
		setB = resultSet;
		setBSize = resultSize;

		// Uncomment below to see the set after every add
		//display(setB, setBSize);
	}

	cout << "setB size: " << setBSize << " [should be 10]" << endl;
	cout << "setB is below - order matters! It should be: {g, h, i, j, k, l, m, n, o, p}" << endl;
	display(setB, setBSize);
	cout << endl;

	cout << "Performing a series of adds to populate setC..." << endl;

	// Load setC with 'w' through 'z'
	for (int i = 0; i < 4; i++)
	{
		resultSet = addElement(setC, setCSize, i + 119, resultSize); // using ASCII values
		delete[] setC;
		setC = resultSet;
		setCSize = resultSize;

		// Uncomment below to see the set after every add
		//display(setC, setCSize);
	}

	cout << "setC size: " << setCSize << " [should be 4]" << endl;
	cout << "setC is below - order matters! It should be: {w, x, y, z}" << endl;
	display(setC, setCSize);
	cout << endl;

	cout << "Displaying an empty set below. It should be: {}" << endl;
	display(nullptr, 0);
	cout << endl;

	cout << "Is 'c' an element of setA? " << containsElement(setA, setASize, 'c')
		<< " [should be 1]" << endl;
	cout << "Is 'x' an element of setA? " << containsElement(setA, setASize, 'x')
		<< " [should be 0]" << endl << endl;

	cout << "Is 'c' an element of setB? " << containsElement(setB, setBSize, 'c')
		<< " [should be 0]" << endl;
	cout << "Is 'p' an element of setB? " << containsElement(setB, setBSize, 'p')
		<< " [should be 1]" << endl << endl;

	cout << "Is 'c' an element of setC? " << containsElement(setC, setCSize, 'c')
		<< " [should be 0]" << endl;
	cout << "Is 'x' an element of setC? " << containsElement(setC, setCSize, 'x')
		<< " [should be 1]" << endl << endl;

	cout << "Is 'x' an element of an empty set? " 
		<< containsElement(nullptr, 0, 'x')
		<< " [should be 0]" << endl << endl;
	
	cout << "Attempting to add duplicate elements to setA."
		<< " The set should not change..." << endl;
	
	// Re-add 'a'
	resultSet = addElement(setA, setASize, 'a', resultSize); // using ASCII values
	delete[] setA;
	setA = resultSet;
	setASize = resultSize;

	// Re-add 'f'
	resultSet = addElement(setA, setASize, 'f', resultSize); // using ASCII values
	delete[] setA;
	setA = resultSet;
	setASize = resultSize;

	// Re-add 'j'
	resultSet = addElement(setA, setASize, 'j', resultSize); // using ASCII values
	delete[] setA;
	setA = resultSet;
	setASize = resultSize;

	cout << "setA size: " << setASize << " [should be 10]" << endl;
	cout << "setA is below - order matters! It should be: "
		<< "{a, b, c, d, e, f, g, h, i, j}" << endl;
	display(setA, setASize);
	cout << endl;

	cout << "Creating the union of setA and setB. The order *does not* " 
		<< "have to match, but the result should include:"  << endl
		<< "{a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p}" << endl
		<< "Union: ";
	resultSet = setUnion(setA, setASize, setB, setBSize, resultSize);
	display(resultSet, resultSize);
	cout << "Union size: " << resultSize << " [should be 16]" << endl << endl;

	delete[] resultSet;
	resultSet = nullptr;
	resultSize = 0;

	cout << "Creating the union of setC and setA. The order *does not* "
		<< "have to match, but the result should include:" << endl
		<< "{w, x, y, z, a, b, c, d, e, f, g, h, i, j}" << endl
		<< "Union: ";
	resultSet = setUnion(setC, setCSize, setA, setASize, resultSize);
	display(resultSet, resultSize);
	cout << "Union size: " << resultSize << " [should be 14]" << endl << endl;

	delete[] resultSet;
	resultSet = nullptr;
	resultSize = 0;

	cout << "Creating the union of setC and an emptySet. The order *does not* "
		<< "have to match, but the result should include:" << endl
		<< "{w, x, y, z}" << endl
		<< "Union: ";
	resultSet = setUnion(setC, setCSize, nullptr, 0, resultSize);
	display(resultSet, resultSize);
	cout << "Union size: " << resultSize << " [should be 4]" << endl << endl;

	delete[] resultSet;
	resultSet = nullptr;
	resultSize = 0;

	cout << "Creating the intersection of setA and setB. The order *does not* "
		<< "have to match, but the result should include:" << endl
		<< "{g, h, i, j}" << endl
		<< "Intersection: ";
	resultSet = setIntersect(setA, setASize, setB, setBSize, resultSize);
	display(resultSet, resultSize);
	cout << "Intersection size: " << resultSize << " [should be 4]" << endl << endl;

	delete[] resultSet;
	resultSet = nullptr;
	resultSize = 0;

	cout << "Creating the intersection of setC and setA. The order *does not* "
		<< "have to match, but the result should include:" << endl
		<< "{}" << endl
		<< "Intersection: ";
	resultSet = setIntersect(setC, setCSize, setA, setASize, resultSize);
	display(resultSet, resultSize);
	cout << "Intersection size: " << resultSize << " [should be 0]" << endl << endl;

	delete[] resultSet;
	resultSet = nullptr;
	resultSize = 0;

	cout << "Creating the intersection of an empty set and setA. The order *does not* "
		<< "have to match, but the result should include:" << endl
		<< "{}" << endl
		<< "Intersection: ";
	resultSet = setIntersect(nullptr, 0, setA, setASize, resultSize);
	display(resultSet, resultSize);
	cout << "Intersection size: " << resultSize << " [should be 0]" << endl << endl;

	delete[] setA;
	setA = nullptr;

	delete[] setB;
	setB = nullptr;

	delete[] setC;
	setC = nullptr;

	delete[] resultSet;
	resultSet = nullptr;

}

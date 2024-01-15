#include <iostream>
#include <string>
#include "Pair.hpp"
using namespace std;

int main()
{

	Pair<int> pair1(3, 6);
	Pair<char> pair2('a', 'b');
	Pair<string> pair3("Hello", "World");

	cout << "A Pair of ints: " << endl
		<< "\tFirst item: " << pair1.getElement(1) << endl
		<< "\tSecond item: " << pair1.getElement(2) << endl;

	pair1.swapElements();

	cout << "\n\tAfter swapElements: " << endl
		<< "\tFirst item: " << pair1.getElement(1) << endl
		<< "\tSecond item: " << pair1.getElement(2) << endl;

	cout << "\nA Pair of chars: " << endl
		<< "\tFirst item: " << pair2.getElement(1) << endl
		<< "\tSecond item: " << pair2.getElement(2) << endl;

	pair2.swapElements();

	cout << "\n\tAfter swapElements: " << endl
		<< "\tFirst item: " << pair2.getElement(1) << endl
		<< "\tSecond item: " << pair2.getElement(2) << endl;

	cout << "\nA Pair of strings: " << endl
		<< "\tFirst item: " << pair3.getElement(1) << endl
		<< "\tSecond item: " << pair3.getElement(2) << endl;

	pair3.swapElements();

	cout << "\n\tAfter swapElements: " << endl
		<< "\tFirst item: " << pair3.getElement(1) << endl
		<< "\tSecond item: " << pair3.getElement(2) << endl;

	return 0;
}
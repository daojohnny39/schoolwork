#include "Cat.h"
#include <iostream>

using namespace std;

Cat::Cat(string pName, string pType) : Animal(pName, pType) {}

void Cat::speak() {
	cout << "\"Meow!\" says " << getName() << " the cat." << endl;
}

#include "Dog.h"
#include <iostream>

using namespace std;

Dog::Dog(string pName, string pType) : Animal(pName, pType) {}

void Dog::speak() {
	cout << "\"Woof!\" says " << getName() << " the dog." << endl;
}
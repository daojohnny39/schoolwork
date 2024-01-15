#include "Animal.h"
#include <iostream>

Animal::Animal(string pName, string pType) {
	setName(pName);
	setType(pType);
}

void Animal::setName(string pName)
{
	name = pName;
}

void Animal::setType(string pType)
{
	type = pType;
}

string Animal::getName()
{
	return name;
}

string Animal::getType()
{
	return type;
}

void Animal::speak() {
	cout << "\"Noise!\" says " << name << "." << endl;
}
#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
	Dog(string pName = "Name", string pType = "dog");
	void speak();
};

#endif // !DOG_H

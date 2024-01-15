#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
	Cat(string pName = "Name", string pType = "cat");
	void speak();
};

#endif // !CAT_H

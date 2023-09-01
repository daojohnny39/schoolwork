#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
private:
	string name;
	string type;

public:
	Animal(string pName = "Name", string pType = "Animal");
	void setName(string pName);
	void setType(string pName);
	string getName();
	string getType();
	virtual void speak();
};// end Animal

#endif
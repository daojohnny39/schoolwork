#include "Vet.h"
#include <iostream>
using namespace std;

void Vet::giveShot(Animal* aniPtr) {
	// Give that poor animal a shot here!
	cout << "I'm giving the animal a shot..." << endl;
	aniPtr->speak();
	cout << endl;
}// end giveShot()
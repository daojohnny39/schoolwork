#include <iostream>
#include <string>
#include "Animal.h"
#include "Vet.h"
#include "Dog.h"
#include "Cat.h"
using namespace std;

int main() {

	Animal defaultAnimal("Jimbo", "aardvark");
	cout << "Animal Name: " << defaultAnimal.getName() << endl
		<< "Type: " << defaultAnimal.getType() << endl
		<< "Sound: ";
	defaultAnimal.speak();
	cout << endl;
    
	// Dog test. Also uncomment the include above.
	Dog defaultDog;
	defaultDog.setName("Marley");
    cout << "Animal Name: " << defaultDog.getName() << endl 
		<< "Type: " << defaultDog.getType() << endl
		<< "Sound: ";
	defaultDog.speak();
	cout << endl;
	
	// Cat test. Also uncomment the include above.
	Cat defaultCat;
	defaultCat.setName("Garfield");
    cout << "Animal Name: " << defaultCat.getName() << endl 
		<< "Type: " << defaultCat.getType() << endl
		<< "Sound: ";
	defaultCat.speak();
	cout << endl;
	
	// STEP 5 - DONE
	Dog* dogPtr = new Dog(defaultDog.getName());
	Cat* catPtr = new Cat(defaultCat.getName());
	
	// STEP 6 - DONE
	Vet vetObj;
	
	// STEP 7 - DONE
	vetObj.giveShot(dogPtr);

	// STEP 8 - DONE
	vetObj.giveShot(catPtr);

	return 0;
}// end main()
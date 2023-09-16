#include <iostream>
#include "Account.h"

int main()
{
	Account a(100);
	int choice = 0;

	do {
		std::cout << "What test do you want to do?"
			<< std::endl << "1. NegativeAmount exception with deposit()" 
			<< std::endl << "2. InsufficientFunds exception with withdraw()" 
			<< std::endl << "3. NegativeAmount exception with withdraw()"
			<< std::endl << "Your choice: ";
		std::cin >> choice;

		if ((choice < 1) || (choice > 3))
		{
		std::cout << std::endl << "Invalid choice, please enter 1, 2, or 3." << std::endl << std::endl;
		}	
	} while ((choice < 1) || (choice > 3));

	
	// STEP 6

	std::cin.ignore();
	std::cin.get();
	return 0;
}



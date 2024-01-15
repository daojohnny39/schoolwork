#include <iostream>
#include <string>
#include <stdexcept>
#include "ArrayStack.hpp"

void stackTester(StackInterface<std::string>* stackPtr)
{
	try
	{
		std::string items[] = { "zero", "one", "two", "three", "four", "five" };
		std::cout << "isEmpty(): " << stackPtr->isEmpty() 
			<< " [should be 1]" << std::endl << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << "Pushing " << items[i] << ": " 
				<< stackPtr->push(items[i]) << " [should be 1]" << std::endl;
		}

		std::cout << "Pushing " << items[5] << ": "
			<< stackPtr->push(items[5]) << " [should be 0, max items is 5]" << std::endl;

		std::cout << std::endl << "isEmpty(): " << stackPtr->isEmpty()
			<< " [should be 0]" << std::endl;

		for (int i = 0; i < 5; i++)
		{
			std::cout << "peek(): " << stackPtr->peek() 
				<< " [should be " << items[4-i] << "]" << std::endl;
			std::cout << "pop(): " << stackPtr->pop() 
				<< " [should be 1]" << std::endl;

		}

		std::cout << std::endl << "isEmpty(): " << stackPtr->isEmpty() 
			<< " [should be 1]" << std::endl << std::endl;

		std::cout << "pop an empty stack: " << std::endl;
		std::cout << "pop(): " << stackPtr->pop() << " [should be 0]" 
			<< std::endl << std::endl;   // nothing to pop!

		std::cout << "peek into an empty stack: "
			<< "[should be an error from thrown exception]" << std::endl;
		std::cout << "peek(): " << stackPtr->peek() << std::endl; 
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}  // end try/catch
}  // end stackTester

int main()
{
	StackInterface<std::string>* stackPtr = new ArrayStack<std::string>();
	std::cout << "TESTING AN ARRAY-BASED STACK" << std::endl << std::endl;
	stackTester(stackPtr);

	return 0;
}  // end main


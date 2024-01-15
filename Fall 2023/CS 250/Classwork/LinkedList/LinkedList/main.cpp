#include "LinkedList.hpp"
#include <iostream>
#include <string>

const int ITEM_COUNT = 10;

int main()
{
	ListInterface<std::string>* listPtr = new LinkedList<std::string>();
	std::string data[] = { "one", "two", "three", "four", "five", "six",
		"seven", "eight", "nine", "ten" };

	std::cout << "isEmpty: returns " << listPtr->isEmpty()
		<< " [should be 1]" << std::endl;

	for (int i = 0; i < ITEM_COUNT; i++)
	{
		if (listPtr->insert(i + 1, data[i]))
		{
			try
			{
				std::cout << "Successfully inserted " << listPtr->getEntry(i + 1)
					<< " at position " << (i + 1) << std::endl;
			}
			catch (std::runtime_error except)
			{
				std::cout << except.what() << std::endl;
			}
		}
		else
			std::cout << "Cannot insert " << data[i]
			<< " at position " << (i + 1) << std::endl;
	}  // end for

	std::cout << std::endl << "isEmpty: returns " << listPtr->isEmpty()
		<< " [should be 0]" << std::endl;

	std::cout << std::endl << "The List contains:" << std::endl;
	for (int i = 0; i < listPtr->getLength(); i++)
	{
		std::cout << listPtr->getEntry(i + 1) << std::endl;
	}

	std::cout << std::endl << "Replacing the even numbered entries..." << std::endl;

	for (int i = 2; i <= listPtr->getLength(); i += 2)
	{
		std::cout << "Replace entry " << i << ": "
			<< listPtr->replace(i, std::to_string(i)) << std::endl;
	}

	std::cout << std::endl << "The List contains:" << std::endl;
	for (int i = 1; i <= listPtr->getLength(); i++)
	{
		std::cout << listPtr->getEntry(i) << std::endl;
	}

	std::cout << std::endl << "Removing entry 5: " <<
		listPtr->remove(5) << std::endl;

	std::cout << std::endl << "The List contains:" << std::endl;
	for (int i = 1; i <= listPtr->getLength(); i++)
	{
		std::cout << listPtr->getEntry(i) << std::endl;
	}

	std::cout << std::endl << "Clearing the list..." << std::endl;

	listPtr->clear();

	std::cout << "isEmpty: returns " << listPtr->isEmpty()
		<< " [should be 1]" << std::endl;

	return 0;
}  // end main


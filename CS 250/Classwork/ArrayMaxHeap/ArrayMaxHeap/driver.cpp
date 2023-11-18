#include "ArrayMaxHeap.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
	ArrayMaxHeap<std::string>* heapPtr = new ArrayMaxHeap<std::string>();
	
	std::cout << "Adding 8 nodes..." << std::endl << std::endl;
	heapPtr->add("50");
	heapPtr->add("30");
	heapPtr->add("70");
	heapPtr->add("20");
	heapPtr->add("60");
	heapPtr->add("40");
	heapPtr->add("10");
	heapPtr->add("80");

	std::cout << "Trying to add 9th node: " << heapPtr->add("90") << " [should be 0]" << std::endl;
	std::cout << "# of nodes: " << heapPtr->getNumberOfNodes() << " [should be 8]" << std::endl;
	std::cout << "Height: " << heapPtr->getHeight() << " [should be 4]" << std::endl;
	std::cout << "max value: " << heapPtr->peekTop() << " [should be 80]" << std::endl;
	
	std::cout << std::endl;
	std::cout << "Removing 7 nodes..." << std::endl << std::endl;
	
	for (int i = 0; i < 7; i++)
	{
		heapPtr->remove();
	}

	std::cout << "# of nodes: " << heapPtr->getNumberOfNodes() << " [should be 1]" << std::endl;
	std::cout << "Height: " << heapPtr->getHeight() << " [should be 1]" << std::endl;
	std::cout << "max value: " << heapPtr->peekTop() << " [should be 10]" << std::endl;

	std::cout << std::endl;
	std::cout << "Remove last node..." << std::endl << std::endl;
	heapPtr->remove();

	std::cout << "# of nodes: " << heapPtr->getNumberOfNodes() << " [should be 0]" << std::endl;
	std::cout << "Height: " << heapPtr->getHeight() << " [should be 0]" << std::endl;
	
	std::cout << std::endl;
	std::cout << "peekTop() should cause an exception..." << std::endl << std::endl;

	try
	{
		std::cout << "max value: " << heapPtr->peekTop() << std::endl;
	}
	catch (std::logic_error eObj)
	{
		std::cout << eObj.what() << std::endl;
	}

	return 0;
}  // end main


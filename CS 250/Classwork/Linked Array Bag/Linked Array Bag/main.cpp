#include <iostream>
#include <string>
#include "LinkedBag.hpp"

void bagTester(LinkedBag<std::string>& bag);

int main()
{
	LinkedBag<std::string> bag;
	std::cout << "TESTING THE LINKED BAG:" << std::endl << std::endl;
	bagTester(bag);
	std::cout << "ALL DONE!" << std::endl;

	return 0;
}  // end main

void bagTester(LinkedBag<std::string>& bag)
{
	std::cout << "isEmpty() returns: " << bag.isEmpty()
		<< " [should be 1 (true)]" << std::endl;

	std::cout << "getCurrentSize() returns: " << bag.getCurrentSize()
		<< " [should be 0]" << std::endl << std::endl;

	std::string items[] = { "one", "two", "three", "one", "four", "five", "one" };
	std::cout << "Adding 7 items to the bag..." << std::endl;
	for (int i = 0; i < 7; i++)
	{
		bag.add(items[i]);
	}  // end for

	std::vector<std::string> bagItems = bag.toVector();

	int numberOfEntries = (int)bagItems.size();
	if (numberOfEntries > 0)
	{
		std::cout << "Bag contains: ";
	}
	for (int i = 0; i < numberOfEntries; i++)
	{
		std::cout << bagItems[i] << " ";
	}  // end for
	std::cout << std::endl;

	std::cout << std::endl << "isEmpty() returns: " << bag.isEmpty()
		<< " [should be 0 (false)]" << std::endl;

	std::cout << "getCurrentSize() returns: " << bag.getCurrentSize()
		<< " [should be 7]" << std::endl << std::endl;

	std::cout << "contains(\"three\"): returns " << bag.contains("three")
		<< " [should be 1 (true)]" << std::endl << std::endl;
	std::cout << "contains(\"ten\"): returns " << bag.contains("ten")
		<< " [should be 0 (false)]" << std::endl;
	std::cout << "getFrequencyOf(\"one\"): returns "
		<< bag.getFrequencyOf("one") << " [should be 3]" << std::endl << std::endl;

	std::cout << "remove(\"one\"): returns " << bag.remove("one")
		<< " [should be 1 (true)]" << std::endl;
	std::cout << "getFrequencyOf(\"one\"): returns "
		<< bag.getFrequencyOf("one") << " should be 2" << std::endl;
	std::cout << "remove(\"one\"): returns " << bag.remove("one")
		<< " [should be 1 (true)]" << std::endl;
	std::cout << "remove(\"one\"): returns " << bag.remove("one")
		<< " [should be 1 (true)]" << std::endl;
	std::cout << std::endl;

	std::cout << "getCurrentSize() returns: " << bag.getCurrentSize()
		<< " [should be 4]" << std::endl;
	bagItems = bag.toVector();

	numberOfEntries = (int)bagItems.size();
	if (numberOfEntries > 0)
	{
		std::cout << "Bag contains: ";
	}
	for (int i = 0; i < numberOfEntries; i++)
	{
		std::cout << bagItems[i] << " ";
	}  // end for
	std::cout << std::endl << std::endl;

	LinkedBag<std::string> copiedBag(bag);

	std::cout << "copiedBag.getCurrentSize() returns: " << copiedBag.getCurrentSize()
		<< " [should be 4]" << std::endl;
	bagItems = copiedBag.toVector();

	numberOfEntries = (int)bagItems.size();
	if (numberOfEntries > 0)
	{
		std::cout << "copiedBag contains: ";
	}
	for (int i = 0; i < numberOfEntries; i++)
	{
		std::cout << bagItems[i] << " ";
	}  // end for
	std::cout << std::endl << std::endl;
	

	std::cout << "Clearing the bag with clear()." << std::endl;
	bag.clear();

	std::cout << "isEmpty() returns: " << bag.isEmpty()
		<< " [should be 1 (true)]" << std::endl;

	std::cout << "getCurrentSize() returns: " << bag.getCurrentSize()
		<< " [should be 0]" << std::endl << std::endl;

	std::cout << "copiedBag.getCurrentSize() returns: " << copiedBag.getCurrentSize()
		<< " [should be 4]" << std::endl;
	bagItems = copiedBag.toVector();

	numberOfEntries = (int)bagItems.size();
	if (numberOfEntries > 0)
	{
		std::cout << "copiedBag contains: ";
	}
	for (int i = 0; i < numberOfEntries; i++)
	{
		std::cout << bagItems[i] << " ";
	}  // end for
	std::cout << std::endl << std::endl;
}  // end bagTester

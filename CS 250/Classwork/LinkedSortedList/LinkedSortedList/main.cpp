#include <iostream>
#include <string>
#include <memory>

#include "LinkedSortedList.hpp" // ADT list operations

template<class ItemType>
void displayList(std::shared_ptr<ItemType> listPtr);

template<class ItemType>
void sortedListTester(std::shared_ptr<ItemType> listPtr);

template<class ItemType>
void copyConstructorTester(std::shared_ptr<ItemType> listPtr);


int main()
{

	auto listPtr = std::make_shared<LinkedSortedList<std::string>>();


	std::cout << std::endl
		<< "*******************" << std::endl
		<< "* BEGINNING TESTS *" << std::endl
		<< "*******************" << std::endl
		<< std::endl;

	sortedListTester(listPtr);

	copyConstructorTester(listPtr);

	std::cout << "Thanks for testing!\n";
	return 0;
}  // end main

template<class ItemType>
void displayList(std::shared_ptr<ItemType> listPtr)
{
	//std::cout << "The sorted list contains " << std::endl;
	for (int pos = 1; pos <= listPtr->getLength(); pos++)
	{
		std::cout << listPtr->getEntry(pos);
		if (pos < listPtr->getLength())
		{
			std::cout << ", ";
		}
	} // end for
	std::cout << std::endl << std::endl;
}  // end displayList

template<class ItemType>
void copyConstructorTester(std::shared_ptr<ItemType> listPtr)
{
	std::string items[] = { "zero", "one", "two", "three", "four", "five" };
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Adding " << items[i] << std::endl;
		listPtr->insertSorted(items[i]);
	}
	std::cout << "Original list: ";
	displayList(listPtr);

	std::shared_ptr<SortedListInterface<std::string>> copyOfList(listPtr);
	std::cout << "Copy of list: ";
	displayList(copyOfList);

}  // end copyConstructorTester

template<class ItemType>
void sortedListTester(std::shared_ptr<ItemType> listPtr)
{
	auto luke = "Luke";
	auto brent = "Brent";
	auto donna = "Donna";
	auto tom = "Tom";
	auto sue = "Sue";
	auto jerry = "Jerry";

	std::cout << "isEmpty(): " << listPtr->isEmpty()
		<< " [should be 1]" << std::endl << std::endl;

	std::cout << "insertSorted(luke): " << listPtr->insertSorted(luke)
		<< " [should be 1]" << std::endl;
	std::cout << "insertSorted(brent): " << listPtr->insertSorted(brent)
		<< " [should be 1]" << std::endl;
	std::cout << "insertSorted(donna): " << listPtr->insertSorted(donna)
		<< " [should be 1]" << std::endl;
	std::cout << "insertSorted(tom): " << listPtr->insertSorted(tom)
		<< " [should be 1]" << std::endl;
	std::cout << "insertSorted(sue): " << listPtr->insertSorted(sue)
		<< " [should be 1]" << std::endl;
	std::cout << "insertSorted(jerry): " << listPtr->insertSorted(jerry)
		<< " [should be 1]" << std::endl << std::endl;

	std::cout << "getLength() returns : " << listPtr->getLength()
		<< " [should be 6]" << std::endl << std::endl;

	// display the list
	std::cout << "List should contain: Brent, Donna, " <<
		"Jerry, Luke, Sue, Tom" << std::endl;
	std::cout << "\nList actually contains: ";
	displayList(listPtr);

	// test getPosition
	std::cout << "\nTest getPosition:\n" << std::endl;

	// These names are in the list
	std::cout << "Brent is at position " << listPtr->getPosition(brent)
		<< " [should be 1]" << std::endl;
	std::cout << "Donna is at position " << listPtr->getPosition(donna)
		<< " [should be 2]" << std::endl;
	std::cout << "Jerry is at position " << listPtr->getPosition(jerry)
		<< " [should be 3]" << std::endl;
	std::cout << "Luke is at position " << listPtr->getPosition(luke)
		<< " [should be 4]" << std::endl;
	std::cout << "Sue is at position " << listPtr->getPosition(sue)
		<< " [should be 5]" << std::endl;
	std::cout << "Tom is at position " << listPtr->getPosition(tom)
		<< " [should be 6]" << std::endl;

	// These names are not in the list
	std::string missy = "Missy";
	std::cout << "Missy belongs at position " << listPtr->getPosition(missy)
		<< " [should be -5]" << std::endl;
	std::string zeke = "Zeke";
	std::cout << "Zeke belongs at position " << listPtr->getPosition(zeke)
		<< " [should be -7]" << std::endl;
	std::string aaron = "Aaron";
	std::cout << "Aaron belongs at position " << listPtr->getPosition(aaron)
		<< " [should be -1]" << std::endl;

	// test getLength and getEntry
	std::cout << "\nTest getLength and getEntry:\n" << std::endl;

	std::cout << "\nList has " << listPtr->getLength() << " entries, as follows:\n" << std::endl;
	for (int i = 1; i <= listPtr->getLength(); i++)
		std::cout << i << ": " << listPtr->getEntry(i) << std::endl;

	// test remove
	std::cout << "\nTest remove:\n";

	// remove first entry
	std::cout << "\nRemoving first item (Brent): " << listPtr->removeSorted(brent) << " [should be 1]" << std::endl;
	std::cout << "\nAfter removing Brent, list contains " << listPtr->getLength()
		<< " items, as follows:" << std::endl;
	displayList(listPtr);

	// remove interior
	std::cout << "\nRemoving interior item (Luke): " << listPtr->removeSorted(luke) << " [should be 1]" << std::endl;
	std::cout << "\nAfter removing Luke, list contains " << listPtr->getLength()
		<< " items, as follows:" << std::endl;
	displayList(listPtr);

	// remove last
	std::cout << "\nRemoving last item (Tom): " << listPtr->removeSorted(tom) << " [should be 1]" << std::endl;
	std::cout << "\nAfter removing last item, list contains " << listPtr->getLength()
		<< " items, as follows:" << std::endl;
	displayList(listPtr);

	std::cout << "\nRemoving a missing item (Brent): " << listPtr->removeSorted(brent) << " [should be 0]" << std::endl;
	//std::cout << "\nRemoving a missing item (Luke): " << listPtr->removeSorted(luke) << " [should be 0]" << std::endl;
	//std::cout << "\nRemoving a missing item (Tom): " << listPtr->removeSorted(tom) << " [should be 0]" << std::endl;

	std::cout << "\nThe list contains " << listPtr->getLength()
		<< " items, as follows:" << std::endl;
	displayList(listPtr);

	// test clear()
	std::cout << "\nTest clear():\n" << std::endl;
	listPtr->clear();

	std::cout << "isEmpty(): " << listPtr->isEmpty()
		<< " [should be 1]" << std::endl << std::endl;
} // end sortedListTester


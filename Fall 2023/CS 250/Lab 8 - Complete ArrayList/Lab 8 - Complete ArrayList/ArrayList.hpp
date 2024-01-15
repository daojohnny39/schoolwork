#ifndef ARRAY_LIST_
#define ARRAY_LIST_

#include <stdexcept>
#include "ListInterface.h"

/* BEGIN ARRAYLIST INTERFACE */

template<class ItemType>
class ArrayList : public ListInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 100; // Default capacity of the list
	ItemType items[DEFAULT_CAPACITY + 1];    // Array of list items (ignore items[0]
	int itemCount;                           // Current count of list items
	int maxItems;                            // Maximum capacity of the list

public:
	ArrayList();
	// Copy constructor and destructor are supplied by compiler

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const;
	ItemType replace(int position, const ItemType& newEntry)
		;
}; // end ArrayList

/********** FUNCTIONS BELOW NEED TO BE COMPLETED **********/

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	
	bool canInsert = (newPosition >= 1) && (newPosition <= itemCount + 1)
		&& (itemCount < maxItems);

	if (canInsert) {
		for (int i = itemCount; i >= newPosition; i--) {
			items[i + 1] = items[i];
		}

		items[newPosition] = newEntry;
		itemCount++;
	}

	return canInsert;

}  

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const
{
	
	bool isValidPos = (position > 0) && (position <= itemCount);

	if (isValidPos) {
		return items[position];
	}
	else {
		throw(std::runtime_error("getEntry called with invalid position"));
	}

}  

template<class ItemType>
bool ArrayList<ItemType>::remove(int position)
{
	
	bool isValidPos = (position > 0) && (position <= itemCount);

	if (isValidPos) {
		for (int i = position; i <= itemCount - 1; i++) {
			items[i] = items[i + 1];
		}

		itemCount--;
	}

	return isValidPos;

}  

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry)
{
	
	bool isValidPos = (position > 0) && (position <= itemCount);

	if (isValidPos) {
		ItemType oldEntry = items[position];
		items[position] = newEntry;
		return oldEntry;
	}
	else {
		throw(std::runtime_error("replace() called with invalid position"));
	}

}  

/********** EVERYTHING BELOW THIS LINE IS COMPLETE **********/

template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
void ArrayList<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int ArrayList<ItemType>::getLength() const
{
	return itemCount;
}  // end getLength

#endif 

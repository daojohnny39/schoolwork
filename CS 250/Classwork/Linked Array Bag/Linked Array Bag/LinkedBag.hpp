/** Interface and implementation for class LinkedBag.
    @file LinkedBag.hpp */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.hpp"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target) const;
   
public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;
}; // end LinkedBag

// Default constructor should initialize itemCount and headPtr.
template<class ItemType>
LinkedBag<ItemType>::LinkedBag()
{
	itemCount = 0;
	headPtr = nullptr;
} 

// Adds the given item to the FRONT of the linked chain.
template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
	
	Node<ItemType>* newPtr = new Node<ItemType>(newEntry, headPtr);
	//newPtr->setItem(newEntry); - alternative
	//newPtr->setNext(headPtr); - alternative

	headPtr = newPtr;
	itemCount++;

	return true;
} 

// Takes each item in the bag and places it into a vector. Returns the vector.
template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{

	std::vector<ItemType> bagContents;

	Node<ItemType>* curPtr = headPtr;	// creates a pointer to the first node in the chain
	curPtr = curPtr->getNext();			// moves the pointer to the next node in the chain

	while (curPtr != nullptr) { // while not at the end of the chain
		bagContents.push_back(curPtr->getItem());	// do whatever we need with the current node
		curPtr = curPtr->getNext();					// move to the next node
	}

	return bagContents;
}  

// Returns the total number of items in the bag.
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  

// Returns true if there are no items in the bag, otherwise false.
template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return (itemCount == 0);
}

// getPointerTo() is a private helper method used by contains() and remove().
// Returns a pointer to the FIRST occurance of the target in the bag array
// or nullptr if the target is not found.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
	Node<ItemType>* curPtr = headPtr;

	while (curPtr != nullPtr) {
		// do something
		if (curPtr->getItem() == anEntry) {
			break;
		}

		curPtr = curPtr->getNext();
	}

	return curPtr;

}

// Returns true if the bag contains the given entry, false if not.
// The best version makes use of getPointerTo().
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	// STUB - FINISH ME

	return true;
	
}  // end contains

// Removes one copy of the given item from the bag. Returns true if
// successful.
template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	/* STEPS:
	1. Find the first node containing the item to be removed.
	2. Copy the data from the current head node into the node containing the
	   data to be removed.
	3. Delete the head node. */

	// STUB - FINISH ME

	return true;
}  // end remove

// Returns the number of times the given item appears in the bag.
template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	// STUB - FINISH ME

	return 0;
}  // end getFrequencyOf

// Empties the bag. Watch out for memory leaks!
template<class ItemType>
void LinkedBag<ItemType>::clear()
{
	/* PSEUDOCODE
	while (headPtr is not nullPtr)
	{
		Make headPtr point to the 2nd node in the chain
		Delete the old head node
	} */

	// STUB - FINISH ME
	
}  // end clear

// Destructor removes anything created on the heap
template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
	
	// STUB - FINISH ME
	
}  // end destructor

// Parameterized constructor copies contents from the bag parameter
// into the newly created bag.
template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	/* PSEUDOCODE
	
	if (bag to copy is empty)
	{
		set head pointer to be null
	}
	else
	{
		copy first node data into a new node
		while (traversing the rest of chain to copy)
			copy data from current node into a new node
			link new node into new chain
	} */

	// STUB - FINISH ME
	
}  // end copy constructor

#endif
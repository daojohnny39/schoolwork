/** Interface and implementation for an array-based ADT bag.
 @file ArrayBag.hpp */

#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
   int itemCount;                         // Current count of bag items 
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;
}; // end ArrayBag


// Default constructor should initialize itemCount and maxItems.
template<class ItemType>
ArrayBag<ItemType>::ArrayBag()
{
	itemCount = 0;

} 

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool didAdd = false;

	if (itemCount < DEFAULT_CAPACITY) {
		items[itemCount] = newEntry;
		itemCount++;
		didAdd = true;
	}
    
	return didAdd;
}  

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;

   for (int i = 0; i < itemCount; i++) {
	   bagContents.push_back(items[i]);
   }
      
   return bagContents;
}  

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return (itemCount == 0);	// Returns true if there are no items in the bag, otherwise false.
}  

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	int targetIndex = -1;	// -1 if the target is not found.

	for (int i = 0; i < itemCount; i++) {
		if (items[i] == target) {
			targetIndex = i;
			break;
		}
	}

   return targetIndex; // Returns the index of the FIRST occurance of the target in the bag array
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
    return (getIndexOf(anEntry) != -1); // Returns true if the bag contains the given entry, false if not.
} 

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
    bool didRemove = false;
	int location = getIndexOf(anEntry);

	if (location >= 0) {
		items[location] = items[--itemCount];
		didRemove = true;
	}

	return didRemove;
}

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
    itemCount = 0;
}


// Returns the number of times the given item appears in the bag.
template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int count = 0;

   for (int i = 0; i < itemCount; i++) {
	   if (items[i] == anEntry) {
		   count++;
	   }
   }
   
   return count;
}

#endif

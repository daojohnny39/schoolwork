/** ADT sorted list: Link-based implementation. */

#ifndef LINKED_SORTED_LIST_
#define LINKED_SORTED_LIST_

#include <memory>
#include <stdexcept>
#include <cassert>
#include "SortedListInterface.h"
#include "Node.hpp"

/* BEGIN LINKEDSORTEDLIST INTERFACE */

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
   std::shared_ptr<Node<ItemType>> headPtr; // Pointer to first node in the chain
   int itemCount;           // Current count of list items
   
   // Locates the node that is before the node that should or does
   // contain the given entry.
   // @param anEntry  The entry to find.
   // @return  Either a pointer to the node before the node that contains
   //    or should contain the given entry, or nullptr if no prior node exists.
   auto getNodeBefore(const ItemType& anEntry) const;
   
   // Locates the node at a given position within the chain.
   auto getNodeAt(int position) const;
   
   // Returns a pointer to a copy of the chain to which origChainPtr points.
   auto copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr);
   
public:
   LinkedSortedList();
   LinkedSortedList(const LinkedSortedList<ItemType>& aList);
   virtual ~LinkedSortedList();   

   bool insertSorted(const ItemType& newEntry);
   bool removeSorted(const ItemType& anEntry);
   int getPosition(const ItemType& newEntry) const;
   
   // The following methods are the same as given in ListInterface:
   bool isEmpty() const;
   int getLength() const;
   bool remove(int position);
   void clear();
   ItemType getEntry(int position) const;
}; // end LinkedSortedList

/********** FUNCTIONS BELOW NEED TO BE COMPLETED **********/

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
    std::shared_ptr<Node<ItemType>> curPtr;
    std::shared_ptr<Node<ItemType>> prevPtr;

    curPtr = headPtr;

    while ((curPtr != nullptr) && (anEntry < curPtr->getItem())) {
        
        prevPtr = curPtr;
        curPtr = curPtr->getNext();

    }

    return prevPtr;
} 

template<class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{

    // STUB. FINISH ME.

    return true;
} // end insertSorted

template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry) const
{

    // STUB. FINISH ME.

    return 1;
}  // end getPosition

/********** EVERYTHING BELOW THIS LINE IS COMPLETE **********/

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
	headPtr = copyChain(aList.headPtr);
   itemCount = aList.itemCount;
}  // end copy constructor

template<class ItemType>
auto LinkedSortedList<ItemType>::copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr)
{
   std::shared_ptr<Node<ItemType>> copiedChainPtr;
	if (origChainPtr != nullptr)
	{
		// Build new chain from given one
      // Create new node with the current item
      copiedChainPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem());
      // have the node point to the rest of the chain
		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));		
	}  // end if
   
	return copiedChainPtr;
}  // end copyChain

template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
   bool ableToDelete = false;
   if (!isEmpty())
   {
      auto nodeToRemovePtr = headPtr;
      auto prevPtr = getNodeBefore(anEntry);
      if (prevPtr != nullptr)
         nodeToRemovePtr = prevPtr->getNext();
       
      ableToDelete = (nodeToRemovePtr != nullptr) && 
                     (anEntry == nodeToRemovePtr->getItem());
      if (ableToDelete)
      {
         auto aftPtr = nodeToRemovePtr->getNext();
         if (nodeToRemovePtr == headPtr)
         {
            // Delete the first node in the chain
            headPtr = aftPtr;
         }
         else
         {
         
            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(aftPtr);
         }  // end if
         
         itemCount--;  // Decrease count of entries
      }  // end if
   }  // end if

   return ableToDelete;
}  // end removeSorted

//=====================
// List operations:

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
   bool ableToDelete = (position >= 1) && (position <= itemCount);
   if (ableToDelete)
   {
      if (position == 1)
      {
         // Delete the first node in the chain
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         auto prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         auto curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToDelete;
}  // end remove

template<class ItemType>
void LinkedSortedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      auto nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      std::string message = "getEntry() called with an empty list or ";
      message  = message + "invalid position.";
      throw(std::runtime_error(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength



template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeAt(int position) const
{
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   auto curPtr = headPtr;
   for (int skipNodePtr = 1; skipNodePtr < position; skipNodePtr++)
      curPtr = curPtr->getNext();
   
   return curPtr;
}  // end getNodeAt
//  End of implementation file.

#endif
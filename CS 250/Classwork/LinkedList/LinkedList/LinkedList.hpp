#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <cassert>
#include <stdexcept>
#include "ListInterface.h"
#include "Node.hpp"

/* BEGIN LINKEDLIST INTERFACE */

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int itemCount;           // Current count of list items 
   
   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   Node<ItemType>* getNodeAt(int position) const;

public:
   LinkedList();
   virtual ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();
   ItemType getEntry(int position) const;
   ItemType replace(int position, const ItemType& newEntry);
}; // end LinkedList

/********** FUNCTIONS BELOW NEED TO BE COMPLETED **********/

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    Node<ItemType>* positionPtr = headPtr;
    
    for (int pos = 1; pos < position; pos++) {
        positionPtr = positionPtr->getNext();
    }

    return positionPtr;
}  

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool didInsert = false;

    if (newPosition > 0 && newPosition <= itemCount + 1) {
        Node<ItemType>* newPtr = new Node<ItemType>(newEntry); // creating new node.
        if (newPosition == 1) {
            newPtr->setNext(headPtr); // set newPtr's next to headptr.
            headPtr = newPtr;   // headPtr is now newPtr.
        }
        else {
            Node<ItemType>* nodeBeforePtr = getNodeAt(newPosition - 1); // Creates new node ptr and points at node before newPtr.
            newPtr->setNext(nodeBeforePtr->getNext());
            nodeBeforePtr->setNext(newPtr);
        }
        itemCount++;
        didInsert = true;
    }

    return didInsert;
}  

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool didRemove = false;

    if (position > 0 && position <= itemCount) {

        Node<ItemType>* nodeToDel = nullptr;

        if (position == 1) {
            nodeToDel = headPtr;
            headPtr = headPtr->getNext();
        }
        else {
            Node<ItemType>* nodeBeforePtr = getNodeAt(position - 1);
            nodeToDel = nodeBeforePtr->getNext();
            nodeBeforePtr->setNext(nodeToDel->getNext());
        }

        delete nodeToDel;
        itemCount--;
        didRemove = true;
    }

    return didRemove;
}  

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry)
{
    ItemType origValue;

    if (position > 0 && position <= itemCount + 1) {
        Node<ItemType>* nodeToUpdate = getNodeAt(position);
        origValue = nodeToUpdate->getItem();
        nodeToUpdate->setItem(newEntry);
    }
    else {
        throw std::out_of_range("ERROR: Invalid position for replacement.");
    }

    return origValue;

}  



/********** EVERYTHING BELOW THIS LINE IS COMPLETE **********/

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}  // end getLength

template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw(std::runtime_error(message));
    }  // end if
}  // end getEntry

#endif 

#ifndef LINKED_STACK_
#define LINKED_STACK_

#include "StackInterface.h"
#include "Node.hpp"
#include <string>
#include <stdexcept> // for runtime_error

/* LINKEDSTACK INTERFACE BEGIN */
template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
private:
	Node<ItemType>* topPtr; // Pointer to first node in the chain;
						   // this node contains the stack's top

public:
	// Constructors and destructor:
	LinkedStack();                                   // Default constructor
	LinkedStack(const LinkedStack<ItemType>& aStack);// Copy constructor 
	virtual ~LinkedStack();                          // Destructor

// Stack operations:
	bool isEmpty() const;
	bool push(const ItemType& newItem);
	bool pop();
	ItemType peek() const;
}; // end LinkedStack

/********** FUNCTIONS BELOW NEED TO BE COMPLETED **********/

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry)
{
	
	bool didAdd = false;
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, topPtr);
	topPtr = newNodePtr;

	didAdd = true;


	return didAdd;
}  

/* peek() should throw a std::runtime_error exception if the stack is empty. */
template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const
{
	
	if (topPtr == nullptr) {
		throw std::runtime_error("ERROR! The stack is empty");
	}
	else {
		return topPtr->getItem();
	}
	
}  

template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	bool didRemove = false;
	if (topPtr == nullptr) {
		didRemove = false;
	}
	else {
		Node<ItemType>* nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();
		delete nodeToDeletePtr;

		didRemove = true;
	}

	return didRemove;
}  

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	while (topPtr != nullptr) {
		pop();
	}
}  

/********** EVERYTHING BELOW THIS LINE IS COMPLETE **********/

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
	// Point to nodes in original chain
	Node<ItemType>* origChainPtr = aStack.topPtr;

	if (origChainPtr == nullptr)
		topPtr = nullptr;  // Original stack is empty
	else
	{
		// Copy first node
		topPtr = new Node<ItemType>();
		topPtr->setItem(origChainPtr->getItem());

		// Point to last node in new chain
		Node<ItemType>* newChainPtr = topPtr;

		// Advance original-chain pointer
		origChainPtr = origChainPtr->getNext();

		// Copy remaining nodes
		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while

		newChainPtr->setNext(nullptr);               // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == nullptr;
}  // end isEmpty

#endif

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include <stdexcept> // for runtime_error
#include <string>
#include "StackInterface.h"

const int MAX_STACK = 5;

/* ARRAYSTACK INTERFACE BEGIN */
template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:
	ItemType items[MAX_STACK]; // Array of stack items
	int      top;              // Index to top of stack

public:
	ArrayStack();
	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	ItemType peek() const;
}; // end ArrayStack

/********** FUNCTIONS BELOW NEED TO BE COMPLETED **********/

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	bool didAdd = false;

	if ((top + 1) < MAX_STACK) {
		items[++top] = newEntry;
		didAdd = true;
	}

	return didAdd;
}  

/* peek() should throw a std::runtime_error exception if the stack is empty. */
template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
	if (top == -1) {
		throw std::runtime_error("ERROR: You tried to peek an empty stack!");
	}

	return items[top];
} 

template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
	bool didRemove = false;

	if (top != -1) {
		top--;
		didRemove = true;
	}

	return didRemove;
}  

/********** EVERYTHING BELOW THIS LINE IS COMPLETE **********/

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
}  // end default constructor

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;
}  // end isEmpty



#endif
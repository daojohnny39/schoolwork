/** ADT queue: Link-based implementation.
 @file LinkedQueue.hpp */
#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include <memory>
#include <stdexcept>
#include <iostream>
#include "QueueInterface.h"
#include "Node.hpp"

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
   // The queue is implemented as a chain of linked nodes that has 
   // two external pointers, a head pointer for front of the queue and
   // a tail pointer for the back of the queue.
   std::shared_ptr<Node<ItemType>> backPtr;
   std::shared_ptr<Node<ItemType>> frontPtr;

public:
   LinkedQueue();
   LinkedQueue  (const LinkedQueue& aQueue);
   ~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const;
}; // end LinkedQueue

/********** FUNCTIONS BELOW NEED TO BE COMPLETED **********/

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
    if (frontPtr == nullptr) {
        return true;
    }
    else {
        return false;
    }
} 

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    bool didQueue = false;
    auto curPtr = std::make_shared<Node<ItemType>>(newEntry);

    if (isEmpty()) {
        frontPtr = curPtr;
        backPtr = curPtr;
        didQueue = true;
    }
    else {
        backPtr->setNext(curPtr);
        backPtr = curPtr;
        didQueue = true;
    }

    return didQueue;
}  

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const
{
    ItemType temp;

    if (isEmpty()) {
        throw std::runtime_error("No items in Queue!");
    }
    else {
        temp = frontPtr->getItem();
    }

    return temp;
} 

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
    bool didRemove = false;

    if (!isEmpty()) {
        frontPtr = frontPtr->getNext();
        didRemove = true;

        if (frontPtr == nullptr) {
            backPtr = nullptr;
        }
    }

    return didRemove;
} 

/********** EVERYTHING BELOW THIS LINE IS COMPLETE **********/

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{     }  // end default constructor

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue)
{  // Implementation left as an exercise (Exercise 1).
   auto origChainPtr = aQueue.frontPtr;  // Points to nodes in original chain
   
   // Using shared pointers initializes frontPtr/backPtr to nullPtr
   if (origChainPtr != nullptr)
   {
      // Copy first node
      frontPtr = std::make_shared<Node<ItemType>>();
      frontPtr->setItem(origChainPtr->getItem());
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext(); 

      // Copy remaining nodes
      auto newChainTailPtr = frontPtr;        // Points to last node in new chain
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item 
         auto newNodePtr = std::make_shared<Node<ItemType>>(nextItem);
         
         // Link new node to end of new chain
         newChainTailPtr->setNext(newNodePtr);
         
         // Advance pointers       
         newChainTailPtr = newChainTailPtr->getNext();
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainTailPtr->setNext(nullptr);               // Flag end of chain
      backPtr = newChainTailPtr;
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
   //smart pointers will clean-up
   backPtr == nullptr;
   frontPtr == nullptr;
}  // end destructor



#endif

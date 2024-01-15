//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file Node.h 
    Listing 4-1 */
#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   // STEP 2 - DONE
   Node<ItemType>* prev;
   
public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(Node<ItemType>* nextNodePtr);
   void setPrev(Node<ItemType>* prevNodePtr);
   ItemType getItem() const ;
   Node<ItemType>* getNext() const ;
   Node<ItemType>* getPrev();
}; // end Node

// STEP 3 - DONE
template<class ItemType>
Node<ItemType>::Node() : next(nullptr), prev(nullptr)
{
}

// STEP 3 - DONE
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr), prev(nullptr)
{
}

// STEP 3 - DONE
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr) :
                item(anItem), next(nextNodePtr), prev(prevNodePtr)
{
} 

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
} 

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
   next = nextNodePtr;
} 

// STEP 4 - DONE
template<class ItemType>
void Node<ItemType>::setPrev(Node<ItemType>* prevNodePtr)
{
   prev = prevNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
   return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
   return next;
} 

// STEP 5 - DONE
template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrev()
{
   return prev;
} 

#endif
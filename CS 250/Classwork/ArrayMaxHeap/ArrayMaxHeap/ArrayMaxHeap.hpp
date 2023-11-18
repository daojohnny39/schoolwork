//  Created by Frank M. Carrano and Tim Henry.
#ifndef ARRAY_MAX_HEAP_
#define ARRAY_MAX_HEAP_

#include "HeapInterface.h"
#include <memory>
#include <cmath> // for log2
#include <stdexcept> // for logic_error
#include <algorithm> // for swap

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{
private:
   static const int ROOT_INDEX = 0;        // Helps with readability
   static const int DEFAULT_CAPACITY = 8; // Small capacity to test for a full heap
   std::unique_ptr<ItemType []> items;                        // Array of heap items
   int itemCount;                          // Current count of heap items
   int maxItems;                           // Maximum capacity of the heap
   
   // ---------------------------------------------------------------------
   // Most of the private utility methods use an array index as a parameter
   // and in calculations. This should be safe, even though the array is an
   // implementation detail, since the methods are private.
   // ---------------------------------------------------------------------
   
   // Returns the array index of the left child (if it exists).
   int getLeftChildIndex(const int nodeIndex) const;
   
   // Returns the array index of the right child (if it exists).
   int getRightChildIndex(int nodeIndex) const;
   
   // Returns the array index of the parent node.
   int getParentIndex(int nodeIndex) const;
   
   // Tests whether this node is a leaf.
   bool isLeaf(int nodeIndex) const;
   
   // Converts a semiheap to a heap.
   void heapRebuild(int subTreeRootIndex);
   
   // Creates a heap from an unordered array.
   void heapCreate();
     
public:
   ArrayMaxHeap();
   ArrayMaxHeap(const ItemType someArray[], const int arraySize);
   virtual ~ArrayMaxHeap();
   
   // HeapInterface Public Methods:
   bool isEmpty() const;
   int getNumberOfNodes() const;
   int getHeight() const;
   ItemType peekTop() const;
   bool add(const ItemType& newData);
   bool remove();
   void clear();
}; // end ArrayMaxHeap

/********** FUNCTIONS BELOW NEED TO BE COMPLETED **********/

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData)
{
    
    bool didAdd = false;

    if (itemCount < maxItems) {
        items[itemCount] = newData;

        int newIndex = itemCount;

        while ((newIndex > 0) && (items[newIndex] > items[getParentIndex(newIndex)])) {
            std::swap(items[newIndex], items[getParentIndex(newIndex)]);
            newIndex = getParentIndex(newIndex);
        }

        itemCount++;
        didAdd = true;
    }
    
    return didAdd;

}  

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(const int subTreeNodeIndex)
{
   
    if (!isLeaf(subTreeNodeIndex)) {
        int largerChild = getLeftChildIndex(subTreeNodeIndex);

        if ((getRightChildIndex(subTreeNodeIndex) < itemCount) && (items[largerChild] < items[getRightChildIndex(subTreeNodeIndex)])) {
            largerChild = getRightChildIndex(subTreeNodeIndex);
        }

        if (items[largerChild] > items[subTreeNodeIndex]) {
            std::swap(items[largerChild], items[subTreeNodeIndex]);
            heapRebuild(largerChild);
        }

    }

}  

/********** EVERYTHING BELOW THIS LINE IS COMPLETE **********/

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
   return ceil(log2(itemCount + 1));
}  // end getHeight

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const
{
   if (isEmpty())
      throw std::logic_error("Attempted peek into an empty heap.");
   
   return items[0];
} // end peekTop

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
   return itemCount;
}  // end getNumberOfNodes

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
    return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
    return (2 * nodeIndex) + 2;
}  // end getRightChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
    return (nodeIndex - 1) / 2;
}  // end getParentIndex

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(const int nodeIndex) const
{
    return (getLeftChildIndex(nodeIndex) >= itemCount);
}  // end isLeaf

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
    for (int index = itemCount / 2; index >= 0; index--)
    {
        heapRebuild(index);
    }  // end for
}  // end heapCreate

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
    items = std::make_unique<ItemType[]>(DEFAULT_CAPACITY);
}  // end default constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::
ArrayMaxHeap(const ItemType someArray[], const int arraySize) :
    itemCount(arraySize), maxItems(2 * arraySize)
{
    // Allocate the array
    items = std::make_unique<ItemType[]>(2 * arraySize);


    // Copy given values into the array
    for (int i = 0; i < itemCount; i++)
        items[i] = someArray[i];

    // Reorganize the array into a heap
    heapCreate();
} // end constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
    items.reset();
}  // end destructor

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
    itemCount = 0;
}  // end clear


template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
    bool isSuccessful = false;
    if (!isEmpty())
    {
        items[ROOT_INDEX] = items[itemCount - 1];
        itemCount--;
        heapRebuild(ROOT_INDEX);
        isSuccessful = true;
    }  // end if

    return isSuccessful;
}  // end remove

#endif

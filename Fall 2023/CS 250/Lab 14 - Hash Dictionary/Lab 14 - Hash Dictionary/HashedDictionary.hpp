#ifndef HASHED_DICTIONARY_
#define HASHED_DICTIONARY_

#include "HashedEntry.hpp"
#include <memory>
#include <cmath>    // For sqrt
#include <iostream> // For testing
#include <unordered_map>
#include <stdexcept>

template <class KeyType, class ItemType>
using hashTableType = std::shared_ptr<HashedEntry<KeyType, ItemType>>[];

template <class KeyType, class ItemType>
class HashedDictionary 
{
private:
   // creates a unique pointer to an array of shared HashedEntry pointers
   std::unique_ptr<hashTableType<KeyType, ItemType>> hashTable;  // Array of pointers to entries
   int itemCount;                               // Count of dictionary entries
   int hashTableSize;                           // Table size must be prime
   static const int DEFAULT_CAPACITY = 101;
   
   void destroyDictionary();   
   int getHashIndex(const KeyType& itemKey) const;   
   int getNextPrime(int number) const;
   bool isPrime(int number) const;
   
public:   
   HashedDictionary();
   HashedDictionary(int maxNumberOfEntries);
   HashedDictionary(const HashedDictionary<KeyType, ItemType>& dict);
   
   virtual ~HashedDictionary();
   
   bool isEmpty() const;   
   int getNumberOfItems() const;   
   void clear();   
   bool add(const KeyType& itemKey, const ItemType& newItem);   
   bool remove(const KeyType& itemKey);
   ItemType getItem(const KeyType& itemKey) const;   
   bool contains(const KeyType& itemKey) const;   
   void traverse(void visit(ItemType&)) const;   
}; // end HashedDictionary

//////////////////////////////////////////////////////////////////////
// Private helper methods
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::destroyDictionary()
{
    for (int i = 0; i < hashTableSize; i++)
    {
        // If there are hashed entries at this location,
        // we need to delete them
        while (hashTable[i] != nullptr)
        {
            hashTable[i] = hashTable[i]->getNext();
        }  // end while
    }  // end for

    itemCount = 0;
}  // end destroyDictionary

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& key) const
{

    // STEP 2
    return key % hashTableSize;

} // end getHashIndex

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNextPrime(int number) const
{
    bool foundPrime = false;
    if ((number % 2) == 0)
        number++;

    while (!foundPrime)
    {
        if ((number % 5 == 0) || !isPrime(number))
        {
            number = number + 2;
        }
        else
            foundPrime = true;
    }  // end

    return number;
}  // end getNextPrime

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isPrime(int number) const
{
    bool isPrimeNumber = true;                 // Assume prime, prove otherwise

    if ((number == 2) || (number == 3))        // Smallest primes
        isPrimeNumber = true;
    else
    {
        if ((number % 2 == 0) || (number < 2))  // Even number or ineligible
            isPrimeNumber = false;
        else
        {
            int root = sqrt(number);             // Limit of search
            int i = 3;
            do
            {
                if (number % i == 0)               // Not prime
                    isPrimeNumber = false;
                else
                    i = i + 2;

            } while ((isPrimeNumber == true) && (i <= root));
        }  // end if
    }  // endif

    return isPrimeNumber;
}  // end isPrime

//////////////////////////////////////////////////////////////////////
// Constructors & Destructor
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
    :itemCount(0), hashTableSize(DEFAULT_CAPACITY)
{
    // All shared pointers in array initialized to nullptr & reference count zero
    hashTable = std::make_unique<hashTableType<KeyType, ItemType>>(DEFAULT_CAPACITY);
}  // end

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(int maxNumberOfEntries)
    :itemCount(0)
{
    hashTableSize = getNextPrime(maxNumberOfEntries);

    // All shared pointers in array initialized to nullptr & reference count zero
    hashTable = std::make_unique<hashTableType<KeyType, ItemType>>(hashTableSize);
}  // end

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(const
    HashedDictionary<KeyType, ItemType>& dict)
    :itemCount(dict.itemCount), hashTableSize(dict.hashTableSize)
{
    hashTable = std::make_unique<hashTableType<KeyType, ItemType>>(dict.maxItems);
    for (auto index : dict.itemCount)
    {
        hashTable[index] = dict.hashTable[index];
    }  // end for
}  // end 

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary()
{
    destroyDictionary();
} // end destructor

////////////////////////////////////////////////////////////////////
// Status and public maintenance (clear) methods
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const
{
    return (itemCount == 0);
} // end isEmpty

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const
{
    return itemCount;
} // end getNumberOfItems

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear()
{
    destroyDictionary();
} // end clear

///////////////////////////////////////////////////////////////////
// Container methods (add, remove, getItem, contains, traverse)
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{

    // STEP 3
    auto p = std::make_shared<HashedEntry<KeyType, ItemType>>(searchKey, newItem);
    int i = getHashIndex(searchKey);

    if (hashTable[i] == nullptr) {
        hashTable[i] = p;
    }
    else {
        p->setNext(hashTable[i]);
        hashTable[i] = p;
    }
    itemCount++;
    return true;

} // end add

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType& searchKey)
{
    int i = getHashIndex(searchKey);

    if (hashTable[i] != nullptr) {
        if (hashTable[i]->getKey() == searchKey) {
            hashTable[i] = hashTable[i]->getNext();
            itemCount--;
            return true;
        }
        else {
            auto curPtr = hashTable[i]->getNext();
            std::shared_ptr<HashedEntry<KeyType, ItemType>> prevPtr = hashTable[i];

            while (curPtr == nullptr && curPtr->getKey() != searchKey) {
                prevPtr = curPtr;
                curPtr = curPtr->getNext();
            }

            if (curPtr != nullptr) {
                prevPtr->setNext(curPtr->getNext());
                itemCount--;
                return true;
            }

        }
    }
    
    return false;

} // end remove

template <class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const
{

    // STEP 5
    int i = getHashIndex(searchKey);
    auto curPtr = hashTable[i];

    while (curPtr != nullptr) {
        if (curPtr->getKey() == searchKey) {
            return curPtr->getItem();
        }
        curPtr = curPtr->getNext();
    }
    
    throw std::logic_error("Item is not in the dictionary!");


} // end getItem

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const
{

    // STEP 6
    int i = getHashIndex(searchKey);
    auto curPtr = hashTable[i];
    
    while (curPtr != nullptr) {
        if (curPtr->getKey() == searchKey) {
            return true;
        }
        curPtr = curPtr->getNext();
    }

    return false;
} // end contains

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{

    // STEP 7
    for (int i = 0; i < hashTableSize; i++) {
        auto curPtr = hashTable[i];
        
        while (curPtr != nullptr) {
            ItemType curItem = curPtr->getItem();
            visit(curItem);
            curPtr = curPtr->getNext();
        }
    }


}  //end traverse

#endif

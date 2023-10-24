#ifndef NODE_
#define NODE_

#include <memory>

template<class ItemType>
class Node
{
private:
    ItemType        item; // A data item
    std::shared_ptr<Node<ItemType>> next; // Pointer to next node

public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr);
    ItemType getItem() const;
    auto getNext() const;

}; // end Node

template<class ItemType>
Node<ItemType>::Node()
{
} // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem)
{
} // end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem,
    std::shared_ptr<Node<ItemType>> nextNodePtr)
    : item(anItem), next(nextNodePtr)
{
} // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType>> nextNodePtr)
{
    next = nextNodePtr;
} // end setNext

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
} // end getItem

template<class ItemType>
auto Node<ItemType>::getNext() const
{
    return next;
} // end getNext


#endif
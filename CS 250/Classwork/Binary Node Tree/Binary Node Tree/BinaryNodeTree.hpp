/** ADT binary tree: Link-based implementation.
 @file BinaryNodeTree.hpp */
 
#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include <memory>
#include <iostream>
#include <stdexcept>
#include <algorithm> // for max()
#include "BinaryTreeInterface.h"
#include "BinaryNode.hpp"

 /* BEGIN BINARYNODETREE INTERFACE */

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
   std::shared_ptr<BinaryNode<ItemType>> rootPtr;
   
protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------
   
   int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
   int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
   
   // Recursively adds a new node to the tree in a left/right fashion to
   // keep the tree balanced.
   auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                     std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
   
   // Copies values up the tree to overwrite value in current node until
   // a leaf is reached; the leaf is then removed, since its value is
   // stored in the parent.
   std::shared_ptr<BinaryNode<ItemType>> moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
   
   // Removes the target value from the tree by calling moveValuesUpTree
   // to overwrite value with value from child.
   virtual std::shared_ptr<BinaryNode<ItemType>>
               removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                     const ItemType target, bool& success);
   
   // Recursively searches for target value in the tree by using a
   // preorder traversal.
   //CHANGE BACK
   std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                  const ItemType& target) const;
   
   // Copies the tree rooted at treePtr and returns a pointer to
   // the copy.
   std::shared_ptr<BinaryNode<ItemType>> copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
   
   // Recursively deletes all nodes from the tree.
   void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
   
   // Recursive traversal helper methods:
   void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
   void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
   void postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
   
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinaryNodeTree();
   BinaryNodeTree(const ItemType& rootItem);
   BinaryNodeTree(const ItemType& rootItem,
                   const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                   const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
   BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
   virtual ~BinaryNodeTree();
   
   //------------------------------------------------------------
   // Public BinaryTreeInterface Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const;
   int getHeight() const;
   int getNumberOfNodes() const;
   ItemType getRootData() const;
   void setRootData(const ItemType& newData);
   bool add(const ItemType& newData); // Adds a node
   bool remove(const ItemType& data); // Removes a node
   void clear();
   ItemType getEntry(const ItemType& anEntry) const;
   bool contains(const ItemType& anEntry) const;
   
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void preorderTraverse(void visit(ItemType&)) const;
   void inorderTraverse(void visit(ItemType&)) const;
   void postorderTraverse(void visit(ItemType&)) const;
   
   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
}; // end BinaryNodeTree

//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

/********** FUNCTIONS BELOW NEED TO BE COMPLETED **********/

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{

    int count = 0;

    if (subTreePtr != nullptr) {
        count = 1;
        count += getNumberOfNodesHelper(subTreePtr->getLeftChildPtr());
        count += getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    }

    return count;

}  

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    
    int height = 0;

    if (subTreePtr != nullptr) {
        height = 1;
        int leftSubHeight = getHeightHelper(subTreePtr->getLeftChildPtr());
        int rightSubHeight = getHeightHelper(subTreePtr->getRightChildPtr());
        height += std::max(leftSubHeight, rightSubHeight);
    }

    return height;

}

//CHANGE BACK TO AUTO
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
    const ItemType& target) const
{
    std::shared_ptr<BinaryNode<ItemType>> resultPtr;
    
    if (treePtr == nullptr) {
        resultPtr = nullptr;
    }
    else {
        if (treePtr->getItem() == target) {
            resultPtr == treePtr;
        }
        else {
            resultPtr = findNode(treePtr->getLeftChildPtr(), target);

            if (resultPtr == nullptr) {
                resultPtr = findNode(treePtr->getRightChildPtr(), target);
            }
        }
    }

    return resultPtr;

}  

template<class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
    std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    
    // STUB - Finish me!

    return newNodePtr;

}  // end balancedAdd

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
    
    // STUB - Finish me!

}  // end inorder

template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{

    // STUB - Finish me!

}  // end preorder

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
    
    // STUB - Finish me!

}  // end postorder

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
    
    // STUB - Finish me!

    return oldTreeRootPtr;

}  // end copyTree

/********** EVERYTHING BELOW THIS LINE IS COMPLETE **********/

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    auto  leftPtr = subTreePtr->getLeftChildPtr();
    auto  rightPtr = subTreePtr->getRightChildPtr();
    int leftHeight = getHeightHelper(leftPtr);
    int rightHeight = getHeightHelper(rightPtr);
    if (leftHeight > rightHeight)
    {
        subTreePtr->setItem(leftPtr->getItem());
        leftPtr = moveValuesUpTree(leftPtr);
        subTreePtr->setLeftChildPtr(leftPtr);
        return subTreePtr;
    }
    else
    {
        if (rightPtr != nullptr)
        {
            subTreePtr->setItem(rightPtr->getItem());
            rightPtr = moveValuesUpTree(rightPtr);
            subTreePtr->setRightChildPtr(rightPtr);
            return subTreePtr;
        }
        else
        {
            //this was a leaf!
            // value not important
            return nullptr;
        }  // end if
    }  // end if   
}  // end moveValuesUpTree

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
    const ItemType target,
    bool& success)
{
    if (subTreePtr == nullptr) // not found here
        return subTreePtr;

    if (subTreePtr->getItem() == target) // found it
    {
        subTreePtr = moveValuesUpTree(subTreePtr);
        success = true;
        return subTreePtr;
    }
    else
    {
        auto targetNodePtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
        subTreePtr->setLeftChildPtr(targetNodePtr);
        if (!success) // no need to search right subTree
        {
            targetNodePtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
            subTreePtr->setRightChildPtr(targetNodePtr);
        }  // end if

        return subTreePtr;
    }  // end if
}  // end removeValue

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
{  }  // end default constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
   :rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{  }  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                          const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                                          const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
      :rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem,
                                                copyTree(leftTreePtr->rootPtr),
                                                copyTree(rightTreePtr->rootPtr)))
{   }  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
   rootPtr = copyTree(treePtr.rootPtr);
}  // end copy constructor

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
    clear();
}  // end destructor

template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
   return rootPtr == nullptr;
}  // end isEmpty

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
   return getHeightHelper(rootPtr);
}  // end getHeight

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
   return getNumberOfNodesHelper(rootPtr);
}  // end getNumberOfNodes

template<class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
    rootPtr = nullptr;
}  // end clear

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const
{
   if (isEmpty())
      throw std::runtime_error("getRootData() called with empty tree."); 
      
   return rootPtr->getItem();
}  // end getRootData

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newItem)
{
   if (isEmpty())
      rootPtr = std::make_shared<BinaryNode<ItemType>>(newItem, nullptr, nullptr);
   else
      rootPtr->setItem(newItem);
}  // end setRootData

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
   auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
   rootPtr = balancedAdd(rootPtr, newNodePtr);
   return true;
}  // end add

template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& target)
{
   bool isSuccessful = false;
   rootPtr = removeValue(rootPtr, target, isSuccessful);
   return isSuccessful; 
}  // end remove

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const
{

   auto binaryNodePtr = findNode(rootPtr, anEntry);
   
   if (binaryNodePtr != nullptr)
      return binaryNodePtr->getItem(); 
   else 
      throw std::logic_error("Entry not found in tree!");
}  // end getEntry

template<class ItemType>
bool BinaryNodeTree<ItemType>:: contains(const ItemType& anEntry) const
{
   auto resultPtr = findNode(rootPtr, anEntry);
   
   return (resultPtr != nullptr);
}  // end contains

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
   preorder(visit, rootPtr);
}  // end preorderTraverse

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
   inorder(visit, rootPtr);
}  // end inorderTraverse

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
   postorder(visit, rootPtr);
}  // end postorderTraverse

template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(
                                                const BinaryNodeTree<ItemType>& rightHandSide)
{
   if (!isEmpty())
      clear();

   /* this is a pointer to the object on the lefthand side of the =.
      Code below replace object on the lefthand side with a pointer to
      a copy of the rightHandSide tree. */
   this = copyTree(&rightHandSide);

   /* To allow for chained =, we need to also return a copy of the object
      on the lefthand side of the =, which is the object this code is running
      in. */
   return *this;
}  // end operator=


#endif

#include "Book.h"


Book::Book() : title(nullptr), leftChildPtr(nullptr), rightChildPtr(nullptr)
{
} // end default constructor


Book::Book(const std::string& theTitle) 
    : title(theTitle), leftChildPtr(nullptr), rightChildPtr(nullptr)
{
} // end constructor


Book::Book(const std::string& theTitle, 
    std::shared_ptr<Book> leftPtr,
    std::shared_ptr<Book> rightPtr)
    : title(theTitle), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{
} // end constructor


void Book::setTitle(const std::string& theTitle)
{
   title = theTitle;
} // end setItem


void Book::setLeftChildPtr(std::shared_ptr<Book> leftPtr)
{
    leftChildPtr = leftPtr;
} // end setLeftChildPtr

void Book::setRightChildPtr(std::shared_ptr<Book> rightPtr)
{
    rightChildPtr = rightPtr;
} // end setRightChildPtr

std::string Book::getTitle() const
{
   return title;
} // end getItem


std::shared_ptr<Book> Book::getLeftChildPtr() const
{
   return leftChildPtr;
} // end getLeftChildPtr

std::shared_ptr<Book> Book::getRightChildPtr() const
{
    return rightChildPtr;
} // end getRightChildPtr

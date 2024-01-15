#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <memory>

class Book
{
private:
   std::string title; // The book title
   std::shared_ptr<Book> leftChildPtr; 
   std::shared_ptr<Book> rightChildPtr;
   
public:
   Book();
   Book(const std::string& theTitle);
   Book(const std::string& theTitle,
       std::shared_ptr<Book> leftPtr,
       std::shared_ptr<Book> rightPtr);
   void setTitle(const std::string& theTitle);
   void setLeftChildPtr(std::shared_ptr<Book> leftPtr);
   void setRightChildPtr(std::shared_ptr<Book> rightPtr);
   std::string getTitle() const ;
   std::shared_ptr<Book> getLeftChildPtr() const;
   std::shared_ptr<Book> getRightChildPtr() const;
}; // end Book

#endif
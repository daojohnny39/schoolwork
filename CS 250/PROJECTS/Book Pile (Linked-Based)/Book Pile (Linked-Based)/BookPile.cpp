#include "BookPile.h"

BookPile::BookPile(): headptr(nullptr) {}

BookPile::BookPile(std::vector<std::string> existingBooks) {

}

bool BookPile::addBook(const std::string & addedBook) {
	Book* newBook = new Book(addedBook);
	if (headptr == nullptr) {
		headptr = newBook;
	}
	else {
		Book* curPtr = headptr;
		while (curPtr->getTitle().length() < curPtr->getNext()->getTitle().length()) {
			curPtr = curPtr->getNext();
		}
	}
}




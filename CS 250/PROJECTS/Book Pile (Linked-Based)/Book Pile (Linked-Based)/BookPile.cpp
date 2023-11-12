#include "BookPile.h"

BookPile::BookPile(): headptr(nullptr) {}

BookPile::BookPile(std::vector<std::string> existingBooks): headptr(nullptr) {
	for (int i = 0; i < existingBooks.size(); i++) {
		addBook(existingBooks[i]);
	}
}

void BookPile::displayPile() {
	Book* curPtr = headptr;


}

bool BookPile::addBook(const std::string & addedBook) {

	Book* newBook = new Book(addedBook);

	if (addedBook == "") {
		return false;
	}

	if (headptr == nullptr) {
		headptr = newBook;
	}
	else {
		Book* curPtr = headptr;
		Book* prevPtr = nullptr;

		while (curPtr != nullptr && // making sure curPtr doesn't drift
			(curPtr->getTitle().length() > addedBook.length() || // checking if current book length is greater than addedBook
				(curPtr->getTitle().length() == addedBook.length() && curPtr->getTitle() > addedBook))) {	// checking if same length and if book title is greater than addedBook title

			prevPtr = curPtr;
			curPtr = curPtr->getNext();
		}
		if (prevPtr == nullptr) {
			newBook->setNext(headptr);
			headptr = newBook;
		}
		else {
			prevPtr->setNext(newBook);
			newBook->setNext(curPtr);
		}
	}
	return true;
}




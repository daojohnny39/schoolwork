#include "BookPile.h"
#include <iostream>

BookPile::BookPile(): headptr(nullptr), bookCount(0) {}

BookPile::BookPile(std::vector<std::string> existingBooks): headptr(nullptr), bookCount(0) {
	for (int i = 0; i < existingBooks.size(); i++) {
		addBook(existingBooks[i]);
	}
}

void BookPile::displayPile() {
	if (headptr == nullptr) {
		std::cout << "Book pile is empty." << std::endl;
	}
	else {
		Book* curPtr = headptr;
		int counter = 1;

		while (curPtr != nullptr) {
			std::cout << counter << ". " << curPtr->getTitle() << " (" << curPtr->getTitle().length() << ")" << std::endl;
			counter++;
			curPtr = curPtr->getNext();
		}
	}
}

bool BookPile::addBook(const std::string & addedBook) {

	Book* newBook = new Book(addedBook);

	// checking if book is empty
	if (addedBook == "") {
		return false;
	}

	// checking if list is empty
	if (headptr == nullptr || addedBook == "") {
		headptr = newBook;
	}
	else {
		// checking if duplicate
		Book* checkPtr = headptr;
		while (checkPtr != nullptr) {
			if (addedBook == checkPtr->getTitle()) {
				return false;
			}
			checkPtr = checkPtr->getNext();
		}

		Book* curPtr = headptr;
		Book* prevPtr = nullptr;

		while (curPtr != nullptr && // making sure curPtr doesn't drift
			(curPtr->getTitle().length() > addedBook.length() || // checking if current book length is greater than addedBook
				(curPtr->getTitle().length() == addedBook.length() && curPtr->getTitle() < addedBook))) {	// checking if same length and if book title is greater than addedBook title

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
	bookCount++;
	return true;
}

bool BookPile::removeBook(const std::string& bookToRemove) {
	if (headptr == nullptr) {
		return false;
	}
	else {

		Book* curPtr = headptr;
		Book* prevPtr = nullptr;

		while (curPtr != nullptr) {
			if (bookToRemove == curPtr->getTitle()) {
				if (prevPtr == nullptr) {
					headptr = curPtr->getNext();
				}
				else {
					prevPtr->setNext(curPtr->getNext());
				}
				delete curPtr;
				bookCount--;
				return true;
			}
			prevPtr = curPtr;
			curPtr = curPtr->getNext();
		}

	}
}

bool BookPile::removePosition(int positionToRemove) {

	if (headptr == nullptr || positionToRemove < 0) {
		return false;
	}
	else {

		Book* curPtr = headptr;
		Book* prevPtr = nullptr;
		int counter = 1;

		// traversing to position
		while (curPtr != nullptr && counter < positionToRemove) {
			prevPtr = curPtr;
			curPtr = curPtr->getNext();
			counter++;
		}

		// can't remove non-existent book
		if (curPtr == nullptr) {
			return false;
		}
		else {
			// checking if there is only 1 book in list
			if (prevPtr == nullptr) {
				headptr = curPtr->getNext();
			}
			else {
				prevPtr->setNext(curPtr->getNext());
			}

			delete curPtr;
			bookCount--;
			return true;
		}

	}
}

int BookPile::bookPosition(std::string bookName) {

	if (headptr == nullptr) {
		return -1;
	}
	else {

		Book* curPtr = headptr;
		int counter = 1;

		while (curPtr != nullptr) {
			if (bookName == curPtr->getTitle()) {
				return counter;
			}

			counter++;
			curPtr = curPtr->getNext();
		}
		return -1;
	}
}

std::string BookPile::getPosition(int positionNum) {

	if (positionNum > bookCount || positionNum < 0) {
		throw out_of_range("ERROR: Invalid position.");
	}

	int counter = 1;
	Book* curPtr = headptr;

	while (curPtr != nullptr && counter <= bookCount) {
		if (counter == positionNum) {
			return curPtr->getTitle();
		}
		counter++;
		curPtr = curPtr->getNext();
	}

}

bool BookPile::rename(std::string oldTitle, std::string newTitle) {

	if (headptr == nullptr || newTitle == "") {
		return false;
	}
	else {

		// checking if book even exists
		if (removeBook(oldTitle)) {
			addBook(newTitle);
		}
		else {
			return false;
		}

	}

}

int BookPile::size() {
	return bookCount;
}

void BookPile::clear() {

	while (headptr != nullptr) {
		removePosition(bookCount);
	}

}




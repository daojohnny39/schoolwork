#include <iostream>

#include "BookPile.h"

BookPile::BookPile() : rootPtr(nullptr), bookCount(0) {}

BookPile::BookPile(std::vector<std::string> existEntries) {
	for (int i = 0; i < existEntries.size(); i++) {
		addBook(existEntries[i]);
	}
}

void BookPile::displayPile() {
	inOrderTraversal(rootPtr);
	std::cout << std::endl;
}

bool BookPile::addBook(std::string newEntry) {
	/* --------- INITIAL CHECKS --------- */
	if (newEntry.empty()) {
		return false;
	}

	auto newBook = std::make_shared<Book>(newEntry);

	if (rootPtr == nullptr) {
		rootPtr = newBook;
		bookCount++;

		return true;
	}
	/* --------- INITIAL CHECKS END --------- */

	/* --------- FINDING POSITION --------- */
	std::shared_ptr<Book> curPtr = rootPtr;
	std::shared_ptr<Book> parPtr = nullptr;
	bool isLeftChild = true;

	while (curPtr != nullptr) {
		parPtr = curPtr;

		// Checking for duplicate
		if (newEntry == curPtr->getTitle()) {
			return false;
		}
		else if ((newEntry.length() < curPtr->getTitle().length()) || // If newEntry length is less than curPtr's title length
			(newEntry.length() == curPtr->getTitle().length() && newEntry < curPtr->getTitle()) ) {	// If newEntry is = curPtr's length AND if newEntry is < curPtr

			curPtr = curPtr->getLeftChildPtr();
			isLeftChild = true;

		}
		else {
			curPtr = curPtr->getRightChildPtr();
			isLeftChild = false;
		}
	}
	/* --------- FINDING POSITION END --------- */

	/* --------- ADDING BOOK --------- */
	if (isLeftChild) {
		parPtr->setLeftChildPtr(newBook);
	}
	else {
		parPtr->setRightChildPtr(newBook);
	}

	bookCount++;
	return true;
	/* --------- ADDING BOOK END --------- */
}

bool BookPile::removeBook(std::string bookToRemove) {
	return false;
}

bool BookPile::contains(std::string book) {
	return false;
}

bool BookPile::rename(std::string oldTitle, std::string newTitle) {
	return false;
}

int BookPile::size() {
	return bookCount;
}

void BookPile::clear() {

}

bool BookPile::operator==(const BookPile& secondPile) {
	return false;
}

/* --------- HELPER FUNCTION --------- */
void BookPile::inOrderTraversal(std::shared_ptr<Book> rootPtr) {
	if (rootPtr != nullptr) {
		inOrderTraversal(rootPtr->getLeftChildPtr());
		std::cout << rootPtr->getTitle() << std::endl;
		inOrderTraversal(rootPtr->getRightChildPtr());
	}
}
/* --------- HELPER FUNCTIONS END --------- */
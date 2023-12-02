#include <iostream>

#include "BookPile.h"

BookPile::BookPile() : rootPtr(nullptr), bookCount(0) {}

BookPile::BookPile(std::vector<std::string> existEntries) {
	for (int i = 0; i < existEntries.size(); i++) {
		addBook(existEntries[i]);
	}
}

void BookPile::displayPile() {
	int count = 0;

	inOrderTraversal(rootPtr, count);
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
		
		if ((newEntry.length() < curPtr->getTitle().length()) || // If newEntry length is less than curPtr's title length
			(newEntry.length() == curPtr->getTitle().length() && newEntry > curPtr->getTitle()) ) {	// If newEntry is = curPtr's length AND if newEntry is < curPtr

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
	// CHECK: if there are any books
	if (rootPtr == nullptr) {
		return false;
	}

	// Traversal pointers:
	std::shared_ptr<Book> curPtr = rootPtr;
	std::shared_ptr<Book> parPtr = nullptr;
	bool isLeftChild = true;

	// Finding position
	while ( (curPtr != nullptr) && (curPtr->getTitle() != bookToRemove) ) {
		parPtr = curPtr;

		if (bookToRemove < curPtr->getTitle()) {
			isLeftChild = true;
			curPtr = curPtr->getLeftChildPtr();
		}
		else {
			isLeftChild = false;
			curPtr = curPtr->getRightChildPtr();
		}
	}

	// CHECK: If book was never found
	if (curPtr == nullptr) {
		return false;
	}

	// CHECK: If curPtr is a leaf
	if ((curPtr->getLeftChildPtr() == nullptr) && (curPtr->getRightChildPtr() == nullptr)) {
		// If rootPtr is getting removed
		if (curPtr == rootPtr) {
			rootPtr = nullptr;
		}
		else if (isLeftChild) {
			parPtr->setLeftChildPtr(nullptr);
		}
		else {
			parPtr->setRightChildPtr(nullptr);
		}
	}	// CHECK: If curPtr only has a left child:
	else if (curPtr->getRightChildPtr() == nullptr) {
		if (curPtr == rootPtr) {
			rootPtr = curPtr->getLeftChildPtr();
		}
		else if (isLeftChild) {
			parPtr->setLeftChildPtr(curPtr->getLeftChildPtr());
		}
		else {
			parPtr->setRightChildPtr(curPtr->getLeftChildPtr());
		}
	}	// CHECK: If curPtr only has a right child:
	else if (curPtr->getLeftChildPtr() == nullptr) {
		if (curPtr == rootPtr) {
			rootPtr = curPtr->getRightChildPtr();
		}
		else if (isLeftChild) {
			parPtr->setLeftChildPtr(curPtr->getRightChildPtr());
		}
		else {
			parPtr->setRightChildPtr(curPtr->getRightChildPtr());
		}
	}	// By this point, curPtr has two children:
	else {
		// #################
		std::shared_ptr<Book> successor = curPtr->getRightChildPtr();
		std::shared_ptr<Book> successorPar = curPtr;

		// #################
		while (successor->getLeftChildPtr() != nullptr) {
			successorPar = successor;
			successor = successor->getLeftChildPtr();
		}

		curPtr->setTitle(successor->getTitle());

		if (successorPar != curPtr) {
			successorPar->setLeftChildPtr(successor->getRightChildPtr());
		}
		else {
			curPtr->setRightChildPtr(successor->getRightChildPtr());
		}
	}

	bookCount--;
	return true;
}

bool BookPile::contains(std::string book) {
	std::shared_ptr<Book> curPtr = rootPtr;

	while (curPtr != nullptr) {
		if (curPtr->getTitle() == book) {
			return true;
		}
		else if (book < curPtr->getTitle()) {
			curPtr = curPtr->getLeftChildPtr();
		}
		else {
			curPtr = curPtr->getRightChildPtr();
		}
	}

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
void BookPile::inOrderTraversal(std::shared_ptr<Book> rootPtr, int& count) {
	if (rootPtr != nullptr) {
		inOrderTraversal(rootPtr->getRightChildPtr(), count);
		std::cout << ++count << ". " << rootPtr->getTitle() << " (" << rootPtr->getTitle().length() << ")" << std::endl;
		inOrderTraversal(rootPtr->getLeftChildPtr(), count);
	}
}
/* --------- HELPER FUNCTIONS END --------- */
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
		
		if ((newEntry.length() > curPtr->getTitle().length()) || // If newEntry length is less than curPtr's title length
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
	std::shared_ptr<Book> curPtr = rootPtr;
	std::shared_ptr<Book> parPtr = nullptr;
	bool isLeftChild = true;

	// Finding Book
	while (curPtr != nullptr) {
		if (bookToRemove == curPtr->getTitle()) {
			break;
		}

		parPtr = curPtr;

		if ( (bookToRemove.length() > curPtr->getTitle().length()) ||
			(bookToRemove.length() == curPtr->getTitle().length() && bookToRemove > curPtr->getTitle()) ) {

			curPtr = curPtr->getLeftChildPtr();
			isLeftChild = true;
		}
		else {
			curPtr = curPtr->getRightChildPtr();
			isLeftChild = false;
		}
	}

	// If book doesn't exist
	if (curPtr == nullptr) {
		return false;
	}

	// If curPtr is a leaf
	if (curPtr->getLeftChildPtr() == nullptr && curPtr->getRightChildPtr() == nullptr) {
		if (curPtr != rootPtr) {
			if (isLeftChild) {
				parPtr->setLeftChildPtr(nullptr);
			}
			else {
				parPtr->setRightChildPtr(nullptr);
			}
		}
		else {
			rootPtr = nullptr;
		}
	}

	// If curPtr has two children
	else if (curPtr->getLeftChildPtr() != nullptr && curPtr->getRightChildPtr() != nullptr) {
		std::shared_ptr<Book> succPtr = findMinimumNode(curPtr->getRightChildPtr());
		std::string succTitle = succPtr->getTitle();
		removeBook(succTitle);
		curPtr->setTitle(succTitle);
	}

	// If curPtr only has one child
	else {
		std::shared_ptr<Book> childPtr;

		if (curPtr->getLeftChildPtr() != nullptr) {
			childPtr = curPtr->getLeftChildPtr();
		}
		else {
			childPtr = curPtr->getRightChildPtr();
		}

		if (curPtr != rootPtr) {
			if (isLeftChild) {
				parPtr->setLeftChildPtr(childPtr);
			}
			else {
				parPtr->setRightChildPtr(childPtr);
			}
		}
		else {
			rootPtr = childPtr;
		}
	}

	bookCount--;
	return true;
}

bool BookPile::contains(std::string book) {
	std::shared_ptr<Book> curPtr = rootPtr;

	while (curPtr != nullptr) {
		// CHECK: If book is rootPtr
		if (curPtr->getTitle() == book) {
			return true;
		}
		
		// Traversal
		if ( (book.length() < curPtr->getTitle().length()) ||
			(book.length() == curPtr->getTitle().length() && book > curPtr->getTitle()) ) {

			curPtr = curPtr->getLeftChildPtr();
		}
		else {
			curPtr = curPtr->getRightChildPtr();
		}
	}

	return false;
}

bool BookPile::rename(std::string oldTitle, std::string newTitle) {
	bool didRemove = removeBook(oldTitle);
	bool didAdd = addBook(newTitle);

	return (didRemove && didAdd);
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
// USED IN: displayPile()
void BookPile::inOrderTraversal(std::shared_ptr<Book> rootPtr, int& count) {
	if (rootPtr != nullptr) {
		inOrderTraversal(rootPtr->getLeftChildPtr(), count);
		std::cout << ++count << ". " << rootPtr->getTitle() << " (" << rootPtr->getTitle().length() << ")" << std::endl;
		inOrderTraversal(rootPtr->getRightChildPtr(), count);
	}
}

// USED IN: removeBook()
std::shared_ptr<Book> BookPile::findMinimumNode(std::shared_ptr<Book> node) {
	while (node->getLeftChildPtr() != nullptr) {
		node = node->getLeftChildPtr();
	}

	return node;
}
/* --------- HELPER FUNCTIONS END --------- */
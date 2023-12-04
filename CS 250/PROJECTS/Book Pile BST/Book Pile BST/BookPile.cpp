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
	if (rootPtr == nullptr) {
		return false; // Tree is empty
	}

	std::shared_ptr<Book> parentPtr = nullptr;
	std::shared_ptr<Book> currentPtr = rootPtr;
	bool isLeftChild = false;

	// Find the book to remove and its parent
	while (currentPtr != nullptr && currentPtr->getTitle() != bookToRemove) {
		parentPtr = currentPtr;
		if (bookToRemove < currentPtr->getTitle()) {
			currentPtr = currentPtr->getLeftChildPtr();
			isLeftChild = true;
		}
		else {
			currentPtr = currentPtr->getRightChildPtr();
			isLeftChild = false;
		}
	}

	if (currentPtr == nullptr) {
		return false; // Book not found
	}

	// Case 1: Removing a leaf node
	if (currentPtr->getLeftChildPtr() == nullptr && currentPtr->getRightChildPtr() == nullptr) {
		if (currentPtr == rootPtr) {
			rootPtr = nullptr; // Tree becomes empty
		}
		else if (isLeftChild) {
			parentPtr->setLeftChildPtr(nullptr);
		}
		else {
			parentPtr->setRightChildPtr(nullptr);
		}
	}
	// Case 2: Removing a node with one child
	else if (currentPtr->getLeftChildPtr() == nullptr) { // Only right child
		if (currentPtr == rootPtr) {
			rootPtr = currentPtr->getRightChildPtr();
		}
		else if (isLeftChild) {
			parentPtr->setLeftChildPtr(currentPtr->getRightChildPtr());
		}
		else {
			parentPtr->setRightChildPtr(currentPtr->getRightChildPtr());
		}
	}
	else if (currentPtr->getRightChildPtr() == nullptr) { // Only left child
		if (currentPtr == rootPtr) {
			rootPtr = currentPtr->getLeftChildPtr();
		}
		else if (isLeftChild) {
			parentPtr->setLeftChildPtr(currentPtr->getLeftChildPtr());
		}
		else {
			parentPtr->setRightChildPtr(currentPtr->getLeftChildPtr());
		}
	}
	// Case 3: Removing a node with two children
	else {
		// Find the in-order successor (smallest in the right subtree)
		std::shared_ptr<Book> successorParent = currentPtr;
		std::shared_ptr<Book> successor = currentPtr->getRightChildPtr();
		while (successor->getLeftChildPtr() != nullptr) {
			successorParent = successor;
			successor = successor->getLeftChildPtr();
		}

		// Swap titles
		std::string tempTitle = currentPtr->getTitle();
		currentPtr->setTitle(successor->getTitle());
		successor->setTitle(tempTitle);

		// Recursively remove the successor node
		if (successor == successorParent->getRightChildPtr()) {
			successorParent->setRightChildPtr(removeBookRecursive(successor->getTitle(), successorParent->getRightChildPtr()));
		}
		else {
			successorParent->setLeftChildPtr(removeBookRecursive(successor->getTitle(), successorParent->getLeftChildPtr()));
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
// USED IN: displayPile()
void BookPile::inOrderTraversal(std::shared_ptr<Book> rootPtr, int& count) {
	if (rootPtr != nullptr) {
		inOrderTraversal(rootPtr->getRightChildPtr(), count);
		std::cout << ++count << ". " << rootPtr->getTitle() << " (" << rootPtr->getTitle().length() << ")" << std::endl;
		inOrderTraversal(rootPtr->getLeftChildPtr(), count);
	}
}

std::shared_ptr<Book> BookPile::removeBookRecursive(const std::string& bookToRemove, std::shared_ptr<Book> subTreePtr) {
	if (subTreePtr == nullptr) {
		return subTreePtr; // Book not found in this subtree
	}

	if (bookToRemove == subTreePtr->getTitle()) {
		// Node with only one child or no child
		if (subTreePtr->getLeftChildPtr() == nullptr) {
			return subTreePtr->getRightChildPtr();
		}
		else if (subTreePtr->getRightChildPtr() == nullptr) {
			return subTreePtr->getLeftChildPtr();
		}

		// Node with two children: Get the in-order successor (smallest in the right subtree)
		std::shared_ptr<Book> successorParent = subTreePtr;
		std::shared_ptr<Book> successor = subTreePtr->getRightChildPtr();
		while (successor->getLeftChildPtr() != nullptr) {
			successorParent = successor;
			successor = successor->getLeftChildPtr();
		}

		// Copy the successor's title to this node and delete the successor
		subTreePtr->setTitle(successor->getTitle());
		if (successor == successorParent->getRightChildPtr()) {
			successorParent->setRightChildPtr(removeBookRecursive(successor->getTitle(), successorParent->getRightChildPtr()));
		}
		else {
			successorParent->setLeftChildPtr(removeBookRecursive(successor->getTitle(), successorParent->getLeftChildPtr()));
		}
	}
	else if (bookToRemove < subTreePtr->getTitle()) {
		subTreePtr->setLeftChildPtr(removeBookRecursive(bookToRemove, subTreePtr->getLeftChildPtr()));
	}
	else {
		subTreePtr->setRightChildPtr(removeBookRecursive(bookToRemove, subTreePtr->getRightChildPtr()));
	}

	return subTreePtr;
}
/* --------- HELPER FUNCTIONS END --------- */
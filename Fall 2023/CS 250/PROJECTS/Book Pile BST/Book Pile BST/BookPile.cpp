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

	if (bookCount == 0) {
		std::cout << "Book pile is empty." << std::endl;
	}
	else {
		inOrderTraversal(rootPtr, count);
	}
}

bool BookPile::addBook(std::string newEntry) {
	if (newEntry.empty()) {
		return false;
	}

	auto newBook = std::make_shared<Book>(newEntry);

	if (rootPtr == nullptr) {
		rootPtr = newBook;
		bookCount++;

		return true;
	}

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

	if (isLeftChild) {
		parPtr->setLeftChildPtr(newBook);
	}
	else {
		parPtr->setRightChildPtr(newBook);
	}

	bookCount++;
	return true;
}

bool BookPile::removeBook(std::string bookToRemove) {
	bool isSuccessful = false;
	rootPtr = removeBookHelper(rootPtr, bookToRemove, isSuccessful);

	if (isSuccessful) {
		bookCount--;
	}

	return (isSuccessful);
}

bool BookPile::contains(std::string book) {
	std::shared_ptr<Book> curPtr = rootPtr;

	while (curPtr != nullptr) {
		// CHECK: If book is rootPtr
		if (curPtr->getTitle() == book) {
			return true;
		}
		
		// Traversal
		if ( (book.length() > curPtr->getTitle().length()) ||  // *line under this - Originally "book > curPtr->getTitle()"
			(book.length() == curPtr->getTitle().length() && book < curPtr->getTitle()) ) {

			curPtr = curPtr->getLeftChildPtr();
		}
		else {
			curPtr = curPtr->getRightChildPtr();
		}
	}

	return false;
}

// LOTS of comments here from debugging

bool BookPile::rename(std::string oldTitle, std::string newTitle) {
	//std::cout << " ------------------------------------ RENAME TESTING ------------------------------------ " << std::endl;

	bool didRemove = false;

	//std::cout << "REMOVE:" << std::endl;
	//std::cout << "Contain " << oldTitle << "?: " << contains(oldTitle) << std::endl;

	if (contains(oldTitle)) {
		didRemove = removeBook(oldTitle);
	}

	//std::cout << "didRemove: " << didRemove << std::endl;
	//std::cout << "Removed: " << oldTitle << std::endl;
	//std::cout << "Still contains: " << oldTitle << "? - " << contains(oldTitle) << std::endl;
	//std::cout << std::endl;

	bool didAdd = false;

	//std::cout << "Contains " << newTitle << "?: " << contains(newTitle) << std::endl;

	if (didRemove) {
		didAdd = addBook(newTitle);
	}

	//std::cout << "ADD:" << std::endl;
	//std::cout << "added Book?: " << didAdd << std::endl;
	//std::cout << "added Book: " << newTitle << std::endl;
	//std::cout << "Contains Book: " << newTitle << "? - " << contains(newTitle) << std::endl;
	//std::cout << std::endl;

	//std::cout << " ------------------------------------ RENAME TESTING END ------------------------------------ " << std::endl;

	return (didRemove && didAdd);
}

int BookPile::size() {
	return bookCount;
}

void BookPile::clear() {
	destroyTree(rootPtr);
	rootPtr = nullptr;
	bookCount = 0;
}

bool BookPile::operator==(const BookPile& secondPile) {
	std::vector<std::string> firstPileVec;
	std::vector<std::string> secondPileVec;

	treeToVector(rootPtr, firstPileVec);
	treeToVector(secondPile.rootPtr, secondPileVec);

	/*
	std::cout << "First Pile: " << std::endl;
	for (int i = 0; i < firstPileVec.size(); i++) {
		std::cout << firstPileVec[i] << std::endl;
	}

	std::cout << "Second Pile: " << std::endl;
	for (int i = 0; i < secondPileVec.size(); i++) {
		std::cout << secondPileVec[i] << std::endl;
	}
	*/

	// CHECK: if book content are the same
	bool isSameBooks = firstPileVec == secondPileVec;

	bool structureSame = isSameTree(rootPtr, secondPile.rootPtr);

	return isSameBooks && structureSame;
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

// USED IN: removeBook() ----------------------------------------------
std::shared_ptr<Book> BookPile::removeBookHelper(std::shared_ptr<Book> subTreePtr, const std::string& bookToRemove, bool& isSuccessful) {
	//std::cout << " -------------------------- removeBookHelper DEBUG -------------------------- " << std::endl;
	if (subTreePtr == nullptr) {
		//TEST
		//std::cout << "Reached a null pointer, book not found" << std::endl;

		isSuccessful = false;
		return nullptr;
	}

	//TEST
	//std::cout << "Currently at node with title: " << subTreePtr->getTitle() << std::endl;

	if (bookToRemove == subTreePtr->getTitle()) {
		//TEST
		//std::cout << "Found the book to remove: " << bookToRemove << std::endl;

		subTreePtr = removeNode(subTreePtr);
		isSuccessful = true;
	}
	else if ((bookToRemove.length() > subTreePtr->getTitle().length()) ||
		(bookToRemove.length() == subTreePtr->getTitle().length() && bookToRemove < subTreePtr->getTitle())) {
		//TEST
		//std::cout << "Going left to find the book" << std::endl;

		auto tempPtr = removeBookHelper(subTreePtr->getLeftChildPtr(), bookToRemove, isSuccessful);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else {
		//TEST
		//std::cout << "Going right to find the book" << std::endl;

		auto tempPtr = removeBookHelper(subTreePtr->getRightChildPtr(), bookToRemove, isSuccessful);
		subTreePtr->setRightChildPtr(tempPtr);
	}

	//std::cout << " -------------------------- removeBookHelper DEBUG END -------------------------- " << std::endl;
	
	return subTreePtr;
}

std::shared_ptr<Book> BookPile::removeNode(std::shared_ptr<Book> nodePtr) {
	// If node is a leaf
	if (nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() == nullptr) {
		return nullptr;
	}
	// If the node only has one child
	else if (nodePtr->getLeftChildPtr() == nullptr || nodePtr->getRightChildPtr() == nullptr) {
		auto childPtr = (nodePtr->getLeftChildPtr() != nullptr) ? nodePtr->getLeftChildPtr() : nodePtr->getRightChildPtr();

		// Messing around with ternary operator
		/*
		std::shared_ptr<Book> childPtr;

		if (nodePtr->getLeftChildPtr() != nullptr) {
			childPtr = nodePtr->getLeftChildPtr();
		}
		else {
			childPtr = nodePtr->getRightChildPtr();
		}
		*/
		
		return childPtr;
	}
	// If the node has two children
	else {
		std::string inorderSuccVal;
		auto rightChildPtr = nodePtr->getRightChildPtr();
		auto tempPtr = removeLeftmostNode(rightChildPtr, inorderSuccVal);
		nodePtr->setRightChildPtr(tempPtr);
		nodePtr->setTitle(inorderSuccVal);
		return nodePtr;
	}
}

std::shared_ptr<Book> BookPile::removeLeftmostNode(std::shared_ptr<Book> nodePtr, std::string& inorderSuccVal) {
	if (nodePtr->getLeftChildPtr() == nullptr) {
		inorderSuccVal = nodePtr->getTitle();
		return removeNode(nodePtr);
	}
	else {
		auto tempPtr = removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccVal);
		nodePtr->setLeftChildPtr(tempPtr);
		return nodePtr;
	}
}
// USED IN: removeBook() END ----------------------------------------------


// USED IN: clear()
void BookPile::destroyTree(std::shared_ptr<Book> subTreePtr) {
	if (subTreePtr != nullptr) {
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());

		subTreePtr->setLeftChildPtr(nullptr);
		subTreePtr->setRightChildPtr(nullptr);
	}
}

// USED IN: operator==() ----------------------------------------------
void BookPile::treeToVector(std::shared_ptr<Book> subTreePtr, std::vector<std::string>& bookPile) {
	if (subTreePtr != nullptr) {
		treeToVector(subTreePtr->getLeftChildPtr(), bookPile);
		bookPile.push_back(subTreePtr->getTitle());
		treeToVector(subTreePtr->getRightChildPtr(), bookPile);
	}
}

bool BookPile::isSameTree(std::shared_ptr<Book> subTreePtr1, std::shared_ptr<Book> subTreePtr2) {
	if (subTreePtr1 == nullptr && subTreePtr2 == nullptr) {
		return true;
	}
	else if (subTreePtr1 != nullptr && subTreePtr2 != nullptr) {
		return ( (subTreePtr1->getTitle() == subTreePtr2->getTitle()) &&	// comparing titles at current node
			(isSameTree(subTreePtr1->getLeftChildPtr(), subTreePtr2->getLeftChildPtr())) &&	// recursion for next child
			(isSameTree(subTreePtr1->getRightChildPtr(), subTreePtr2->getRightChildPtr())) );
	}
	else {
		return false;
	}
}
// USED IN: operator==() END ----------------------------------------------
/* --------- HELPER FUNCTIONS END --------- */
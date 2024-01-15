#include "BookPile.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

BookPile::BookPile() : bookCount(0) {
	//initializing books array
	for (int i = 0; i < DEFAULT_CAPACITY; i++) {
		books[i] = "";
	}
}

BookPile::BookPile(std::vector<std::string>& addedBooks) : bookCount(0) {
	//iterates through the addBook function
	for (int i = 0; i < addedBooks.size(); i++) {
		addBook(addedBooks[i]);
	}
}

void BookPile::displayPile() {

	if (bookCount == 0) {
		cout << "Book pile is empty." << endl;
	}
	else {
		for (int i = 0; i < bookCount; i++) {
			cout << i + 1 << ". " << books[i] << " (" << books[i].length() << ")" << endl;
		}
	}
}

bool BookPile::addBook(string addedBook) {

	int insIndex = bookCount;

	//can't add book if array is full
	if (bookCount >= DEFAULT_CAPACITY) {
		return false;
	}

	//book shouldn't be added when title is ""
	if (addedBook.empty()) {
		return false;
	}

	//checking for duplicates and setting insIndex
	for (int i = 0; i < bookCount; i++) {
		if (addedBook == books[i]) {
			return false;
		}
		if (addedBook.length() == books[i].length()) {
			if (addedBook < books[i]) {
				insIndex = i;
				break;
			}
			else if (addedBook > books[i]) {
				insIndex = i + 1;
				break;
			}
		}
		if (addedBook.length() > books[i].length()) {
			insIndex = i;
			break;
		}
	}

	// shifting all values from insIndex and up to the right
	for (int i = bookCount - 1; i >= insIndex; i--) {
		books[i + 1] = books[i];
	}

	books[insIndex] = addedBook;
	bookCount++;

	return true;
}

bool BookPile::removeBook(string bookToRemove) {

	bool didRemove = false;
	int indexToRemove = -1;

	//checking if bookToRemove is empty
	if (bookToRemove == "") {
		return false;
	}

	for (int i = 0; i < bookCount; i++) {
		if (books[i] == bookToRemove) {
			indexToRemove = i;
			break;
		}
	}
	//checking if book even exists
	if (indexToRemove < 0) {
		return false;
	}
	//if it does exist
	else {
		didRemove = removePosition(indexToRemove + 1);
	}

	return didRemove;
}

bool BookPile::removePosition(int input) {

	bool didRemove = false;

	if ((input <= bookCount) && (input >= 0)) {
		//shifting all values to the left until it hits bookCount - 1
		for (int i = input - 1; i < bookCount - 1; i++) {
			books[i] = books[i + 1];
		}
		bookCount--;
		books[bookCount] = "";
		didRemove = true;
	}
	return didRemove;
}

int BookPile::bookPosition(string nameOfBook) {

	int posOfBook = -1;

	for (int i = 0; i < bookCount; i++) {
		if (books[i] == nameOfBook) {
			posOfBook = i + 1;	// +1 to accommodate for indexing
			break;
		}
	}
	
	return posOfBook;
}

string BookPile::getPosition(int input) {
	
	if ((input >= 0) && (input < bookCount)) {
		return books[input - 1];
	}
	else {
		throw out_of_range("ERROR: Invalid position.");
	}
}

bool BookPile::rename(string oldTitle, string newTitle) {

	bool result = removeBook(oldTitle);

	//checking if book exists
	if (result) {
		addBook(newTitle);
		return true;
	}
	else {
		return false;
	}
}

int BookPile::size() {
	return bookCount;
}

void BookPile::clear() {

	for (int i = 0; i < bookCount; i++) {
		books[i] = "";
	}
	bookCount = 0;
}

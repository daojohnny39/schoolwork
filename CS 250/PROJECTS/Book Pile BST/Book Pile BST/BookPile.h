#ifndef BOOKPILE_H
#define BOOKPILE_H

#include <vector>
#include <string>
#include <memory>

#include "Book.h"

class BookPile {
private:
	std::shared_ptr<Book> rootPtr;
	int bookCount;

	void inOrderTraversal(std::shared_ptr<Book> rootPtr);	// Helper

public:
	BookPile();
	BookPile(std::vector<std::string> existEntries);

	void displayPile();
	bool addBook(std::string newEntry);
	bool removeBook(std::string bookToRemove);
	bool contains(std::string book);
	bool rename(std::string oldTitle, std::string newTitle);

	int size();
	void clear();
	bool operator==(const BookPile& secondPile);
};

#endif
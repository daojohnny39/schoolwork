#ifndef BOOKPILE_H
#define BOOKPILE_H

#include "Book.h"
#include <memory>
#include <cassert>
#include <vector>

using namespace std;

class BookPile : public Book {
private:
	Book* headptr;
	int bookCount;

public:
	/*
	BookPile - default constructor
	*/
	BookPile();

	/*
	BookPile - constructor that takes a vector of books
	@params: existingBooks - the vector of books to be added
	*/
	BookPile(std::vector<std::string> existingBooks);

	/*
	DisplayPile - displays the contents of the book pile
	*/
	void displayPile();

	/*
	addBook - adds a book to the book pile
	@params: addedBook - the book to be added
	@return: true if the book was added, false if not
	*/
	bool addBook(const std::string& addedBook);

	/*
	removeBook - removes a book from the book pile
	@params: bookToRemove - the book to be removed
	@return: true if the book was removed, false if not
	*/
	bool removeBook(const std::string& bookToRemove);

	/*
	removePosition - removes a book from the book pile at a given position
	@params: positionToRemove - the position to remove the book from
	@return: true if the book was removed, false if not
	*/
	bool removePosition(int positionToRemove);

	/*
	bookPosition - returns the position of a given book
	@params: bookName - the book to find the position of
	@return: the position of the book
	@precondition: book pile must not be empty
	*/
	int bookPosition(std::string bookName);

	/*
	getPosition - returns the book at a given position
	@params: positionNum - the position to get the book from
	@return: the book at the given position
	*/
	std::string getPosition(int positionNum);

	/*
	rename - renames a book in the book pile
	@params: oldTitle - the old title of the book
			 newTitle - the new title of the book
	@return: true if the book was renamed, false if not
	*/
	bool rename(std::string oldTitle, std::string newTitle);

	/*
	size - returns the size of the book pile
	@return: the size of the book pile
	*/
	int size();

	/*
	clear - clears the book pile
	*/
	void clear();
};

#endif // !BOOKPILE_H

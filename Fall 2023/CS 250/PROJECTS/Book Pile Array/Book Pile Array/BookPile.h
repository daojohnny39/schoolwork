#ifndef BOOKPILE_H
#define BOOKPILE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BookPile {
private:
	static const int DEFAULT_CAPACITY = 10;
	string books[DEFAULT_CAPACITY];
	int bookCount;

public:
	/*
	* Default constructor, Initializes books array to empty strings
	*/
	BookPile();

	/*
	* Constructor that takes in a vector of strings and adds them to the books array
	* 
	* @param addedBooks vector of strings to be added to the books array
	*/
	BookPile(std::vector<string>& addedBooks);

	/*
	* Displays the books in the books array
	*/
	void displayPile();

	/*
	* Adds a book to the books array in character length order, if the same length, then alphabetical order
	* 
	* @param addedBook string to be added to the books array
	* @return true if book was added, false if not
	*/
	bool addBook(std::string addedBook);

	/*
	* Removes a book from the books array
	* 
	* @param bookToRemove string to be removed from the books array
	* @return true if book was removed, false if not
	* @pre book must exist in the books array
	*/
	bool removeBook(std::string bookToRemove);

	/*
	* Removes a book from the books array at a specific position
	* 
	* @param input position of the book to be removed
	* @return true if book was removed, false if not
	* @pre input must be a valid position in the books array
	*/
	bool removePosition(int input);

	/*
	* Finds the position of a book in the books array
	* 
	* @param nameOfBook string to be found in the books array
	* @return position of the book in the books array, -1 if not found
	*/
	int bookPosition(std::string nameOfBook);

	/*
	* Finds the book at a specific position in the books array
	* 
	* @param input position of the book to be found
	* @return book at the position in the books array, empty string if not found
	*/
	std::string getPosition(int input);

	/*
	* Renames a book in the books array
	* 
	* @param oldTitle string to be renamed, newTitle string to be renamed to
	* @return true if book was renamed, false if not
	*/
	bool rename(std::string oldTitle, std::string newTitle);

	/*
	* Returns the number of books in the books array
	* 
	* @return number of books in the books array
	*/
	int size();

	/*
	* Clears the books array
	*/
	void clear(); 
};

#endif
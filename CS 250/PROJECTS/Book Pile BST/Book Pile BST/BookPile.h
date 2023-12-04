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

	// Helper

	/*
	inOrderTraversal() - Helper function for displayPile() - displays the book pile in order

	@param rootPtr - The root pointer of the tree
	@param count - The count of the books in the tree
	*/
	void inOrderTraversal(std::shared_ptr<Book> rootPtr, int& count);

	/*
	removeBookHelper() - Helper function for removeBook() - removes a book from the tree

	@param subTreePtr - The root pointer of the tree
	@param target - The book to remove
	@param isSuccessful - Whether or not the book was removed
	*/
	std::shared_ptr<Book> removeBookHelper(std::shared_ptr<Book> subTreePtr, const std::string& bookToRemove, bool& isSuccessful);

	/*
	removeNode() - Helper function for removeBookHelper() - removes a node from the tree

	@param nodePtr - The node to remove
	*/
	std::shared_ptr<Book> removeNode(std::shared_ptr<Book> nodePtr);

	/*
	removeLeftmostNode() - Helper function for removeNode() - removes the leftmost node from the tree

	@param nodePtr - The node to remove
	@param inorderSuccVal - The value of the inorder successor
	*/
	std::shared_ptr<Book> removeLeftmostNode(std::shared_ptr<Book> nodePtr, std::string& inorderSuccVal);

	/*
	destroyTree() - Helper function for destructor - sets all childPtrs to nullptr

	@param subTreePtr - The root pointer of the tree
	*/
	void destroyTree(std::shared_ptr<Book> subTreePtr);

	/*
	treeToVector() - Helper function for operator== - converts a tree to a vector

	@param subTreePtr - The root pointer of the tree
	@param bookPile - The vector to convert to
	*/
	void treeToVector(std::shared_ptr<Book> subTreePtr, std::vector<std::string>& bookPile);

	/*
	isSameTree() - Helper function for operator== - checks if two trees are the same

	@param subTreePtr1 - The root pointer of the first tree
	@param subTreePtr2 - The root pointer of the second tree
	*/
	bool isSameTree(std::shared_ptr<Book> subTreePtr1, std::shared_ptr<Book> subTreePtr2);

public:
	BookPile();
	BookPile(std::vector<std::string> existEntries);

	/*
	displayPile() - Displays the book pile in order
	*/
	void displayPile();

	/*
	addBook() - Adds a book to the book pile

	@param newEntry - The book to add
	@return - Whether or not the book was added
	*/
	bool addBook(std::string newEntry);

	/*
	removeBook() - Removes a book from the book pile

	@param bookToRemove - The book to remove
	@return - Whether or not the book was removed
	*/
	bool removeBook(std::string bookToRemove);

	/*
	contains() - Checks if a book is in the book pile

	@param book - The book to check for
	@return - Whether or not the book is in the book pile
	*/
	bool contains(std::string book);

	/*
	rename() - Renames a book in the book pile

	@param oldTitle - The book to rename
	@param newTitle - The new name of the book
	@return - Whether or not the book was renamed
	*/
	bool rename(std::string oldTitle, std::string newTitle);

	/*
	size() - Returns the number of books in the book pile

	@return - The number of books in the book pile
	*/
	int size();

	/*
	clear() - Clears the book pile
	*/
	void clear();

	/*
	operator==() - Checks if two book piles are the same

	@param secondPile - The second book pile to check
	@return - Whether or not the two book piles are the same
	*/
	bool operator==(const BookPile& secondPile);
};

#endif
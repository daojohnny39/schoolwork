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

public:
	BookPile();
	BookPile(std::vector<std::string> existingBooks);
	void displayPile();
	bool addBook(const std::string& addedBook);
	//int size();
};

#endif // !BOOKPILE_H

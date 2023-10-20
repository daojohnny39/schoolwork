#ifndef BOOKPILE_H
#define BOOKPILE_H

#include <string>
#include <vector>

class BookPile {
private:
	static const int DEFAULT_CAPACITY = 10;
	std::vector<std::string> books;

public:
	BookPile();
	BookPile(vector<string>& addedBooks);
	void displayPile();
	bool addBook(string);
	bool removeBook(string);
	bool removePosition(int);
	int bookPosition(string);
	string getPosition(int);
	bool rename(string oldTitle, string newTitle);
	int size();
	void clear(); 
};

#endif
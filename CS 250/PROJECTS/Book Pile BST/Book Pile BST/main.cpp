#include <iostream>
#include <string>
#include "BookPile.h"
#include <vector>
using namespace std;

int main() {
    BookPile myPile;
    BookPile samePile;

    std::vector<string> books = { "Random1ze", "Sea of Rust", "All Systems Red", "Rust", "Dragonflight",
                           "Neuromancer", "Contact", "Brave New World", "Cinder", "Dune", "Random1ze", 
                           "Sea of Rust", "All Systems Red", "This Shouldn't Show Up", 
                           "This Book Does Not Exist", "Null"};

    std::cout << "size() returns: " << myPile.size() << " [should be 0]" << std::endl << std::endl;

    for (int i = 0; i < 16; i++) {
        std::cout << "addBook(\"" << books[i] << "\") returns: " << myPile.addBook(books[i]) << std::endl;
    }

    std::cout << std::endl << "size() returns: " << myPile.size() << " [should be 13]" << std::endl << std::endl;

    std::cout << "BOOK PILE CONTAINS: " << std::endl;
    myPile.displayPile();

    std::cout << std::endl << "addBook(\"\") returns: " << myPile.addBook("")
        << " [should be 0]" << std::endl;

    std::cout << std::endl << "contains(\"Contact\") returns: " << myPile.contains("Contact")
        << " [should be 1]" << std::endl << std::endl;

    std::cout << "contains(\"Neverwhere\") returns: " << myPile.contains("Neverwhere")
        << " [should be 0]" << std::endl << std::endl;

    std::cout << "removeBook(\"Last Days\") returns: " << myPile.removeBook("Last Days")
        << " [should be 0]" << std::endl << std::endl;

    std::cout << "removeBook(\"Cinder\") returns: " << myPile.removeBook("Cinder")
        << " [should be 1]" << std::endl << std::endl;

    std::cout << "rename(\"Fred\", \"Jimmy\") returns: " << myPile.rename("Fred", "Jimmy")
        << " [should be 0]" << std::endl << std::endl;

    std::cout << "rename(\"Rust\", \"Crust\") returns: " << myPile.rename("Rust", "Crust")
        << " [should be 1]" << std::endl << std::endl;

    std::cout << "size() returns: " << myPile.size() << " [should be 11]" << std::endl << std::endl;

    std::cout << "BOOK PILE CONTAINS: " << std::endl;
    myPile.displayPile();

    std::cout << std::endl << "Running clear()..." << std::endl << std::endl;
    myPile.clear();

    std::cout << "size() returns: " << myPile.size() << " [should be 0]" << std::endl << std::endl;
    std::cout << "BOOK PILE CONTAINS: " << std::endl;
    myPile.displayPile();

    std::cout << std::endl  << "Filling a pile with the vector constructor..." << std::endl;
    BookPile myPile2(books);
    std::cout << "BOOK PILE CONTAINS: " << std::endl;
    myPile2.displayPile();

    std::cout << "operator==() returns: " << (myPile == myPile2) << " [should be 0]" << std::endl << std::endl;

    for (int i = 0; i < 16; i++) {
        myPile.addBook(books[i]);
    }

    for (int i = 0; i < 16; i++) {
        samePile.addBook(books[i]);
    }

    std::cout << "operator==() returns: " << (myPile == samePile) << " [should be 1]" << std::endl << std::endl;

    myPile.clear();
    for (int i = 15; i >= 0; i--) {
        myPile.addBook(books[i]);
    }

    std::cout << "operator==() returns: " << (myPile == samePile) << " [should be 0]" << std::endl << std::endl;

    std::cout << "operator==() returns: " << (samePile == samePile) << " [should be 1]" << std::endl << std::endl;

    return 0;
}

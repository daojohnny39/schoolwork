#include <iostream>
#include <string>
#include <vector>
#include "BookPile.h"
#include "FunctionUtilities.hpp"
using namespace std;

int main() {
    BookPile myPile;

    std::vector<string> books = { "Random1ze", "Sea of Rust", "All Systems Red", "Rust", "Dragonflight",
                           "Neuromancer", "Contact", "Brave New World", "Cinder", "Dune", "Random1ze", 
                           "Sea of Rust", "All Systems Red", "This Shouldn't Show Up", 
                           "This Book Does Not Exist", "Null"};

    std::cout << "size() returns: " << myPile.size() << " [should be 0]" << std::endl << std::endl;

    for (int i = 0; i < 16; i++) {
        std::cout << "addBook(\"" << books[i] << "\") returns: " << myPile.addBook(books[i]) << std::endl;
    }

    std::cout << std::endl << "size() returns: " << myPile.size() << " [should be 10]" << std::endl << std::endl;

    std::cout << "BOOK PILE CONTAINS: " << std::endl;
    myPile.displayPile();

    std::cout << std::endl << "addBook(\"\") returns: " << myPile.addBook("")
        << " [should be 0]" << std::endl;

    std::cout << std::endl << "bookPosition(\"Contact\") returns: " << myPile.bookPosition("Contact")
        << " [should be 7]" << std::endl << std::endl;

    std::cout << "bookPosition(\"Neverwhere\") returns: " << myPile.bookPosition("Neverwhere")
        << " [should be -1]" << std::endl << std::endl;

    std::cout << "getPosition(6) returns: " << myPile.getPosition(6) << " [should be Random1ze]" << std::endl << std::endl;

    std::cout << "removePosition(1) returns: " << myPile.removePosition(1) << " [should be 1]" << std::endl << std::endl;

    std::cout << "removeBook(\"Last Days\") returns: " << myPile.removeBook("Last Days")
        << " [should be 0]" << std::endl << std::endl;

    std::cout << "removeBook(\"Cinder\") returns: " << myPile.removeBook("Cinder")
        << " [should be 1]" << std::endl << std::endl;

    std::cout << "rename(\"Fred\", \"Jimmy\") returns: " << myPile.rename("Fred", "Jimmy")
        << " [should be 0]" << std::endl << std::endl;

    std::cout << "rename(\"Rust\", \"Crust\") returns: " << myPile.rename("Rust", "Crust")
        << " [should be 1]" << std::endl << std::endl;

    std::cout << "size() returns: " << myPile.size() << " [should be 8]" << std::endl << std::endl;

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

    divLine("codePost Tests", "Test cases:");

    BookPile pile;

    //REMOVEBOOK()
    subDivLine("removeBook()");
    actualOutput();

    pile.addBook("Dune");
    pile.addBook("Brave New World");
    pile.addBook("Neuromancer");

    std::cout << "Removing Dune:" << (pile.removeBook("Dune") ? " Success" : " Failed") << std::endl;
    std::cout << "Removing Dune again:" << (pile.removeBook("Dune") ? " Success" : " Failed") << std::endl; // should fail
    std::cout << "Removing Brave New World:" << (pile.removeBook("Brave New World") ? " Success" : " Failed") << std::endl;

    std::cout << "Displaying BookPile: " << std::endl;
    pile.displayPile();

    expectedOutput();
    cout << "Removing Dune: Success" << endl;
    cout << "Removing Dune again: Failed" << endl;
    cout << "Removing Brave New World: Success" << endl << endl;
    cout << "Displaying BookPile:" << endl;
    cout << "1. Neuromancer (11)" << endl;

    pile.clear();
    subDivLineEnd();
    //END REMOVEBOOK()

    //GETPOSITION()
    subDivLine("getPosition()");
    actualOutput();

    pile.addBook("Dune");
    pile.addBook("Brave New World");
    pile.addBook("Neuromancer");

    // Get book titles by position
    std::cout << "Title at position 1: " << pile.getPosition(1) << std::endl;
    std::cout << "Title at position 2: " << pile.getPosition(2) << std::endl;

    try {
        std::cout << "Title at invalid position 10: " << pile.getPosition(10) << std::endl; // should throw exception
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    expectedOutput();
    cout << "Title at position 1: Brave New World" << endl;
    cout << "Title at position 2: Neuromancer" << endl;
    cout << "Title at invalid position 10: ERROR: Invalid position." << endl;

    pile.clear();
    subDivLineEnd();

    //RENAME()
    subDivLine("rename()");
    actualOutput();

    pile.addBook("Dune");
    pile.addBook("Brave New World");
    pile.addBook("Neuromancer");

    //actual output
    std::cout << "Renaming Dune to Desert Planet:" << (pile.rename("Dune", "Desert Planet") ? " Success" : " Failed") << std::endl;
    std::cout << "Renaming Dune again:" << (pile.rename("Dune", "Desert Moon") ? " Success" : " Failed") << std::endl; // should fail

    cout << endl;
    std::cout << "Displaying BookPile : " << std::endl;
    pile.displayPile();

    //expected output
    expectedOutput();
    cout << "Renaming Dune to Desert Planet: Success" << endl;
    cout << "Renaming Dune again: Failed" << endl;
    cout << endl;
    cout << "Expected output:" << endl;
    cout << "1. Brave New World (15)" << endl;
    cout << "2. Desert Planet (13)" << endl;
    cout << "3. Neuromancer (11)" << endl;
    
    subDivLineEnd();

    return 0;
}

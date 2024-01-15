#include <iostream>
#include <string>
#include "functions.hpp"

int main() {
    std::string phrase;

    std::cout << "Enter a phrase: ";
    getline(std::cin, phrase);

    std::string processedPhrase = strip(phrase);

    // REMOVE LATER
    std::cout << "Processed Phrase: " << processedPhrase << std::endl;

    if (isPalindrome(processedPhrase)) {
        std::cout << "The phrase is a palindrome." << std::endl;
    }
    else {
        std::cout << "The phrase is not a palindrome." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include "Movie.h"

Movie::Movie() {}

void Movie::setTitle(std::string inputTitle) {
    title = inputTitle;
}

void Movie::setRating(std::string inputRating) {
    
    if (inputRating == "G" || inputRating == "PG" ||
        inputRating == "PG-13" || inputRating == "R" ||
        inputRating == "Unrated") {
        rating = inputRating;
    }
    else {
        rating = "Unrated";
    }
}

void Movie::addScore(int inputScore) {
    if (inputScore >= 1 && inputScore <= 5) {
        score[inputScore]++;
    }
} 

double Movie::getAverageScore() {
    double averageScore = 0;
    double topEquation = 0;
    double bottomEquation = 0;

    double tempNum = 0;

//  Calculates top portion of equation.
    for (int i = 1; i < 6; i++) {
        tempNum = score[i] * i;
        topEquation += tempNum; 
    }
    tempNum = 0;

//  Calculates bottom portion
    for (int i = 1; i < 6; i++) {
        tempNum += score[i];
    }
    bottomEquation = tempNum;

    if (bottomEquation > 0) {
        averageScore = topEquation / bottomEquation;
    }

    return averageScore;
}

void Movie::output() {
    std::cout << "Title: " << title << std::endl;
    std::cout << "MPAA Rating: " << rating << std::endl;
    std::cout << "Average Score: " << getAverageScore() << std::endl;
}
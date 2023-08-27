#include <iostream>
#include <string>

class Movie {
    public:
    Movie();
    void setTitle(std::string);
    void setRating(std::string);
    void addScore(int);
    double getAverageScore();
/** 
 * getAverageScore() calculates the average of the total
 * scores.
 * 
 * \@return returns average score. if no score, returns 0.
*/
    void output();
/**
 * output() displays title, rating, and average score.
*/

    private:
    std::string title;
    std::string rating;
    int score[6] = {0, 0, 0, 0, 0, 0};
};
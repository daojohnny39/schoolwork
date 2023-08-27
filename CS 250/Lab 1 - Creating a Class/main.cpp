#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include "Movie.h"

int main() {
	Movie aMovie;
	aMovie.setTitle("The Matrix");
	aMovie.setRating("X"); // intentionally invalid
	
	std::cout << "The object contains:" << std::endl;
	aMovie.output();

	std::cout << std::endl
		<< "Output above should be:" << std::endl
		<< "Title: The Matrix\nMPAA Rating: Unrated\nAverage Score: 0"
		<< std::endl << std::endl;

	aMovie.setRating("R");

	for (int i = 1; i < 6; i++)
	{
		aMovie.addScore(1);
	}

	for (int i = 1; i < 11; i++)
	{
		aMovie.addScore(2);
	}

	for (int i = 1; i < 21; i++)
	{
		aMovie.addScore(3);
	}

	for (int i = 1; i < 41; i++)
	{
		aMovie.addScore(4);
	}

	for (int i = 1; i < 81; i++)
	{
		aMovie.addScore(5);
	}
	
	std::cout << "The object contains:" << std::endl;
	aMovie.output();

	std::cout << std::endl
		<< "Output above should be:" << std::endl
		<< "Title: The Matrix\nMPAA Rating: R\nAverage Score: 4.16129"
		<< std::endl << std::endl;
}

#endif
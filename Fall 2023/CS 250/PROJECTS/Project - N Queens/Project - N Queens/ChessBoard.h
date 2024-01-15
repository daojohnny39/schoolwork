#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

/**
* [Johnny (Nhat) Dao]
**/

#include <iostream>

class ChessBoard {
private:
	char** boardPtr;
	int boardSize;

	/**
	* isSafe: Checks if a queen can be placed at a given row and column
	* 
	* @param row the row to check
	* @param column the column to check
	* @return true if a queen can be placed at the given row and column, false otherwise
	**/
	bool isSafe(int row, int column); // helper function

	/**
	* placeQueens: Places queens on the board
	* 
	* @param column the column to place the queen
	* @return true if the queen can be placed, false otherwise
	**/
	bool placeQueens(int column);

public:
	/**
	* ChessBoard: Default constructor
	* 
	* @return a ChessBoard object
	**/
	ChessBoard();

	/**
	* ChessBoard: Constructor that takes in a size
	* 
	* @param inputSize the size of the board
	* @return a ChessBoard object
	**/
	ChessBoard(int inputSize);

	/**
	* ~ChessBoard: Destructor
	**/
	~ChessBoard();

	/**
	* setSize: Sets the size of the board
	* 
	* @param size the size of the board
	**/
	void setSize(int size);

	/**
	* getSize: Gets the size of the board
	* 
	* @return the size of the board
	**/
	int getSize();

	/**
	* solve: Solves the n-queens problem
	* 
	* @return true if the problem can be solved, false otherwise
	**/
	bool solve();

	/**
	* displayBoard: Displays the board
	**/
	void displayBoard();
};

#endif // CHESSBOARD_H_
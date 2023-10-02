/** 
* [Johnny (Nhat) Dao]
**/

#include <iostream>
#include <string>
#include "ChessBoard.h"

using namespace std;

// *** CONSTRUCTORS *** //
ChessBoard::ChessBoard() {
	boardSize = 8;
	boardPtr = new char* [boardSize];

	for (int i = 0; i < boardSize; i++) {
		boardPtr[i] = new char[boardSize];

		for (int j = 0; j < boardSize; j++) {
			boardPtr[i][j] = '*';
		}
	}
}

ChessBoard::ChessBoard(int inputSize) {
	if (inputSize < 4) {
		boardSize = 4;
	}
	else if (inputSize > 12) {
		boardSize = 12;
	}
	else {
		boardSize = inputSize;
	}

	boardPtr = new char* [boardSize];

	for (int i = 0; i < boardSize; i++) {
		boardPtr[i] = new char[boardSize];

		for (int j = 0; j < boardSize; j++) {
			boardPtr[i][j] = '*';
		}
	}
}

// *** DESTRUCTOR *** //
ChessBoard::~ChessBoard() {
	for (int i = 0; i < boardSize; i++) {
		delete[] boardPtr[i];
	}
	delete [] boardPtr;
}

// *** HELPER FUNCTION *** //
bool ChessBoard::isSafe(int row, int col) {
	// Check if there is a queen in the same row
	for (int i = 0; i < col; ++i) {
		if (boardPtr[row][i] == 'Q') {
			return false;
		}
	}

	// Check upper diagonal on the left side
	for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
		if (boardPtr[i][j] == 'Q') {
			return false;
		}
	}

	// Check lower diagonal on the left side
	for (int i = row, j = col; i < boardSize && j >= 0; ++i, --j) {
		if (boardPtr[i][j] == 'Q') {
			return false;
		}
	}

	return true;
}

// *** FUNCTIONS *** //
bool ChessBoard::placeQueens(int col) {
	int row = 0;

	if (col >= boardSize) {
		return true;
	}
	else {
		while (row < boardSize) {
			if (isSafe(row, col)) {
				// Place queen in the square if it is safe.
				boardPtr[row][col] = 'Q';

				if (!placeQueens(col + 1)) {
					// Backtrack
					boardPtr[row][col] = '*';
					row++;
				}
				else {
					return true;
				}
			}
			else {
				row++;
			}
		}
		return false;
	}
}

void ChessBoard::setSize(int size) {
	
	// Delete existing board
	for (int i = 0; i < boardSize; i++) {
        delete[] boardPtr[i];
    }
    delete[] boardPtr;

    // Checking for valid size
    if (size < 4) {
        boardSize = 4;
    }
    else if (size > 12) {
        boardSize = 12;
    }
    else {
        boardSize = size;
    }

    // Creating a new board
    boardPtr = new char* [boardSize];

    for (int i = 0; i < boardSize; i++) {
        boardPtr[i] = new char[boardSize];

        for (int j = 0; j < boardSize; j++) {
            boardPtr[i][j] = '*';
        }
    }
}

int ChessBoard::getSize() {
	return boardSize;
}

bool ChessBoard::solve() {

	// Resetting the board
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			boardPtr[i][j] = '*';
		}
	}

	if (placeQueens(0)) {
		return true;
	}
	else {	
		return false;
	}
}

void ChessBoard::displayBoard() {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << boardPtr[i][j] << " ";
		}
		cout << endl;
	}
}




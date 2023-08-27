#include <iostream>
#include <cstdlib> // for rand()
#include <ctime> // for time()
using namespace std;

// Constant used to quickly change all array sizes.
const int ARRAY_SIZE = 20;

/*
* fillStackArray1D fills the given single dimension array on the stack with
* random integers from 0 - 9.
*
* @param array The single dimension array.
* @param size The number of elements in the array.
*/
void fillStackArray1D(int array[], int size);

/*
* fillStackArray2D fills the given two dimensional array on the stack with
* random integers from 0 - 9.
*
* @param array The two dimensional array.
* @param rows The number of rows in the array.
* @param cols The number of columns in the array.
*/
void fillStackArray2D(int array[][ARRAY_SIZE], int rows, int cols);

/*
* displayStackArray1D displays the given single dimension array on the screen
* with each element separated by a space.
*
* @param array The single dimension array.
* @param size The number of elements in the array.
*/
void displayStackArray1D(int array[], int size);

/*
* displayStackArray2D displays the given two dimensional array on the screen
* with each element separated by a space and linebreaks between rows.
*
* @param array The two dimensional array.
* @param rows The number of rows in the array.
* @param cols The number of columns in the array..
*/
void displayStackArray2D(int array[][ARRAY_SIZE], int rows, int cols);

// ---------- LAB FOLLOWING -------------------
// 1D FUNCTIONS
int* createHeapArray1D(int size);
void fillHeapArray1D(int* array, int size);
void displayHeapArray1D(int* array, int size);
void deleteHeapArray1D(int* array);

// 2D FUNCTIONS
int** createHeapArray2D(int row, int col);
void fillHeapArray2D(int** array, int rows, int cols);
void displayHeapArray2D(int** array, int rows, int cols);
void deleteHeapArray2D(int** array, int rows);
// ---------- LAB FOLLOWING END ---------------

int main()
{

	int stackArray1D[ARRAY_SIZE]; // one-dimensional array
	int stackArray2D[ARRAY_SIZE][ARRAY_SIZE]; // two-dimensional array
	int* heapArray1D = nullptr;
	int** heapArray2D = nullptr;

	cout << "1D STACK ARRAY" << endl;
	fillStackArray1D(stackArray1D, ARRAY_SIZE);
	displayStackArray1D(stackArray1D, ARRAY_SIZE);

	cout << endl << endl << "2D STACK ARRAY" << endl;
	fillStackArray2D(stackArray2D, ARRAY_SIZE, ARRAY_SIZE);
	displayStackArray2D(stackArray2D, ARRAY_SIZE, ARRAY_SIZE);

	cout << endl << "1D HEAP ARRAY" << endl;
	// UNCOMMENTED FUNCTIONS
	heapArray1D = createHeapArray1D(ARRAY_SIZE);
	fillHeapArray1D(heapArray1D, ARRAY_SIZE);
	displayHeapArray1D(heapArray1D, ARRAY_SIZE);
	deleteHeapArray1D(heapArray1D);
	// END UNCOMMENTED FUNCTIONS
	heapArray1D = nullptr;
	
	cout << endl << endl << "2D HEAP ARRAY" << endl;
	// UNCOMMENTED FUNCTIONS
	heapArray2D = createHeapArray2D(ARRAY_SIZE, ARRAY_SIZE);
	fillHeapArray2D(heapArray2D, ARRAY_SIZE, ARRAY_SIZE);
	displayHeapArray2D(heapArray2D, ARRAY_SIZE, ARRAY_SIZE);
	deleteHeapArray2D(heapArray2D, ARRAY_SIZE);
	// END UNCOMMENTED FUNCTIONS
	heapArray2D = nullptr;
	
	return 0;
}

// ---------- LAB FOLLOWING -------------------
// 2D FUNCTIONS
void deleteHeapArray2D(int** array, int rows) {
	if (array != nullptr) {
		for (int i = 0; i < rows; i++) {
			delete [] array[i];
		}

		delete [] array;
	}
}

void displayHeapArray2D(int** array, int rows, int cols)
{

	if (array != nullptr) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << array[i][j] << " ";
			}

			cout << endl;
		}
	}

}

int** createHeapArray2D(int row, int col) {
	int** array = new int*[row];

	for (int i = 0; i < row; i++) {
		array[i] = new int[col];
	}

	return array;
}

void fillHeapArray2D(int** array, int rows, int cols)
{
	srand(static_cast<unsigned int>(time(0))); // seed random

	if (array != nullptr) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				array[i][j] = rand() % 10; // random int from 0 - 9
			}
		}
	}

}
// 2D FUNCTIONS END

// 1D FUNCTIONS
void deleteHeapArray1D(int* array) {
	delete [] array;
}

void displayHeapArray1D(int* array, int size)
{
	if (array != nullptr) {
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
	}
}

int* createHeapArray1D(int size) {
	return new int[size];
}

void fillHeapArray1D(int* array, int size)
{
	srand(static_cast<unsigned int>(time(0))); // seed random

	if (array != nullptr) {
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 10; // random int from 0 - 9
		}
	}

}
// 1D FUNCTIONS END
// ---------- LAB FOLLOWING END ---------------

void fillStackArray1D(int array[], int size)
{
	srand(static_cast<unsigned int>(time(0))); // seed random

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 10; // random int from 0 - 9
	}

}

void fillStackArray2D(int array[][ARRAY_SIZE], int rows, int cols)
{
	srand(static_cast<unsigned int>(time(0))); // seed random

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = rand() % 10; // random int from 0 - 9
		}
	}

}

void displayStackArray1D(int array[], int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

}

void displayStackArray2D(int array[][ARRAY_SIZE], int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array[i][j] << " ";
		}

		cout << endl;
	}

}

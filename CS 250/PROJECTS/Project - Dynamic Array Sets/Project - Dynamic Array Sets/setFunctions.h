#ifndef SETFUNCTIONS_H
#define SETFUNCTIONS_H

/**
* Author: Johnny (Nhat) Dao
**/

/**
* containsElement() - checks if the set contains the element
* 
* @param: setA - the set to check
* @param: sizeA - the size of the set
* @param: itemToCheck - the element to check
* @return: true if the set contains the element, false otherwise
**/
bool containsElement(char* set, int size, char itemToCheck);

/**
* display() - displays the set
* 
* @param: set - the set to display
* @param: size - the size of the set
**/
void display(char* set, int size);

/**
* addElement() - adds an element to the set
* 
* @param: set - the set to add the element to
* @param: size - the size of the set
* @param: itemToAdd - the element to add
* @param: resultSize - the size of the new set
* @return: the new set
**/
char* addElement(char* set, int size, char itemToAdd, int& resultSize);

/**
* setUnion() - performs the union of two sets
* 
* @param: setA - the first set
* @param: sizeA - the size of the first set
* @param: setB - the second set
* @param: sizeB - the size of the second set
* @param: resultSetSize - the size of the new set
* @return: the new set
**/
char* setUnion(char* setA, int sizeA, char* setB, int sizeB, int& resultSetSize);

/**
* setIntersect() - performs the intersection of two sets
* 
* @param: setA - the first set
* @param: sizeA - the size of the first set
* @param: setB - the second set
* @param: sizeB - the size of the second set
* @param: resultSetSize - the size of the new set
* @return: the new set
**/
char* setIntersect(char* setA, int sizeA, char* setB, int sizeB, int& resultSetSize);
// NEED TO DO???
//bool equal(char* setA, int sizeA, char* setB, int sizeB);

#endif
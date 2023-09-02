#ifndef SETFUNCTIONS_H
#define SETFUNCTIONS_H

// NOTE: ADD JAVADOC COMMENTS TO ALL FUNCTIONS

bool containsElement(char* set, int size, char itemToCheck);

void display(char* set, int size);

char* addElement(char* set, int size, char itemToAdd, int& newSize);

char* setUnion(char* set1, int set1Size, char* set2, int set2Size, int& unionSize);

char* setIntersect(char* set1, int set1Size, char* set2, int set2Size, int& intersectSize);

#endif
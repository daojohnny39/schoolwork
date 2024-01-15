#ifndef PAIR_H
#define PAIR_H
#include <iostream>
using namespace std;

template<class T>
class Pair
{
public:
	Pair(T firstValue, T secondValue);
	void setElement(int position, T value);
	void swapElements();
	T getElement(int position);

private:
	T firstItem;
	T secondItem;
};

#endif

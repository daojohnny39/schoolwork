#include <iostream>
#include "Pair.h"
using namespace std;

template<class T>
Pair<T>::Pair(T firstValue, T secondValue)
{
	firstItem = firstValue;
	secondItem = secondValue;
}

template<class T>
void Pair<T>::swapElements()
{
	T tempItem;
	tempItem = firstItem;
	firstItem = secondItem;
	secondItem = tempItem;
}

template<class T>
void Pair<T>::setElement(int position, T value)
{
	if (position == 1)
	{
		firstItem = value;
	}
	else
	{
		secondItem = value;
	}

}

template<class T>
T Pair<T>::getElement(int position)
{
	if (position == 1)
	{
		return firstItem;
	}
	else
	{
		return secondItem;
	}

}

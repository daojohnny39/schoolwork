#ifndef PAIR_HPP
#define PAIR_HPP

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

#endif // !PAIR_HPP

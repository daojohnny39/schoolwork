#ifndef SET_H
#define SET_H

// STEP 2 - DONE
template <class T>
class Set
{
public:
	Set();
	// Constructs a new set

	Set<T>(const Set& other);  // STEP 3 - DONE
	// Constructs a new set

	~Set();
	// Destructor

	void operator=(const Set<T>& right_side);  // STEP 3 - DONE
	// Assignment operator

	void add(T item); // STEP 4 - DONE
	// Adds an item to the set. Ignored if the item
	// is already in the set. 

	void remove(T item); // STEP 4 - DONE
	// Removes an item from the set. Ignored if the
	// item is not in the set.

	int size() const;
	// Returns the number of items in the set

	bool contains(T item) const; // STEP 4 - DONE
	// Returns true if the item is in the set

	T *to_array() const; // STEP 4 - DONE
	// Returns a dynamically allocated array with the
	// set's contents, or NULL if the set is empty. The
	// caller is responsible for de-allocating the array.

private:
	T * items; // STEP 4 - DONE
	int set_size;

};

// STEP 5 - DONE
// Constructs a new set
// STEP 6 - DONE
template<class T>
Set<T>::Set() : items(nullptr), set_size(0) // STEP 7 - DONE
{
}

// Constructs a new set
// STEP 6 - DONE
template<class T>
Set<T>::Set(const Set<T>& other) // STEP 7 - DONE	AND STEP 8 - DONE
{
	set_size = other.set_size;
	items = other.to_array();
}

// Destructor
// STEP 6 - DONE
template<class T>
Set<T>::~Set() // STEP 7 - DONE
{
	delete[] items;
}

// Assignment operator
// STEP 6 - DONE
template<class T>
void Set<T>::operator=(const Set<T>& right_side) // STEP 7 - DONE	AND STEP 8 - DONE
{
	if (set_size > 0)
	{
		delete[] items;
	}
	set_size = right_side.set_size;
	items = right_side.to_array();
}


// Adds an item to the set. Ignored if the item
// is already in the set.
// STEP 6 - DONE
template<class T>
void Set<T>::add(T item) // STEP 7 - DONE		AND STEP 9 - DONE
{
	if (!contains(item))
	{
		T* new_items = new T[set_size + 1]; // STEP 9 - DONE
		for (int i = 0; i < set_size; i++)
		{
			new_items[i] = items[i];
		}
		new_items[set_size] = item;
		if (set_size > 0)
		{
			delete[] items;
		}
		set_size++;
		items = new_items;
	}
}

// Removes an item from the set. Ignored if the
// item is not in the set.
// STEP 6 - DONE
template<class T>
void Set<T>::remove(T item) // STEP 7 - DONE		AND STEP 9 - DONE
{
	if (contains(item))
	{
		T* copy = nullptr;  // STEP 9 - DONE
		if (set_size > 1)
		{
			copy = new T[set_size - 1];  // STEP 9 - DONE
			for (int i = 0, j = 0; i < set_size; i++)
			{
				if (items[i] != item)
				{
					copy[j++] = items[i];
				}
			}
		}
		delete[] items;
		items = copy;
		set_size--;
	}
}

// Returns the number of items in the set
// STEP 6 - DONE
template<class T>
int Set<T>::size() const // STEP 7 - DONE
{
	return set_size;
}

// Returns true if the item is in the set
// STEP 6 - DONE
template<class T>
bool Set<T>::contains(T item) const // STEP 7 - DONE		AND STEP 9 - DONE
{
	bool found = false;
	for (int i = 0; (i < set_size) && (!found); i++)
	{
		found = (items[i] == item);
	}
	return found;
}

// Returns a dynamically allocated array with the
// set's contents, or NULL if the set is empty. The
// caller is responsible for de-allocating the array.
// STEP 6 - DONE
template<class T>
T* Set<T>::to_array() const // STEP 7 - DONE		 AND STEP 9 - DONE
{
	T* copy = nullptr;  // STEP 9 - DONE
	if (set_size > 0)
	{
		copy = new T[set_size];  // STEP 9 - DONE
		for (int i = 0; i < set_size; i++)
		{
			copy[i] = items[i];
		}
	}
	return copy;
}

#endif SET_H


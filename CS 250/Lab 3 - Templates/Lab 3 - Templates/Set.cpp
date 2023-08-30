#include "Set.h"

// Constructs a new set
// STEP 6
Set::Set() : items(nullptr), set_size(0) // STEP 7 
{
}

// Constructs a new set
// STEP 6
Set::Set(const Set& other) // STEP 7 AND STEP 8
{
	set_size = other.set_size;
	items = other.to_array();
}

// Destructor
// STEP 6
Set::~Set() // STEP 7
{
	delete [] items;
}

// Assignment operator
// STEP 6
void Set::operator=(const Set& right_side) // STEP 7 AND STEP 8
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
// STEP 6
void Set::add(int item) // STEP 7 AND STEP 9
{
	if (!contains(item))
	{
		int *new_items = new int[set_size + 1]; // STEP 9
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
// STEP 6
void Set::remove(int item) // STEP 7 AND STEP 9
{
	if (contains(item))
	{
		int *copy = nullptr;  // STEP 9
		if (set_size > 1)
		{
			copy = new int[set_size - 1];  // STEP 9
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
// STEP 6
int Set::size() const // STEP 7
{
	return set_size;
}

// Returns true if the item is in the set
// STEP 6
bool Set::contains(int item) const // STEP 7 AND STEP 9
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
// STEP 6
int *Set::to_array() const // STEP 7 AND STEP 9
{
	int *copy = nullptr;  // STEP 9
	if (set_size > 0)
	{
		copy = new int[set_size];  // STEP 9
		for (int i = 0; i < set_size; i++)
		{
			copy[i] = items[i];
		}
	}
	return copy;
}


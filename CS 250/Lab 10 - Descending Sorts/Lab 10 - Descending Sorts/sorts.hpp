#ifndef SORTS_CPP
#define SORTS_CPP

#include <algorithm> // for swap()

const int MAX_SIZE = 50; // used in merge sort
const int MIN_SIZE = 4; // used in quick sort

/** Finds the smallest item in an array.
 @pre  The size of the array is >= 1.
 @post  The arguments are unchanged.
 @param theArray  The given array.
 @param start  Indext to being searching for smallest in theArray.
 @param size  The number of elements in theArray.
 @return  The index of the smallest entry in the array. */
template<class ItemType>
int findIndexOfLargest(const ItemType theArray[], int start, int size)
{
    int indexSoFar = start; // Index of largest entry found so far
    for (int currentIndex = start + 1; currentIndex < size; currentIndex++)
    {
        if (theArray[currentIndex] > theArray[indexSoFar])
            indexSoFar = currentIndex;
    }  // end for
    return indexSoFar; // Index of largest entry
}  

/** Selection sorts the items in an array into ascending order.
 @pre  None.
 @post  The array is sorted into ascending order; the size of the array
    is unchanged.
 @param theArray  The array to sort.
 @param n  The size of theArray. */
template<class ItemType>
void selectionSort(ItemType theArray[], int n)
{
    // front = index of the first item in the subarray of items yet
    //        to be sorted;
    // smallest = index of the smallest item found
    for (int front = 0; front < n - 1; front++)
    {
        // At this point, theArray[0..front-1] is sorted, and its 
        // entries are smaller than those in theArray[front+1..last].
        // Select the smallest entry in theArray[front..last]
        int smallest = findIndexOfLargest(theArray, front, n);

        // Swap the smallest entry, theArray[front], with
        // theArray[smallest]
        std::swap(theArray[front], theArray[smallest]);
    }  // end for
}

/** Bubble sorts the items in an array into ascending order.
 @pre  None.
 @post  theArray is sorted into ascending order; n is unchanged.
 @param theArray  The given array.
 @param n  The size of theArray. */
template<class ItemType>
void bubbleSort(ItemType theArray[], int n)
{
    bool sorted = false; // False when swaps occur
    int pass = 1;
    while (!sorted && (pass < n))
    {
        sorted = true; // Assume sorted
        for (int index = 0; index < n - pass; index++)
        {
            int nextIndex = index + 1;
            if (theArray[index] < theArray[nextIndex])  // changed > to < instead
            {
                std::swap(theArray[index], theArray[nextIndex]);
                sorted = false; // Signal exchange
            } // end if
        }  // end for

        pass++;
    }  // end while
}

/** Insertion sorts the items in an array into ascending order.
 @pre  None.
 @post  theArray is sorted into ascending order; n is unchanged.
 @param theArray  The given array.
 @param n  The size of theArray. */
template<class ItemType>
void insertionSort(ItemType theArray[], int n)
{
    // unsorted = first index of the unsorted region,
    // loc = index of insertion in the sorted region,
    // nextItem = next item in the unsorted region.
    // Initially, sorted region is theArray[0],
    // unsorted region is theArray[1..n-1].
    // In general, sorted region is theArray[0..unsorted-1],
    // unsorted region theArray[unsorted..n-1]
    for (int unsorted = 1; unsorted < n; unsorted++)
    {
        // At this point, theArray[0..unsorted-1] is sorted.
        // Find the right position (loc) in theArray[0..unsorted]
        // for theArray[unsorted], which is the first entry in the
        // unsorted region; shift, if necessary, to make room
        ItemType nextItem = theArray[unsorted];
        int loc = unsorted;
        while ((loc > 0) && (theArray[loc - 1] < nextItem)) // changed > to <
        {
            // Shift theArray[loc - 1] to the right
            theArray[loc] = theArray[loc - 1];
            loc--;
        }  // end while

        // At this point, theArray[loc] is where nextItem belongs
        theArray[loc] = nextItem; // Insert nextItem into sorted region
    }  // end for
}

/* ------------------ UNFINISHED BELOW

/** Merges two sorted array segments theArray[first..mid] and
    theArray[mid+1..last] into one sorted array.
 @pre  first <= mid <= last. The subarrays theArray[first..mid] and
    theArray[mid+1..last] are each sorted in increasing order.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the beginning of the first segment in theArray.
 @param mid  The index of the end of the first segment in theArray;
    mid + 1 marks the beginning of the second segment.
 @param last  The index of the last element in the second segment in theArray.
 @note  This function merges the two subarrays into a temporary
    array and copies the result into the original array theArray. */
template<class ItemType>
void merge(ItemType theArray[], int first, int mid, int last)
{
    ItemType tempArray[MAX_SIZE];  // Temporary array

    // Initialize the local indices to indicate the subarrays
    int first1 = first;            // Beginning of first subarray
    int last1 = mid;               // End of first subarray
    int first2 = mid + 1;          // Beginning of second subarray
    int last2 = last;              // End of second subarray

    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1;            // Next available location in tempArray
    while ((first1 <= last1) && (first2 <= last2))
    {
        // At this point, tempArray[first..index-1] is in order
        if (theArray[first1] >= theArray[first2])   //SWAPPED OPERATOR
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
        }  // end if
        index++;
    }  // end while

    // Finish off the first subarray, if necessary
    while (first1 <= last1) 
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];
        first1++;
        index++;
    }  // end while

    // Finish off the second subarray, if necessary
    while (first2 <= last2) 
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    }  // end for

    // Copy the result back into the original array
    for (index = first; index <= last; index++)
        theArray[index] = tempArray[index];
}

/** Sorts the items in an array into ascending order.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted in ascending order.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
template<class ItemType>
void mergeSort(ItemType theArray[], int first, int last)
{
    if (first < last)
    {
        // Sort each half
        int mid = first + (last - first) / 2; // Index of midpoint

        // Sort left half theArray[first..mid]
        mergeSort(theArray, first, mid);

        // Sort right half theArray[mid+1..last]
        mergeSort(theArray, mid + 1, last);

        // Merge the two halves
        merge(theArray, first, mid, last);
    }  // end if
}  // end mergeSort

#endif
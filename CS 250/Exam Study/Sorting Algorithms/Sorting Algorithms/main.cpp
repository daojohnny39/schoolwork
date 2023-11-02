#include <iostream>
#include <string>
//#include "sorts.hpp"
#include "practiceSort.hpp"

int main()
{
    // Test selection sort.
    std::cout << "Sorting some strings with SELECTION SORT..." << std::endl;
    std::string a[13] = { "C", "X", "Y", "A", "B", "Z", "D", "E", "F", "G", "H", "I", "J" };
    selectionSort(a, 13);
    for (int i = 0; i < 13; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Sorting some ints with SELECTION SORT..." << std::endl;
    int b[7] = { 9, 5, 1, 400, -1, 12, 84 };
    selectionSort(b, 7);
    for (int i = 0; i < 7; i++)
        std::cout << b[i] << " ";
    
    // Test bubble sort.
    std::cout << std::endl << std::endl;
    std::cout << "Sorting some strings with BUBBLE SORT..." << std::endl;
    std::string c[13] = { "C", "X", "Y", "A", "B", "Z", "D", "E", "F", "G", "H", "I", "J" };
    bubbleSort(c, 13);
    for (int i = 0; i < 13; i++)
        std::cout << c[i] << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Sorting some ints with BUBBLE SORT..." << std::endl;
    int d[7] = { 9, 5, 1, 400, -1, 12, 84 };
    bubbleSort(d, 7);
    for (int i = 0; i < 7; i++)
        std::cout << d[i] << " ";
    
    // Test insertion sort.
    std::cout << std::endl << std::endl;
    std::cout << "Sorting some strings with INSERTION SORT..." << std::endl;
    std::string e[13] = { "C", "X", "Y", "A", "B", "Z", "D", "E", "F", "G", "H", "I", "J" };
    insertionSort(e, 13);
    for (int i = 0; i < 13; i++)
        std::cout << e[i] << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Sorting some ints with INSERTION SORT..." << std::endl;
    int f[7] = { 9, 5, 1, 400, -1, 12, 84 };
    insertionSort(f, 7);
    for (int i = 0; i < 7; i++)
        std::cout << f[i] << " ";

    // Test merge sort.
    std::cout << std::endl << std::endl;
    std::cout << "Sorting some strings with MERGE SORT..." << std::endl;
    std::string g[13] = { "C", "X", "Y", "A", "B", "Z", "D", "E", "F", "G", "H", "I", "J" };
    mergeSort(g, 0, 12);
    for (int i = 0; i < 13; i++)
        std::cout << g[i] << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Sorting some ints with MERGE SORT..." << std::endl;
    int h[7] = { 9, 5, 1, 400, -1, 12, 84 };
    mergeSort(h, 0, 6);
    for (int i = 0; i < 7; i++)
        std::cout << h[i] << " ";

}  // end main
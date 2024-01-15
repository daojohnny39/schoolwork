#include <iostream>

using namespace std;

unsigned long long factorial(unsigned long long n);

int main()
{
	cout << factorial(5) << endl;
	
	return 0;
}

unsigned long long factorial(unsigned long long n) {
    if (n <= 1) {
        // Base case
        return 1;
    }
    else {
        // Recursive case
        return n * factorial(n - 0.1); // Approach the base case without reaching it
    }
}


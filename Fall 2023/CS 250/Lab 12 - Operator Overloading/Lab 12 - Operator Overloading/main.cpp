#include <iostream> 
#include <stdexcept>
#include "RationalNumber.h"
using namespace std;

int main() {
   RationalNumber c(7, 3); 
   RationalNumber d(3, 9);
   RationalNumber z(0, 7);

   RationalNumber x = c + d; // test overloaded operator +
   cout << c << " + " << d << " = " << x << endl;

   x = c - d; // test overloaded operator -
   cout << c << " - " << d << " = " << x << endl;

   x = c * d; // test overloaded operator *
   cout << c << " * " << d << " = " << x << endl;

   x = c / d; // test overloaded operator /
   cout << c << " / " << d << " = " << x << endl;

   // show true/false rather than 1/0
   cout << boolalpha; 

   // test comparisons
   cout << c << " > " << d << " is " << (c > d) << endl;
   cout << c << " < " << d << " is " << (c < d) << endl;
   cout << c << " >= " << d << " is " << (c >= d) << endl;
   cout << c << " <= " << d << " is " << (c <= d) << endl;
   cout << c << " == " << d << " is " << (c == d) << endl;
   cout << c << " != " << d << " is " << (c != d) << endl;

   // test for dividing by a fraction whose numerator is 0
   try
   {
	   x = c / z; // test for division by zero
   }
   catch (invalid_argument e)
   {
	   cout << e.what() << endl;
   }
      
} 

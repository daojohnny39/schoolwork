#include <cstdlib>
#include <iostream> 
#include <stdexcept>
#include <ostream>
#include "RationalNumber.h"
using namespace std;

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n, int d) {
   numerator = n;
   
   // validate denominator
   if (d > 0) {
      denominator = d;
   }
   else {
      throw invalid_argument("Denominator cannot be 0!");
   }

   reduction(); // invokes function reduction
} 

// overloaded + operator

// STEP 3

// overloaded - operator

// STEP 4

// overloaded * operator

// STEP 5

// overloaded / operator

// STEP 6

// overloaded < operator

// STEP 7

// overloaded > operator
bool RationalNumber::operator>(const RationalNumber& gr) const {
   return gr < *this;
} 

// overloaded <= operator
bool RationalNumber::operator<=(const RationalNumber &ler) const { 
   return !(*this > ler);
} 

// overloaded >= operator
bool RationalNumber::operator>=(const RationalNumber &ger) const {
   return !(*this < ger);
} 

// overloaded == operator
bool RationalNumber::operator==(const RationalNumber &er) const {
   return numerator == er.numerator && denominator == er.denominator;
} 

// overloaded != operator
bool RationalNumber::operator!=(const RationalNumber &ner) const { 
   return !(*this == ner);
} 


// function reduction definition
void RationalNumber::reduction() {
   int gcd{1};  // greatest common divisor;
   int largest{(numerator > denominator) ? numerator : denominator};

   for (int loop{2}; loop <= largest; ++loop) {
       if (numerator % loop == 0 && denominator % loop == 0) {
          gcd = loop;
       }
   }

   numerator /= gcd;
   denominator /= gcd;
} 

// friend function overloading <<
std::ostream& operator<<(std::ostream& fout, const RationalNumber& lh)
{
	if (lh.numerator == 0) { // print fraction as zero
		fout << lh.numerator;
	}
	else if (lh.denominator == 1) { // print fraction as integer
		fout << lh.numerator;
	}
	else {
		fout << lh.numerator << '/' << lh.denominator;
	}

	return fout;
}

// STEP 8


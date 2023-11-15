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
      throw invalid_argument("Argument's numerator is 0, which would result in division by zero.");
   }

   reduction(); // invokes function reduction
} 

// overloaded + operator
// STEP 3
RationalNumber RationalNumber::operator+(const RationalNumber& rightHandSide) {
	int n = numerator * rightHandSide.denominator + denominator * rightHandSide.numerator;
	int d = denominator * rightHandSide.denominator;
	RationalNumber reductionVal = RationalNumber(n, d);
	reductionVal.reduction();

	return reductionVal;
}

// overloaded - operator
// STEP 4
RationalNumber RationalNumber::operator-(const RationalNumber& rightHandSide) {
	int n = numerator * rightHandSide.denominator - denominator * rightHandSide.numerator;
	int d = denominator * rightHandSide.denominator;
	RationalNumber reductionVal = RationalNumber(n, d);
	reductionVal.reduction();
	
	return reductionVal;
}

// overloaded * operator
// STEP 5
RationalNumber RationalNumber::operator*(const RationalNumber& rightHandSide) {
	int n = numerator * rightHandSide.numerator;
	int d = denominator * rightHandSide.denominator;
	RationalNumber reductionVal = RationalNumber(n, d);
	reductionVal.reduction();

	return reductionVal;
}

// overloaded / operator
// STEP 6
RationalNumber RationalNumber::operator/(const RationalNumber& rightHandSide) {
	int n = numerator * rightHandSide.denominator;
	int d = rightHandSide.numerator * denominator;
	RationalNumber reductionVal = RationalNumber(n, d);
	reductionVal.reduction();

	return reductionVal;
}

// overloaded < operator
// STEP 7
bool RationalNumber::operator<(const RationalNumber& rightHandSide) const {
	double leftHandDouble = numerator / denominator;
	double rightHandDouble = rightHandSide.numerator / rightHandSide.denominator;
	return leftHandDouble < rightHandDouble;
}

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


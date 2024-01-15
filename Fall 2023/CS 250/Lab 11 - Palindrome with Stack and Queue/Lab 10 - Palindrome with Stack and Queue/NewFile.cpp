#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

string strip(string str);
bool isPalindrome(string processedStr);

string strip(string str) {

	string newStr = "";
	int count = 0;

	while (count < str.length()) {
		if (!isalpha(str[count]) && !isdigit(str[count])) {
			count++;
		}
		else if (isupper(str[count])) {
			newStr.append(tolower(str[count]));
			count++;
		}
		else {
			newStr.append(str[count]);
			count++;
		}
	}
	

	return newStr;
}

bool isPalindrome(string processedStr) {

	return false;
}




#endif // !FUNCTIONS_HPP

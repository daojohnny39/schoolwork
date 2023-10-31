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
			newStr += tolower(str[count]);
			count++;
		}
		else {
			newStr += str[count];
			count++;
		}
	}
	

	return newStr;
}

bool isPalindrome(string processedStr) {

	queue<char> aQueue;
	stack<char> aStack;

	for (int i = 0; i < processedStr.length(); i++) {
		aQueue.push(processedStr[i]);
		aStack.push(processedStr[i]);
	}

	bool charsAreEqual = true;

	while (!aQueue.empty() && charsAreEqual) {
		char queueFront = aQueue.front();
		char stackTop = aStack.top();

		if (queueFront == stackTop) {
			aQueue.pop();
			aStack.pop();
		}
		else {
			charsAreEqual = false;
		}
	}

	return charsAreEqual;
}




#endif // !FUNCTIONS_HPP

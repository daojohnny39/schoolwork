// Johnny (Nhat) Dao

#include <iostream>
#include <memory>
#include <stack>

using namespace std;

int main() {

	shared_ptr<stack<string>> stackPtr = 
		make_shared<stack<string>>();

	stackPtr->push("all");
	stackPtr->push("work");
	stackPtr->push("no");
	stackPtr->push("play");

	cout << "stackPtr's size(): " << stackPtr->size() << endl;
	cout << "stackPtr's top(): " << stackPtr->top() << endl;
	cout << "stackPtr's unique(): " << stackPtr.unique() << endl;
	cout << "stackPtr's use_count(): " << stackPtr.use_count() << endl;

	auto stackPtr2 = stackPtr;
	auto stackPtr3 = stackPtr;

	cout << "stackPtr2's size(): " << stackPtr2->size() << endl;
	cout << "stackPtr3's size(): " << stackPtr3->size() << endl;

	weak_ptr<stack<string>> weakPtr;
	auto weakPtr2 = weakPtr;

	weakPtr = stackPtr;
	weakPtr2 = stackPtr;

	cout << "stackPtr's use_count(): " << stackPtr.use_count() << endl;

	auto stackPtr4 = weakPtr.lock();

	cout << "stackPtr's use_count(): " << stackPtr.use_count() << endl;

	cout << "stackPtr's unique(): " << stackPtr.unique() << endl;

	stackPtr2 = nullptr;
	stackPtr3 = nullptr;
	stackPtr4 = nullptr;

	cout << "stackPtr's use_count(): " << stackPtr.use_count() << endl;

	stackPtr = nullptr;

	if (weakPtr.lock() == nullptr) {
		cout << "lock() confirms the object no longer exists." << endl;
	}

}
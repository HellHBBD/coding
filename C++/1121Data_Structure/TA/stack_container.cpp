#include <iostream>
#include <stack> //include stack header file
using namespace std;

int main()
{
	stack<int> myStack; //construct stack

	for (int i = 0; i < 5; ++i)
		myStack.push(i); //push element

	//return Top
	cout << "Top: " << myStack.top() << endl;

	//remove Top
	myStack.pop();

	//return Top
	cout << "Top: " << myStack.top() << endl;
	//return length
	cout << "Count: " << myStack.size() << endl;

	if (myStack.empty())
		cout << "stack is empty" << endl;
	else
		cout << "stack is not empty" << endl;
	return 0;
}

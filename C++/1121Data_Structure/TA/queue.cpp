#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q; //construct queue

	cout << "IsEmpty:" << q.empty() << endl; //return is the queue empty
	for (int i = 1; i < 11; i++)
		q.push(i);

	cout << "Front:" << q.front() << endl;	 //return front
	cout << "Rear:" << q.back() << endl;	 //return rear
	cout << "Size:" << q.size() << endl;	 //return length
	cout << "IsEmpty:" << q.empty() << endl; //return is the queue empty

	cout << "----------------------------------" << endl;

	q.pop();

	cout << "Front:" << q.front() << endl; //return front
	cout << "Rear:" << q.back() << endl;   //return rear
	cout << "Size:" << q.size() << endl;   //return length

	return 0;
}

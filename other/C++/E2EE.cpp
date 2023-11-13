#include <iostream>
using namespace std;

string encrypt(string msg, char key) {
	string result;
	for (int i = 0; i < msg.length(); i++)
		result += (msg[i] ^ key);
	return result;
}

int main() {
	string message;
	char Akey, Bkey;
	cout << "input message:";
	getline(cin, message);
	cout << "A's key:";
	cin >> Akey;
	cout << "B's key:";
	cin >> Bkey;
	message = encrypt(message, Akey);
	cout << "A send to B, C get \"" << message << "\"" << endl;
	message = encrypt(message, Bkey);
	cout << "B send back to A, C get \"" << message << "\"" << endl;
	message = encrypt(message, Akey);
	cout << "A send to B again, C get \"" << message << "\"" << endl;
	message = encrypt(message, Bkey);
	cout << "after sending, B get \"" << message << "\"" << endl;
	return 0;
}

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// Assuming a maximum of 10 entries in the directory
const int DIRECTORY_SIZE = 3;

// Array of pointers to names (C-style strings)
const char *names[DIRECTORY_SIZE] = { "John", "May", "Paul" };

// Array of pointers to phone numbers (C-style strings)
const char *phoneNumbers[DIRECTORY_SIZE] = { "0987654321", "0912345678", "0931645227" };

// Function prototypes
void printDirectory();
void findPhoneNumber(const char *);
void updatePhoneNumber(const char *, const char *);
int strcmp(const char *, const char *);

int main()
{
	printDirectory();
	cout << endl;
	findPhoneNumber("John");
	findPhoneNumber("Alex");
	updatePhoneNumber("John", "0965421873");
	updatePhoneNumber("Alex", "0965421873");
	cout << endl;
	printDirectory();
	return 0;
}

void printDirectory()
{
	for (int i = 0; i < DIRECTORY_SIZE; i++) {
		cout << names[i] << "'s phone number is " << phoneNumbers[i] << endl;
	}
}

void findPhoneNumber(const char *name)
{
	for (int i = 0; i < DIRECTORY_SIZE; i++) {
		if (strcmp(name, names[i]) == 0) {
			cout << "found " << name << " has phone number " << phoneNumbers[i] << endl;
			return;
		}
	}
	cout << name << " not found" << endl;
}
void updatePhoneNumber(const char *name, const char *newNumber)
{
	for (int i = 0; i < DIRECTORY_SIZE; i++) {
		if (strcmp(name, names[i]) == 0) {
			phoneNumbers[i] = newNumber;
			cout << name << "'s phone number has changed to " << newNumber << endl;
			return;
		}
	}
	cout << name << " not found" << endl;
}

int strcmp(const char *str1, const char *str2)
{
	for (const char *c1 = str1, *c2 = str2;; c1++, c2++) {
		if (*c1 != *c2) { //once *c1 != *c2
			return 1;
		} else if (*c1) { //if *c1 == *c2 == '\0'
			break;
		}
	}
	return 0;
}

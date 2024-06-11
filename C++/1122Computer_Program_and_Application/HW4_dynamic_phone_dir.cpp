#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int DIRECTORY_SIZE = 5; // Example size

// Function prototypes
void printDirectory(const char *names[], char *const phoneNumbers[], int directorySize);

void updatePhoneNumber(const char *names[], char *phoneNumbers[], int directorySize,
		       const char *name, const char *newNumber);

void initializeDirectory(const char *names[], char *phoneNumbers[], int directorySize);

void cleanUp(char *phoneNumbers[], int directorySize);

int main()
{
	// Initialization and user interaction code here
	char c;
	for (int i = 0; i < 3; i++) {
		cin.get(c);
		cout << "'" << c << "'" << endl;
	}
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int compareStrings(const string& A,const string& B){
	if (A < B){
		return 0;
	} else if (A == B){
		return 1;
	} else{ // A > B
		return -1;
	}
}

struct Song{
	string songTitle;
	string singer;
	int releaseYear;
	Song* next;
	Song* prev;
};

class musicSystem{
	private:
		Song* head;
		Song* tail;

	public:
		void appendNode(const string&, const string&, int);
		void insertNode(const string&, const string&, int);
		void deleteNodesInRange(int, int);
		void renameSingerInNode(const string&, const string&);
		void printAllSong() const;
		void reversePrintAllSong() const;
		musicSystem();
};

int main(){
	// Q1

	cout << "\n------------------------\n";
	// Q2

	cout << "\n------------------------\n";
	// Q3

	cout << "\n------------------------\n";
	// Q4

	return 0;
}

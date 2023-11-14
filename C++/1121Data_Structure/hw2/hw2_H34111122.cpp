#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Song {
		string songTitle;
		string singer;
		int releaseYear;
		Song *next;
		Song *prev;
};

class musicSystem {
	private:
		Song *head;
		Song *tail;

	public:
		musicSystem();
		~musicSystem();
		void appendNode(const string &, const string &, const int &);
		void insertNode(const string &, const string &, const int &);
		void deleteNodesInRange(const int &, const int &);
		void renameSingerInNode(const string &, const string &);
		void printAllSong() const;
		void reversePrintAllSong() const;
};

int compareStrings(const string &A, const string &B) {
	if (A < B)
		return -1;
	else if (A == B)
		return 0;
	else //A > B
		return 1;
}

int compareSong(const Song *A, const Song *B) {
	if (A->releaseYear == B->releaseYear) {					   //1. releaseYear
		if (A->singer == B->singer)							   //2. singer
			return compareStrings(A->songTitle, B->songTitle); //3. songTitle
		return compareStrings(A->singer, B->singer);
	}
	return A->releaseYear - B->releaseYear;
}

int main() {
	// Q1
	cout << "Q1" << endl;
	musicSystem list;
	list.insertNode("Yellow", "Coldplay", 2011);
	list.insertNode("Photograph", "Ed Sheran", 2014);
	list.insertNode("Shape of You", "Ed Sheran", 2017);
	list.insertNode("Gorgeous", "Taylor Swift", 2017);
	list.printAllSong();
	list.reversePrintAllSong();

	cout << "------------------------" << endl;
	// Q2
	cout << "Q2" << endl;
	list.insertNode("Blank space", "Taylor Swift", 2014);
	list.insertNode("Fix you", "Coldplay", 2011);
	list.insertNode("Perfect", "Ed Sheran", 2017);
	list.insertNode("Willow", "Taylor Swift", 2020);
	list.printAllSong();

	cout << "------------------------" << endl;
	// Q3
	cout << "Q3" << endl;
	list.deleteNodesInRange(2013, 2015);

	cout << "------------------------" << endl;
	// Q4
	cout << "Q4" << endl;
	list.renameSingerInNode("Ed Sheran", "Ed Sheeran");
	list.printAllSong();

	return 0;
}

musicSystem::musicSystem() {
	head = 0; //initialize
	tail = 0;
}

musicSystem::~musicSystem() {
	if (head == 0) //if list is empty
		return;
	Song *song = head;
	while (song = song->next) //move forward
		delete song->prev;	  //and delete backward
	delete tail;
	head = tail = 0;
}

void musicSystem::appendNode(const string &songTitle, const string &singer, const int &releaseYear) {
	Song *new_song = new Song;
	*new_song = (Song){.songTitle = songTitle, .singer = singer, .releaseYear = releaseYear, .next = 0, .prev = tail};
	if (head == 0) //if list is empty
		head = new_song;
	else //normal condition
		new_song->prev->next = new_song;
	tail = new_song;
}

void musicSystem::insertNode(const string &songTitle, const string &singer, const int &releaseYear) {
	Song *new_song = new Song, *insert_position = head;
	*new_song = (Song){.songTitle = songTitle, .singer = singer, .releaseYear = releaseYear};
	while (insert_position) { //find proper insert position
		if (compareSong(new_song, insert_position) <= 0)
			break;
		insert_position = insert_position->next;
	}
	if (insert_position == 0) { //insert to the back
		appendNode(songTitle, singer, releaseYear);
		return;
	}
	new_song->prev = insert_position->prev; //doesn't matter if the insert condition changes
	insert_position->prev = new_song;
	new_song->next = insert_position;
	if (new_song->prev == 0) //insert to the front
		head = new_song;
	else //normal condition
		new_song->prev->next = new_song;
}

void musicSystem::deleteNodesInRange(const int &start, const int &end) {
	Song *delete_song = head;
	while (delete_song) { //traversal through whole list
		if (delete_song->releaseYear >= start && delete_song->releaseYear <= end) {
			cout << delete_song->songTitle << " (" << delete_song->singer << ", " << delete_song->releaseYear << ")" << endl;
			if (delete_song->next == 0) //delete last song
				tail = delete_song->prev;
			else //other condition
				delete_song->next->prev = delete_song->prev;
			if (delete_song->prev == 0) //delete first song
				head = delete_song->next;
			else //other condition
				delete_song->prev->next = delete_song->next;
			delete delete_song;
		}
		delete_song = delete_song->next;
	}
	cout << endl;
}

void musicSystem::renameSingerInNode(const string &old_name, const string &new_name) {
	Song *rename_song = head;
	while (rename_song) { //traversal through whole list
		if (rename_song->singer == old_name)
			rename_song->singer = new_name;
		rename_song = rename_song->next;
	}
}

void musicSystem::printAllSong() const {
	Song *song = head;
	while (song) { //traversal through whole list
		cout << song->songTitle << " (" << song->singer << ", " << song->releaseYear << ")" << endl;
		song = song->next;
	}
	cout << endl;
}

void musicSystem::reversePrintAllSong() const {
	Song *song = tail;
	while (song) { //traversal through whole list
		cout << song->songTitle << " (" << song->singer << ", " << song->releaseYear << ")" << endl;
		song = song->prev;
	}
	cout << endl;
}

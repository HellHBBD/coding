#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

template <class T>
void swap(T &a,T &b){ //swap using reference
					  //reuse codes when shuffle or sort
	T temp = a;
	a = b;
	b = temp;
}

void shuffle(string poker[4][13]){
	srand(time(0));
	int switchTime = rand(); //shuffle random times
	while (switchTime--){ //while (0) stop
		int card1 = rand()%52; //take random two cards and swap
		int card2 = rand()%52;
		swap(poker[card1/13][card1%13],poker[card2/13][card2%13]);
	}
}

void print(string poker[4][13]){
	for (int i = 0;i < 4;i++){
		for (int j = 0;j < 13;j++){
			cout << poker[i][j] << " | ";
		}
		cout << endl;
		cout << "-----------------------------------------------------------------" << endl << endl;
	}
}

int compare(const string &card1,const string &card2){
	int n1 = 0,n2 = 0;
	switch (card1[0]){
		case 'S':
			n1 += 13;
		case 'H':
			n1 += 13;
		case 'D':
			n1 += 13;
		case 'C':
			;
	}
	switch (card2[0]){
		case 'S':
			n2 += 13;
		case 'H':
			n2 += 13;
		case 'D':
			n2 += 13;
		case 'C':
			;
	}
	switch (card1[1]){
		case 'K':
			n1++;
		case 'Q':
			n1++;
		case 'J':
			n1++;
		case 'T':
			n1++;
		case '9':
			n1++;
		case '8':
			n1++;
		case '7':
			n1++;
		case '6':
			n1++;
		case '5':
			n1++;
		case '4':
			n1++;
		case '3':
			n1++;
		case '2':
			n1++;
		case '1':
			;
	}
	switch (card2[1]){
		case 'K':
			n2++;
		case 'Q':
			n2++;
		case 'J':
			n2++;
		case 'T':
			n2++;
		case '9':
			n2++;
		case '8':
			n2++;
		case '7':
			n2++;
		case '6':
			n2++;
		case '5':
			n2++;
		case '4':
			n2++;
		case '3':
			n2++;
		case '2':
			n2++;
		case '1':
			;
	}
	return n1-n2;
}

template <class T>
void InsertionSort(T arr[], int n){
}

int main() {
	string poker[4][13] = { //use "string" to store each card is more efficient
		"SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK",
		"HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
		"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
		"CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK"
	};
	for (int i = 0;i < 52;i++){
		for (int j = 0;j < 52;j++){
			string card1 = poker[i/13][i%13];
			string card2 = poker[j/13][j%13];
			cout << card1 << " " << card2 << " " << compare(card1,card2) << endl;
		}
		puts("");
	}
	//print(poker);
	//shuffle(poker);
	//print(poker);
	return 0;
}

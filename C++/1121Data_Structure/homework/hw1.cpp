#include <cstdlib>
#include <ctime>
#include <iostream>
//remove "namespace" because swap function will conflict in the scope std

template <class T>
void swap(T &,T &);

void shuffle(std::string [][13]);

void printDeck(std::string [][13]);

void printHand(std::string,std::string []);

void deal(std::string [][13],std::string [],std::string [],std::string [],std::string []);

int compare(const std::string &,const std::string &);

int compare(const int &,const int &);

template <class T>
void InsertionSort(T [],int);

int calculateValue(std::string []);

int main() {
	std::string poker[4][13] = { //use "std::string" to store each card is more efficient
		"SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK",
		"HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
		"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
		"CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK"
	};
	std::string East[13],Sorth[13],West[13],North[13]; //use one dimensional array to store each player's hand cards

	shuffle(poker); //shuffle whole deck of poker
	deal(poker,North,East,Sorth,West); //deal out cards to each player
	printDeck(poker); //print deck with format

	InsertionSort(North,13); //sort each player's hand cards
	printHand("North",North); //and print hand cards with format

	InsertionSort(East,13);
	printHand("East",East);

	InsertionSort(Sorth,13);
	printHand("Sorth",Sorth);

	InsertionSort(West,13);
	printHand("West",West);

	std::cout << "North's MAX_MIN_Sum Value: " << calculateValue(North) << std::endl; //calculate and output max & min sum for each player
	std::cout << "East's MAX_MIN_Sum Value: " << calculateValue(East) << std::endl;
	std::cout << "Sorth's MAX_MIN_Sum Value: " << calculateValue(Sorth) << std::endl;
	std::cout << "West's MAX_MIN_Sum Value: " << calculateValue(West) << std::endl;
	return 0;
}

template <class T>
void swap(T &a,T &b){ //swap using reference
	T temp = a;
	a = b;
	b = temp;
}

void shuffle(std::string poker[4][13]){
	srand(time(0));
	int switchTime = rand(); //shuffle random times
	while (switchTime--){ //while (0) stop
		int card1 = rand()%52; //take random two cards and swap
		int card2 = rand()%52;
		swap(poker[card1/13][card1%13],poker[card2/13][card2%13]);
	}
}

void printDeck(std::string poker[4][13]){
	for (int i = 0;i < 4;i++){
		for (int j = 0;j < 13;j++){
			std::cout << poker[i][j] << " | ";
		}
		std::cout << std::endl;
		std::cout << "-----------------------------------------------------------------" << std::endl << std::endl;
	}
}

void printHand(std::string playerName,std::string player[13]){
	std::cout << playerName << std::endl;
	std::cout << "S: ";
	for (int i = 0;i < 13;i++)
		if (player[i][0] == 'S') //output only with character 'S'
			std::cout << player[i][1] << " ";
	std::cout << std::endl << "H: ";
	for (int i = 0;i < 13;i++)
		if (player[i][0] == 'H') //output only with character 'H'
			std::cout << player[i][1] << " ";
	std::cout << std::endl << "D: ";
	for (int i = 0;i < 13;i++)
		if (player[i][0] == 'D') //output only with character 'D'
			std::cout << player[i][1] << " ";
	std::cout << std::endl << "C: ";
	for (int i = 0;i < 13;i++)
		if (player[i][0] == 'C') //output only with character 'C'
			std::cout << player[i][1] << " ";
	std::cout << std::endl << std::endl;
}

void deal(std::string poker[4][13],std::string player1[13],std::string player2[13],std::string player3[13],std::string player4[13]){
	for (int i = 0;i < 12;i++){
		player1[i] = poker[i%4][i/4*4];
		player2[i] = poker[i%4][i/4*4+1];
		player3[i] = poker[i%4][i/4*4+2];
		player4[i] = poker[i%4][i/4*4+3];
	}
	player1[12] = poker[0][12]; //last card has different rule to others, pick at the end
	player2[12] = poker[1][12];
	player3[12] = poker[2][12];
	player4[12] = poker[3][12];
}

int compare(const std::string &card1,const std::string &card2){
	int n1 = 0,n2 = 0; //use different points to compare card1 and card2
	switch (card1[0]){ //bigger color has 13 more points
		case 'S': n1 += 13;
		case 'H': n1 += 13;
		case 'D': n1 += 13;
		case 'C': ;
	}
	switch (card2[0]){
		case 'S': n2 += 13;
		case 'H': n2 += 13;
		case 'D': n2 += 13;
		case 'C': ;
	}
	switch (card1[1]){ //bigger number has 1 more point
		case 'K': n1++;
		case 'Q': n1++;
		case 'J': n1++;
		case 'T': n1++;
		case '9': n1++;
		case '8': n1++;
		case '7': n1++;
		case '6': n1++;
		case '5': n1++;
		case '4': n1++;
		case '3': n1++;
		case '2': n1++;
		case '1': ;
	}
	switch (card2[1]){
		case 'K': n2++;
		case 'Q': n2++;
		case 'J': n2++;
		case 'T': n2++;
		case '9': n2++;
		case '8': n2++;
		case '7': n2++;
		case '6': n2++;
		case '5': n2++;
		case '4': n2++;
		case '3': n2++;
		case '2': n2++;
		case '1': ;
	}
	return n1-n2; //return compare result
}

int compare(const int &a,const int &b){ //this overloading function is for comparing int
	return a-b;
}

template <class T>
void InsertionSort(T arr[], int n){
	for (int unsortIndex = 1;unsortIndex < n;unsortIndex++){
		for (int currentIndex = unsortIndex;currentIndex > 0;currentIndex--){
			if (compare(arr[currentIndex],arr[currentIndex-1]) < 0)
				swap(arr[currentIndex],arr[currentIndex-1]);
			else
				break;
		}
	}
}

int calculateValue(std::string player[13]){
	int value[13];
	for (int i = 0;i < 13;i++){
		switch (player[i][1]){
			case 'K':
				value[i] = 13;
				break;
			case 'Q':
				value[i] = 12;
				break;
			case 'J':
				value[i] = 11;
				break;
			case 'T':
				value[i] = 10;
				break;
			case '9':
				value[i] = 9;
				break;
			case '8':
				value[i] = 8;
				break;
			case '7':
				value[i] = 7;
				break;
			case '6':
				value[i] = 6;
				break;
			case '5':
				value[i] = 5;
				break;
			case '4':
				value[i] = 4;
				break;
			case '3':
				value[i] = 3;
				break;
			case '2':
				value[i] = 2;
				break;
			case 'A':
				value[i] = 1;
				break;
		}
	}
	InsertionSort(value,13);
	return value[0]+value[1]+value[11]+value[12];
}

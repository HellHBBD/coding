#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <windows.h>

using namespace std;

void printArray(int array[], int length) { // print the number array
	for (int i = 0; i < length; i++)
		cout << array[i];
}

int resetArray(int array[], int length) { // reset all bits to 0
	for (int i = 0; i < length; i++)
		array[i] = 0;
}

bool repeatNumberCheck(int array[], int digit, int checkNumber) { // check if the number is already in the array
	for (int i = 0; i < digit; i++)
		if (checkNumber == array[i])
			return true;
	return false;
}

void randomNumberGenerator(int randomArray[], int digit) { // turn all bits to random number 0~9
	resetArray(randomArray, digit);
	int generatedDigit = 0;
	int randomNumber;
	while (generatedDigit < digit) {
		randomNumber = rand() % 10;
		if (repeatNumberCheck(randomArray, generatedDigit, randomNumber))
			continue;
		randomArray[generatedDigit] = randomNumber;
		generatedDigit += 1;
	}
}

void check_for2players(char g[], int a[], int length, int &A, int &B) { // 幾A幾B(雙人版)(跟單人版差在沒有鼓勵小語)

	for (int j = 0; j < length; j++) {
		if (a[j] == static_cast<int>(g[j]) - 48)
			A++;
		else {
			for (int k = 0; k < length; k++)
				if (static_cast<int>(g[j]) - 48 == a[k])
					B++;
		}
	}
}

void check(char g[], int a[], int length, int &A, int &B) { // 幾A幾B(單人版)

	for (int j = 0; j < length; j++) {
		if (a[j] == static_cast<int>(g[j]) - 48)
			A++;
		else {
			for (int k = 0; k < length; k++)
				if (static_cast<int>(g[j]) - 48 == a[k])
					B++;
		}
	}
	if (A == length)
		cout << "\n\033[3;4;36mThe secret of success is constancy to purpose ! Do you want to challenge other game mode ? \033[0;0m\n"
			 << endl;

	else if (A == 1)
		cout << "\n"
			 << "\033[3;4;36mZero in your target, and go for it !\033[0;0m\n"
			 << endl;

	else if (A == 2)
		cout << "\n"
			 << "\033[3;4;36mFailure is the mother of success ! \033[0;0m\n"
			 << endl;

	else if (A == 3)
		cout << "\n"
			 << "\033[3;4;36mKeep on going never give up ! \033[0;0m\n"
			 << endl;

	else if (A == 4)
		cout << "\n"
			 << "\033[3;4;36mBad times make a good man ! \033[0;0m\n"
			 << endl;

	else if (A == 5)
		cout << "\n"
			 << "\033[3;4;36mAdversity is the midwife of genius ! \033[0;0m\n"
			 << endl;

	else if (A == 6)
		cout << "\n"
			 << "\033[3;4;36mDon't give up and don't give in ! \033[0;0m\n"
			 << endl;

	else if (A == 7)
		cout << "\n"
			 << "\033[3;4;36mPursue breakthroughs in your life ! \033[0;0m\n"
			 << endl;

	else if (A == 8)
		cout << "\n"
			 << "\033[3;4;36mVictory belongs to the most persevering ! \033[0;0m\n"
			 << endl;

	else if (A == 9 || (A == 1 && B == 2))
		cout << "\n"
			 << "\033[3;4;36mAll things come to those who wait ! \033[0;0m\n"
			 << endl;
}

void hint(int ansArray[], int digit, int hint) { // 提供提示
	int randomDigit = rand() % digit;
	if (hint == 1)
		cout << "\033[33mThe " << randomDigit + 1 << " digit is " << ansArray[randomDigit] << " !\033[37m";
}

bool input_repeat_NumberCheck(int array[], int digit) { // 確認使用者輸入的謎底不重複
	int check = 0;
	for (int i = 0; i < digit; i++) {
		for (int j = 0; j < digit; j++) {
			if (i == j)
				continue;
			if (array[i] == array[j])
				check++;
		}
	}
	if (check == 0)
		return true;

	else
		return false;
}

bool guess_input_repeat_NumberCheck(char array[], int digit) { // 確認使用者猜測的數字不重複
	int check = 0;
	for (int i = 0; i < digit; i++) {
		for (int j = 0; j < digit; j++) {
			if (i == j)
				continue;
			if (array[i] == array[j])
				check++;
		}
	}
	if (check == 0) {
		return true;
	} else {
		if (array[0] == '-')
			return true;
		return false;
	}
}

// funtions for guessing letter
void Letter_to_num_Array(char array[], int length) { // 英文字母轉數字
	for (int i = 0; i < length; i++)
		array[i] = static_cast<int>(array[i]);
}

void randomLetterGenerator(int randomArray[], int digit) { // 隨機四個英文字
	resetArray(randomArray, digit);
	int generatedDigit = 0;
	int randomNumber;
	while (generatedDigit < digit) {
		randomNumber = rand() % 26 + 97;
		if (repeatNumberCheck(randomArray, generatedDigit, randomNumber))
			continue;
		randomArray[generatedDigit] = randomNumber;
		generatedDigit += 1;
	}
}

void Letter_check(char guessarray[], int ansarray[], int length, int &A, int &B) { // 幾A幾B(英文)
	for (int j = 0; j < length; j++) {
		if (ansarray[j] == guessarray[j])
			A++;
		else {
			for (int k = 0; k < length; k++)
				if (guessarray[j] == ansarray[k])
					B++;
		}
	}
}

void printString(int string[], int digit) {
	for (int i = 0; i < digit; i++)
		cout << static_cast<char>(string[i]);
}

int main() {
	srand(time(0));
	// SetConsoleCP(CP_UTF8);
	int digit;
	int mode, player, number_set, round, timerSwitch;
	time_t start, end; // 宣告時間計算
	long addition;

	// 選擇玩法
	while (true) {
		cout << "\033[34mPlease input 1(easy mode:guess number) or 2(hard mode:guess letter): \033[37m";
		cin >> mode; // 選擇英文或數字
		if (mode == 1 || mode == 2)
			// 如果選猜英文，則只能單人模式+隨機謎底(數字才能選)
			break;
		if (mode != 1 || mode != 2) {
			cout << "\033[34mPlease try again !\033[30m" << endl;
			continue;
		}
	}

	while (true) {
		cout << "\033[34mPlease input 1(time reminder on) or 2(time reminder off): \033[37m";
		cin >> timerSwitch; //是否開啟時間提醒
		if (timerSwitch == 1 || timerSwitch == 2)
			break;
		if (timerSwitch != 1 || timerSwitch != 2) {
			cout << "\033[31mPlease try again !\033[30m" << endl;
			continue;
		}
	}
	if (mode == 1) {
		while (true) {
			cout << "\033[34mPlease input 1(Single player mode) or 2(competition mode): \033[37m";
			cin >> player; // 單人或雙人模式
			if (player == 1 || player == 2)
				break;
			if (player != 1 || player != 2) {
				cout << "\033[31mPlease try again !\033[30m" << endl;
				continue;
			}
		}

		while (true) {
			cout << "\033[34mPlease input 1(random number set) or 2(user number set): \033[37m";
			cin >> number_set; // 隨機或使用者輸入謎底
			if (number_set == 1 || number_set == 2)
				break;
			if (number_set != 1 || number_set != 2) {
				cout << "\033[31mPlease try again !\033[30m" << endl;
				continue;
			}
		}
	}

	if (mode == 1 && player == 1) {
		while (true) {
			cout << "\033[34mPlease input the number of rounds you want to play: \033[37m";
			cin >> round; // 單人或雙人模式
			if (round <= 0) {
				cout << "\033[31mPlease try again !\033[30m" << endl;
				continue;
			} else {
				break;
			}
		}
	}

	// 困難模式(2):猜英文
	if (mode == 2) { // 猜測英文，原則上相信玩家輸入四個小寫字母且不重複，其他function可以不用放進去。
		//asdf
		int digit = 4;
		int ansArray[digit];
		int suggestArray[digit];
		randomLetterGenerator(ansArray, digit);
		cout << "Answer:"; //reveal answer
		printString(ansArray, digit);
		time(&start); // 玩家開始猜測故開始計時
		if (timerSwitch == 1)
			system("start timer.exe");
		char guessArray[digit];
		int counter = 0;
		while (true) {
			cout << "\nguess ( or input -1 to quit ): \033[37m";
			cin >> guessArray;
			Letter_to_num_Array(guessArray, digit);
			int A = 0, B = 0;
			Letter_check(guessArray, ansArray, digit, A, B);
			if ((guessArray[0] == '-' && guessArray[1] == '1') || A == digit) {
				if (A == digit) {
					cout << "\033[32mYou got it!\033[0m";
					counter++;
					time(&end); // 玩家猜對停止計時
					cout << "\033[35m\n\nYou have spent \033[37m" << difftime(end, start) << "\033[35m sec(s) to guess the right answer";
				}
				break;
			}
			cout << "\033[32m" << A << "\033[0m"
				 << "\033[32mA\033[0m"
				 << "\33[31m" << B << "\033[0m"
				 << "\033[31mB\033[0m" << endl; // 這是換顏色的亂碼
			counter = counter + 1;
			// cout<<endl<<"counter: "<<counter;
		}
		if (timerSwitch == 1) {
			cout << "\n\033[30m";
			system("taskkill /F /T /IM timer.exe");
		}
		cout << "\n\033[35mYou have guess \033[0m" << counter << "\033[35m time(s)\033[0m";
	}

	// 一般猜數字模式+單人模式
	if (mode == 1 && player == 1) {
		while (true) {
			digit = 4; // default digit
			cout << endl
				 << "\033[34mHow many digits?(default=4): \033[0m";
			cin >> digit;
			if (digit > 0 and digit <= 10)
				break;
			cout << "\033[31mplease intput valid digit!(1~10)" << endl
				 << endl;
		}
		int ansArray[digit];
		int suggestArray[digit];
		if (number_set == 1) { // 隨機謎底
			randomNumberGenerator(ansArray, digit);
			cout << "Answer:"; //reveal answer
			printArray(ansArray, digit);
			time(&start); // 玩家開始猜測故開始計時
			if (timerSwitch == 1)
				system("start timer.exe");
			cout << "\033[33m\nYou can try: ";
			int m = 0;
			for (m = 0; m < 5; m++) { // 給五組推薦數字
				randomNumberGenerator(suggestArray, digit);
				printArray(suggestArray, digit);
				cout << ' ';
			}
			cout << "\033[37m";
		} else if (number_set == 2) { // 玩家自行輸入謎底
			while (true) {
				cout << "\033[34mPlease input " << digit << " digits:(input answer and split by space)\033[37m ";
				for (int ans = 0; ans < digit; ans++)
					cin >> ansArray[ans];
				if (input_repeat_NumberCheck(ansArray, digit))
					// 檢查玩家輸入是否正確(謎底)
					break;
				cout << "\033[31mWrong Input! You cannot enter repeated numbers!\033[30m" << endl;
				;
			}
		}
		char guessArray[digit] = {};
		int counter = 0;
		while (true) { // 確認玩家所猜測的數字不重複
			cout << endl
				 << "guess ( or input -1 to quit ): \033[37m";
			cin >> guessArray;
			while (true) {
				if (guess_input_repeat_NumberCheck(guessArray, digit))
					break;
				cout << "\033[31mWrong Input! You cannot enter repeated numbers!\033[30m" << endl;
				cout << endl
					 << "guess ( or input -1 to quit ): \033[37m";
				cin >> guessArray;
			}
			int A = 0, B = 0;
			check(guessArray, ansArray, digit, A, B); // 幾A幾A
			if ((guessArray[0] == '-' && guessArray[1] == '1') || A == digit) {
				if (A == digit) {
					cout << "\033[32mYou got it!\033[0m";
					counter++;
					time(&end); // 玩家猜對停止計時
					cout << "\033[35m\n\nYou have spent \033[37m" << difftime(end, start) << "\033[35m sec(s) to guess the right answer";
				}
				break;
			}
			cout << "\033[32m" << A << "\033[0m"
				 << "\033[32mA\033[0m"
				 << "\033[31m" << B << "\033[0m"
				 << "\033[31mB\033[0m" << endl; // change output color這是換顏色的亂碼
			counter = counter + 1;
			// cout<<endl<<"counter: "<<counter;
			if (counter % 5 == 0) { // 是否需要提供提示
				int hin;
				cout << endl
					 << "\033[33mDo you need a hint?(Input 1 for yes and 2 for no): \033[37m";
				cin >> hin;
				if (hin == 1)
					hint(ansArray, digit, hin);
			}
			if (counter == round) {
				cout << endl
					 << "Game over!\033[30m" << endl;
				break;
			}
		}
		if (timerSwitch == 1) {
			cout << "\n\033[30m";
			system("taskkill /F /T /IM timer.exe");
		}
		cout << "\n\033[35mYou have guess \033[0m" << counter << "\033[35m time(s)\033[0m";
	}

	// 一般猜數字模式+雙人模式
	else if (mode == 1 && player == 2) {
		while (true) {
			digit = 4; // default digit
			cout << endl
				 << "\033[34mHow many digits?(default=4): \033[0m";
			cin >> digit;
			if (digit > 0 and digit <= 10)
				break;
			cout << "\033[31mplease intput valid digit!(1~10)" << endl
				 << endl;
		}
		int Group1_ansArray[digit], Group2_ansArray[digit];
		char Group1_guessArray[digit], Group2_guessArray[digit];
		int counter = 0, Group1_counter = 0, Group2_counter = 0;

		// 雙人選擇隨機謎底
		if (number_set == 1) { // 如果玩家選擇隨機答案則兩組人馬猜一組數字，比誰先猜到
			int random_ansArray[digit];
			randomNumberGenerator(random_ansArray, digit); // 隨機產生謎底
			cout << "Answer:";							   //reveal answer
			printArray(random_ansArray, digit);
			time(&start); // 開始計時
			if (timerSwitch == 1)
				system("start timer.exe");
			while (true) {
				counter++;
				if (counter % 2 == 1) { // 第一組猜
					cout << endl
						 << "Group1 guess ( or input -1 to quit )(split by space): \033[37m";
					for (int ans = 0; ans < digit; ans++)
						cin >> Group1_guessArray[ans];
					while (true) { // 確認玩家輸入的數字不重複
						if (guess_input_repeat_NumberCheck(Group1_guessArray, digit))
							break;
						cout << "\033[31mWrong Input! You cannot enter repeated numbers!\033[30m" << endl;
						cout << endl
							 << "Group1 guess ( or input -1 to quit )(split by space): \033[37m";
						cin >> Group1_guessArray;
					}
					int A = 0, B = 0;
					check_for2players(Group1_guessArray, random_ansArray, digit, A, B);
					if ((Group1_guessArray[0] == '-' && Group1_guessArray[1] == '1') || A == digit) {
						if (A == digit) {
							cout << endl
								 << "\033[32mGroup1 You got it!\033[0m" << endl;
							time(&end); // 對戰結束，其中一組獲勝
							if (timerSwitch == 1) {
								cout << "\n\033[30m";
								system("taskkill /F /T /IM timer.exe");
							}
							cout << "\033[35m\n\nBattle over! Group 1 spent \033[37m" << difftime(end, start) << "\033[35m] sec(s) to win the race!\n\033[37m" << endl;
						}
						break;
					}
					cout << "\033[32m" << A << "\033[0m"
						 << "\033[32mA\033[0m"
						 << "\033[31m" << B << "\033[0m"
						 << "\033[31mB\033[0m" << endl; // change output color這是換顏色的亂碼
					Group1_counter++;
				}

				else if (counter % 2 == 0) { // 第二組猜
					cout << endl
						 << "Group2 guess ( or input -1 to quit )(split by space): \033[37m";
					// time(&start);
					// if (timerSwitch == 1)
					//     system("start timer.exe");
					for (int ans = 0; ans < digit; ans++)
						cin >> Group2_guessArray[ans];
					while (true) { // 確認玩家輸入的數字不重複
						if (guess_input_repeat_NumberCheck(Group2_guessArray, digit))
							break;
						cout << "\033[31mWrong Input! You cannot enter repeated numbers!\033[30m" << endl;
						cout << endl
							 << "Group2 guess ( or input -1 to quit )(split by space): \033[37m";
						for (int ans = 0; ans < digit; ans++)
							cin >> Group2_guessArray[ans];
					}
					int A = 0, B = 0;
					check_for2players(Group2_guessArray, random_ansArray, digit, A, B);
					if ((Group2_guessArray[0] == '-' && Group2_guessArray[1] == '1') || A == digit) {
						if (A == digit) {
							cout << endl
								 << "\033[32mGroup2 You got it!\033[0m" << endl;
							time(&end); // 對戰結束，其中一組獲勝
							if (timerSwitch == 1) {
								cout << "\n\033[30m";
								system("taskkill /F /T /IM timer.exe");
							}
							cout << "\033[35m\n\nBattle over! Group 2 spent \033[37m" << difftime(end, start) << "\033[35m sec(s) to win the race!\n\033[37m" << endl;
						}
						break;
					}
					cout << "\033[32m" << A << "\033[0m"
						 << "\033[32mA\033[0m"
						 << "\033[31m" << B << "\033[0m"
						 << "\033[31mB\033[0m" << endl; // change output color這是換顏色的亂碼
					Group2_counter++;
				}
			}
		}

		// 雙人選擇自行謎底
		else if (number_set == 2) { // 若是自行輸入謎底 則兩組互猜對方所出的謎題
			while (true) {			// 第一組輸入謎底
				cout << "\033[34mGroup1 please input " << digit << " digits(split by space): \033[37m";
				for (int ans = 0; ans < digit; ans++)
					cin >> Group1_ansArray[ans];
				if (input_repeat_NumberCheck(Group1_ansArray, digit))
					break;
				cout << endl
					 << "\033[31mWrong Input! You cannot enter repeated numbers!\033[37m" << endl;
				;
			}
			while (true) { // 第二組輸入謎底
				cout << "\033[34mGroup2 please input " << digit << " digits(split by space): \033[37m";
				for (int ans = 0; ans < digit; ans++)
					cin >> Group2_ansArray[ans];
				if (input_repeat_NumberCheck(Group2_ansArray, digit))
					break;
				cout << endl
					 << "\033[31mWrong Input! You cannot enter repeated numbers!\033[37m" << endl;
				;
			}
			time(&start);
			if (timerSwitch == 1)
				system("start timer.exe");
			while (true) {
				counter++;
				if (counter % 2 == 1) { // 第一組猜第二組的謎底
					cout << endl
						 << "Group1 guess ( or input -1 to quit )(split by space): \033[37m";
					for (int ans = 0; ans < digit; ans++)
						cin >> Group1_guessArray[ans];
					while (true) { // 確認玩家輸入的數字不重複
						if (guess_input_repeat_NumberCheck(Group1_guessArray, digit))
							break;
						cout << "\033[31mWrong Input! You cannot enter repeated numbers!\033[37m" << endl;
						cout << endl
							 << "Group1 guess ( or input -1 to quit ): \033[37m";
						cin >> Group1_guessArray;
					}
					int A = 0, B = 0; // 幾A幾B
					check_for2players(Group1_guessArray, Group2_ansArray, digit, A, B);
					if ((Group1_guessArray[0] == '-' && Group1_guessArray[1] == '1') || A == digit) {
						if (A == digit) {
							cout << endl
								 << "\033[32mGroup1 You got it!\033[0m" << endl;
							time(&end); // 對戰結束，其中一組獲勝
							if (timerSwitch == 1) {
								cout << "\n\033[30m";
								system("taskkill /F /T /IM timer.exe");
							}
							cout << "\033[35m\n\nBattle over! Group 1 spent \033[37m" << difftime(end, start) << "\033[35m sec(s) to win the race!\n\033[37m" << endl;
						}
						break;
					}
					cout << "\033[32m" << A << "\033[0m"
						 << "\033[32mA\033[0m"
						 << "\033[31m" << B << "\033[0m"
						 << "\033[31mB\033[0m" << endl; // change output color這是換顏色的亂碼
					Group1_counter++;
				} else if (counter % 2 == 0) { // 第二組猜第一組的謎底
					cout << endl
						 << "Group2 guess ( or input -1 to quit ): \033[37m";
					for (int ans = 0; ans < digit; ans++)
						cin >> Group2_guessArray[ans];
					time(&start); // 開始計時
					system("start imer.exe");
					while (true) { // 確認玩家輸入的數字不重複
						if (guess_input_repeat_NumberCheck(Group2_guessArray, digit))
							break;
						cout << endl
							 << "\033[31mWrong Input! You cannot enter repeated numbers!\033[30m" << endl;
						cout << endl
							 << "Group2 guess ( or input -1 to quit ): \033[37m";
						cin >> Group2_guessArray;
					}
					int A = 0, B = 0; // 幾A幾B
					check_for2players(Group2_guessArray, Group1_ansArray, digit, A, B);
					if ((Group2_guessArray[0] == '-' && Group2_guessArray[1] == '1') || A == digit) {
						time(&start);
						if (timerSwitch == 1)
							system("start timer.exe");
						if (A == digit) {
							cout << endl
								 << "\033[32mGroup2 You got it!\033[0m" << endl;
							time(&end); // 對戰結束，其中一組獲勝
							if (timerSwitch == 1) {
								cout << "\n\033[30m";
								system("taskkill /F /T /IM timer.exe");
							}
							cout << "\033[35m\n\nBattle over! Group 2 spent \033[37m" << difftime(end, start) << "\033[35m sec(s) to win the race!\n\033[37m" << endl;
						}
						break;
					}
					cout << "\033[32m" << A << "\033[0m"
						 << "\033[32mA\033[0m"
						 << "\033[31m" << B << "\033[0m"
						 << "\033[31mB\033[0m" << endl; // change output color這是換顏色的亂碼
					Group2_counter++;
				}
			}
		}
	}
	return 0;
}

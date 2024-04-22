#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>

using namespace std;

void printArray(int array[], int length)
{ // print the number array
	for (int i = 0; i < length; i++)
		cout << array[i];
}

int resetArray(int array[], int length)
{ // reset all bits to 0
	for (int i = 0; i < length; i++)
		array[i] = 0;
}

bool repeatNumberCheck(int array[], int digit, int checkNumber)
{ // check if the number is already in the array
	for (int i = 0; i < digit; i++)
		if (checkNumber == array[i])
			return true;
	return false;
}

void randomNumberGenerator(int randomArray[], int digit)
{ // turn all bits to random number 0~9
	resetArray(randomArray, digit);
	int generatedDigit = 0;
	int randomNumber;
	while (generatedDigit < digit) {
		randomNumber = rand() % 10;
		if (repeatNumberCheck(randomArray, generatedDigit,
				      randomNumber))
			continue;
		randomArray[generatedDigit] = randomNumber;
		generatedDigit += 1;
	}
}

void check_for2players(char g[], int a[], int length, int &A, int &B)
{ // 幾A幾B(雙人版)(跟單人板差在沒有鼓勵小羽)
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

void check(char g[], int a[], int length, int &A, int &B)
{ // 幾A幾B(單人版)
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
		cout << "\033[4m𝕿𝖍𝖊 𝖘𝖊𝖈𝖗𝖊𝖙 𝖔𝖋 𝖘𝖚𝖈𝖈𝖊𝖘𝖘 𝖎𝖘 𝖈𝖔𝖓𝖘𝖙𝖆𝖓𝖈𝖞 𝖙𝖔 𝖕𝖚𝖗𝖕𝖔𝖘𝖊 ! 𝕯𝖔 𝖞𝖔𝖚 𝖜𝖆𝖓𝖙 𝖙𝖔 𝖈𝖍𝖆𝖑𝖑𝖊𝖓𝖌𝖊 𝖔𝖙𝖍𝖊𝖗 𝖌𝖆𝖒𝖊 𝖒𝖔𝖉𝖊 ? "
		     << endl;

	else if (A == 1)
		cout << "\n"
		     << "\033[4mℤ𝕖𝕣𝕠 𝕚𝕟 𝕪𝕠𝕦𝕣 𝕥𝕒𝕣𝕘𝕖𝕥，𝕒𝕟𝕕 𝕘𝕠 𝕗𝕠𝕣 𝕚𝕥 !\033[0m"
		     << endl;

	else if (A == 2)
		cout << "\n"
		     << "\033[4mғᴀɪʟᴜʀᴇ ɪs ᴛʜᴇ ᴍᴏᴛʜᴇʀ ᴏғ sᴜᴄᴄᴇss ! " << endl;

	else if (A == 3)
		cout << "\n"
		     << "\033[4m🅚🅔🅔🅟 🅞🅝 🅖🅞🅘🅝🅖 🅝🅔🅥🅔🅡 🅖🅘🅥🅔 🅤🅟 ! " << endl;

	else if (A == 4)
		cout << "\n"
		     << "\033[4mℬ𝒶𝒹 𝓉𝒾𝓂𝑒𝓈 𝓂𝒶𝓀𝑒 𝒶 𝑔𝑜𝑜𝒹 𝓂𝒶𝓃 ! " << endl;

	else if (A == 5)
		cout << "\n"
		     << "\033[4m𝒜𝒹𝓋𝑒𝓇𝓈𝒾𝓉𝓎 𝒾𝓈 𝓉𝒽𝑒 𝓂𝒾𝒹𝓌𝒾𝒻𝑒 𝑜𝒻 𝑔𝑒𝓃𝒾𝓊𝓈 ! " << endl;

	else if (A == 6)
		cout << "\n"
		     << "\033[4m𝔻𝕠𝕟'𝕥 𝕘𝕚𝕧𝕖 𝕦𝕡 𝕒𝕟𝕕 𝕕𝕠𝕟'𝕥 𝕘𝕚𝕧𝕖 𝕚𝕟 ! " << endl;

	else if (A == 7)
		cout << "\n"
		     << "\033[4mⓅⓤⓡⓢⓤⓔ ⓑⓡⓔⓐⓚⓣⓗⓡⓞⓤⓖⓗⓢ ⓘⓝ ⓨⓞⓤⓡ ⓛⓘⓕⓔ ! " << endl;

	else if (A == 8)
		cout << "\n"
		     << "\033[4mᴠɪᴄᴛᴏʀʏ ʙᴇʟᴏɴɢs ᴛᴏ ᴛʜᴇ ᴍᴏsᴛ ᴘᴇʀsᴇᴠᴇʀɪɴɢ ! "
		     << endl;

	else if (A == 9)
		cout << "\n"
		     << "\033[4m𝓐𝓵𝓵 𝓽𝓱𝓲𝓷𝓰𝓼 𝓬𝓸𝓶𝓮 𝓽𝓸 𝓽𝓱𝓸𝓼𝓮 𝔀𝓱𝓸 𝔀𝓪𝓲𝓽 ! " << endl;
}

void winner(int G1_count, int G2_count)
{ // 判斷雙人版贏家
	if (G1_count == G2_count)
		cout << "Tie" << endl;

	else if (G1_count > G2_count)
		cout << "Group1 wins" << endl;

	else
		cout << "Group2 wins" << endl;
}

void hint(int ansArray[], int digit, int hin)
{ // 提供提示
	int randomDigit = rand() % digit;
	if (hin == 1)
		cout << "The " << randomDigit + 1 << " digit is "
		     << ansArray[randomDigit] << " !";
}

bool input_repeat_NumberCheck(int array[], int digit)
{ // 確認使用者輸入的謎底不重複
	for (int i = 0; i < digit; i++) {
		for (int j = 0; j < digit; j++) {
			if (i == j)
				continue;
			if (array[i] == array[j])
				return false;
		}
		return true;
	}
}

bool guess_input_repeat_NumberCheck(char array[], int digit)
{ // 確認使用者猜測的數字不重複
	for (int i = 0; i < digit; i++) {
		for (int j = 0; j < digit; j++) {
			if (i == j)
				continue;
			if (array[i] == array[j])
				return false;
		}
		return true;
	}
}

// funtions for guessing letter
void Letter_to_num_Array(char array[], int length)
{ // 英文字母轉數字
	for (int i = 0; i < length; i++)
		array[i] = static_cast<int>(array[i]);
}

void randomLetterGenerator(int randomArray[], int digit)
{ // 隨機四個英文字
	resetArray(randomArray, digit);
	int generatedDigit = 0;
	int randomNumber;
	while (generatedDigit < digit) {
		randomNumber = rand() % 26 + 97;
		if (repeatNumberCheck(randomArray, generatedDigit,
				      randomNumber))
			continue;
		randomArray[generatedDigit] = randomNumber;
		generatedDigit += 1;
	}
}

void Letter_check(char guessarray[], int ansarray[], int length, int &A, int &B)
{ // 幾A幾B(英文)
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

int main()
{
	srand(time(0));
	SetConsoleOutputCP(CP_UTF8); //解決輸出亂碼問題
	int digit;
	int mode, player, number_set;
	time_t start, end; // 宣告時間計算
	long addition;

	// 選擇玩法
	while (true) {
		cout << "Please input 1(easy mode:guess number) or 2(hard mode:guess letter): ";
		cin >> mode; // 選擇英文或數字
		if (mode == 1 || mode == 2)
			// 如果選猜英文，則只能單人模式+隨機謎底(數字才能選)
			break;
		if (mode != 1 || mode != 2) {
			cout << "Please try again !" << endl;
			continue;
		}
	}

	// 簡單模式(1):猜數字
	if (mode == 1) {
		while (true) {
			cout << "Please input 1(Single player mode) or 2(competition mode): ";
			cin >> player; // 單人或雙人模式
			if (player == 1 || player == 2)
				break;
			if (player != 1 || player != 2) {
				cout << "Please try again !" << endl;
				continue;
			}
		}
		while (true) {
			cout << "Please input 1(random number set) or 2(user number set): ";
			cin >> number_set; // 隨機或使用者輸入謎底
			if (number_set == 1 || number_set == 2)
				break;
			if (number_set != 1 || number_set != 2) {
				cout << "Please try again !" << endl;
				continue;
			}
		}
	}

	// 困難模式(2):猜英文
	if (mode ==
	    2) { // 猜測英文，原則上相信玩家輸入四個小寫字母且不重複，其他function可以不用放進去。
		int digit = 4;
		int ansArray[digit];
		int suggestArray[digit];
		randomLetterGenerator(ansArray, digit);
		cout << "Answer: ";
		time(&start); // 玩家開始猜測故開始計時
		system("start timer.exe");
		printArray(ansArray, digit);
		char guessArray[digit];
		int counter = 0;
		while (true) {
			cout << endl << "guess ( or input -1 to quit ): ";
			cin >> guessArray;
			Letter_to_num_Array(guessArray, digit);
			int A = 0, B = 0;
			Letter_check(guessArray, ansArray, digit, A, B);
			if ((guessArray[0] == '-' && guessArray[1] == '1') ||
			    A == digit) {
				if (A == digit) {
					cout << "\033[32m猜對了\033[0m";
					counter++;
					time(&end); // 玩家猜對停止計時
					system("taskkill timer.exe");
				}
				break;
			}
			cout << "\033[31m" << A << "\033[0m"
			     << "\033[31mA\033[0m"
			     << "\33[32m" << B << "\033[0m"
			     << "\033[32mB\033[0m" << endl; // 這是換顏色的亂碼
			counter = counter + 1;
			// cout<<endl<<"counter: "<<counter;
		}
		cout << endl
		     << "\033[31m總共猜了\033[0m" << counter
		     << "\033[31m次\033[0m";
	}

	// 一般猜數字模式+單人模式
	if (mode == 1 && player == 1) {
		while (true) {
			digit = 4; // default digit
			cout << endl
			     << "\033[32mHow many digits?(default=4)\033[0m ";
			cin >> digit;
			if (digit > 0 and digit <= 10)
				break;
			cout << "please intput valid digit!(1~10)" << endl
			     << endl;
		}
		int ansArray[digit];
		int suggestArray[digit];
		if (number_set == 1) { // 隨機謎底
			randomNumberGenerator(ansArray, digit);
			cout << "Answer: ";
			time(&start); // 玩家開始猜測故開始計時
			system("start timer.exe");
			printArray(ansArray, digit);
			cout << "\nYou can try: ";
			int m = 0;
			for (m = 0; m < 5; m++) { // 給五組推薦數字
				randomNumberGenerator(suggestArray, digit);
				printArray(suggestArray, digit);
				cout << ' ';
			}
		} else if (number_set == 2) { // 玩家自行輸入謎底
			while (true) {
				cout << "Please input " << digit
				     << " digits(用空格分開): ";
				for (int ans = 0; ans < digit; ans++)
					cin >> ansArray[ans];
				if (input_repeat_NumberCheck(ansArray, digit))
					// 檢查玩家輸入是否正確(謎底)
					break;
				cout << "Wrong Input! You cannot enter repeated numbers!"
				     << endl;
				;
			}
		}
		char guessArray[digit];
		int counter = 0;
		while (true) { // 確認玩家所猜測的數字不重複
			cout << endl << "guess ( or input -1 to quit ): ";
			cin >> guessArray;
			while (true) {
				if (guess_input_repeat_NumberCheck(guessArray,
								   digit))
					break;
				cout << "Wrong Input! You cannot enter repeated numbers!"
				     << endl;
				cout << endl
				     << "guess ( or input -1 to quit ): ";
				cin >> guessArray;
			}
			int A = 0, B = 0;
			check(guessArray, ansArray, digit, A, B); // 幾A幾A
			if ((guessArray[0] == '-' && guessArray[1] == '1') ||
			    A == digit) {
				if (A == digit) {
					cout << "\033[32m猜對了\033[0m";
					counter++;
					time(&end); // 玩家猜對停止計時
					system("taskkill timer.exe");
					cout << endl
					     << endl
					     << "你一共花了"
					     << difftime(end, start)
					     << "秒猜對～" << endl;
				}
				break;
			}
			cout << "\033[31m" << A << "\033[0m"
			     << "\033[31mA\033[0m"
			     << "\033[32m" << B << "\033[0m"
			     << "\033[32mB\033[0m"
			     << endl; // change output color這是換顏色的亂碼
			counter = counter + 1;
			// cout<<endl<<"counter: "<<counter;
			if (counter % 5 == 0) { // 是否需要提供提示
				int hin;
				cout << endl
				     << "Do you need a hint?(Input 1 for yes and 2 for no)";
				cin >> hin;
				if (hin == 1)
					hint(ansArray, digit, hin);
			}
		}
		cout << endl
		     << "\033[31m總共猜了\033[0m" << counter
		     << "\033[31m次\033[0m";
	}

	// 一般猜數字模式+雙人模式
	else if (mode == 1 && player == 2) {
		while (true) {
			digit = 4; // default digit
			cout << endl
			     << "\033[32mHow many digits?(default=4)\033[0m ";
			cin >> digit;
			if (digit > 0 and digit <= 10)
				break;
			cout << "please intput valid digit!(1~10)" << endl
			     << endl;
		}
		int Group1_ansArray[digit], Group2_ansArray[digit];
		char Group1_guessArray[digit], Group2_guessArray[digit];
		int counter = 0, Group1_counter = 0, Group2_counter = 0;

		// 雙人選擇隨機謎底
		if (number_set ==
		    1) { // 如果玩家選擇隨機答案則兩組人馬猜一組數字，比誰先猜到
			int random_ansArray[digit];
			randomNumberGenerator(random_ansArray,
					      digit); // 隨機產生謎底
			cout << "Answer: ";
			printArray(random_ansArray, digit);
			while (true) {
				counter++;
				if (counter % 2 == 1) { // 第一組猜
					cout << endl
					     << "Group1 guess ( or input -1 to quit )(用空格分開): ";
					for (int ans = 0; ans < digit; ans++)
						cin >> Group1_guessArray[ans];
					while (true) { // 確認玩家輸入的數字不重複
						if (guess_input_repeat_NumberCheck(
							    Group1_guessArray,
							    digit))
							break;
						cout << "Wrong Input! You cannot enter repeated numbers!"
						     << endl;
						cout << endl
						     << "Group1 guess ( or input -1 to quit )(用空格分開): ";
						cin >> Group1_guessArray;
					}
					int A = 0, B = 0;
					check_for2players(Group1_guessArray,
							  random_ansArray,
							  digit, A, B);
					if ((Group1_guessArray[0] == '-' &&
					     Group1_guessArray[1] == '1') ||
					    A == digit) {
						if (A == digit)
							cout << "\033[32mGroup1猜對了\033[0m";
						break;
					}
					cout << "\033[31m" << A << "\033[0m"
					     << "\033[31mA\033[0m"
					     << "\033[32m" << B << "\033[0m"
					     << "\033[32mB\033[0m"
					     << endl; // change output color這是換顏色的亂碼
					Group1_counter++;
				} else if (counter % 2 == 0) { // 第二組猜
					cout << endl
					     << "Group2 guess ( or input -1 to quit )(用空格分開): ";
					for (int ans = 0; ans < digit; ans++)
						cin >> Group2_guessArray[ans];
					while (true) { // 確認玩家輸入的數字不重複
						if (guess_input_repeat_NumberCheck(
							    Group2_guessArray,
							    digit))
							break;
						cout << "Wrong Input! You cannot enter repeated numbers!"
						     << endl;
						cout << endl
						     << "Group2 guess ( or input -1 to quit )(用空格分開): ";
						for (int ans = 0; ans < digit;
						     ans++)
							cin >> Group2_guessArray
									[ans];
					}
					int A = 0, B = 0;
					check_for2players(Group2_guessArray,
							  random_ansArray,
							  digit, A, B);
					if ((Group2_guessArray[0] == '-' &&
					     Group2_guessArray[1] == '1') ||
					    A == digit) {
						if (A == digit)
							cout << "\033[32mGroup2猜對了\033[0m";
						break;
					}
					cout << "\033[31m" << A << "\033[0m"
					     << "\033[31mA\033[0m"
					     << "\033[32m" << B << "\033[0m"
					     << "\033[32mB\033[0m"
					     << endl; // change output color這是換顏色的亂碼
					Group2_counter++;
				}
			}
		}

		// 雙人選擇自行謎底
		else if (number_set ==
			 2) { // 若是自行輸入謎底 則兩組互猜對方所出的謎題
			while (true) { // 第一組輸入謎底
				cout << "Group1 please input " << digit
				     << " digits(用空格分開): ";
				for (int ans = 0; ans < digit; ans++)
					cin >> Group1_ansArray[ans];
				if (input_repeat_NumberCheck(Group1_ansArray,
							     digit))
					break;
				cout << endl
				     << "Wrong Input! You cannot enter repeated numbers!"
				     << endl;
				;
			}
			while (true) { // 第二組輸入謎底
				cout << "Group2 please input " << digit
				     << " digits(用空格分開): ";
				for (int ans = 0; ans < digit; ans++)
					cin >> Group2_ansArray[ans];
				if (input_repeat_NumberCheck(Group2_ansArray,
							     digit))
					break;
				cout << endl
				     << "Wrong Input! You cannot enter repeated numbers!"
				     << endl;
				;
			}
			while (true) {
				counter++;
				if (counter % 2 == 1) { // 第一組猜第二組的謎底
					cout << endl
					     << "Group1 guess ( or input -1 to quit ): ";
					for (int ans = 0; ans < digit; ans++)
						cin >> Group1_guessArray[ans];
					while (true) { // 確認玩家輸入的數字不重複
						if (guess_input_repeat_NumberCheck(
							    Group1_guessArray,
							    digit))
							break;
						cout << "Wrong Input! You cannot enter repeated numbers!"
						     << endl;
						cout << endl
						     << "Group1 guess ( or input -1 to quit ): ";
						cin >> Group1_guessArray;
					}
					int A = 0, B = 0; // 幾A幾B
					check_for2players(Group1_guessArray,
							  Group2_ansArray,
							  digit, A, B);
					if ((Group1_guessArray[0] == '-' &&
					     Group1_guessArray[1] == '1') ||
					    A == digit) {
						if (A == digit)
							cout << "\033[32mGroup1猜對了\033[0m";
						break;
					}
					cout << "\033[31m" << A << "\033[0m"
					     << "\033[31mA\033[0m"
					     << "\033[32m" << B << "\033[0m"
					     << "\033[32mB\033[0m"
					     << endl; // change output color這是換顏色的亂碼
					Group1_counter++;
				} else if (counter % 2 ==
					   0) { // 第二組猜第一組的謎底
					cout << endl
					     << "Group2 guess ( or input -1 to quit ): ";
					for (int ans = 0; ans < digit; ans++)
						cin >> Group2_guessArray[ans];
					while (true) { // 確認玩家輸入的數字不重複
						if (guess_input_repeat_NumberCheck(
							    Group2_guessArray,
							    digit))
							break;
						cout << endl
						     << "Wrong Input! You cannot enter repeated numbers!"
						     << endl;
						cout << endl
						     << "Group2 guess ( or input -1 to quit ): ";
						cin >> Group2_guessArray;
					}
					int A = 0, B = 0; // 幾A幾B
					check_for2players(Group2_guessArray,
							  Group1_ansArray,
							  digit, A, B);
					if ((Group2_guessArray[0] == '-' &&
					     Group2_guessArray[1] == '1') ||
					    A == digit) {
						if (A == digit)
							cout << "\033[32mGroup2猜對了\033[0m";
						break;
					}
					cout << "\033[31m" << A << "\033[0m"
					     << "\033[31mA\033[0m"
					     << "\033[32m" << B << "\033[0m"
					     << "\033[32mB\033[0m"
					     << endl; // change output color這是換顏色的亂碼
					Group2_counter++;
					;
				}
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}

/*
final project colab https://reurl.cc/mZMlVA
final project sheet https://reurl.cc/bGYzno
*/
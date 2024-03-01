#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << fixed << setprecision(2);

	int accountCount; //set up accounts
	cout << "How many account: ";
	cin >> accountCount;
	Account **account = new Account *[accountCount];
	for (int i = 0; i < accountCount; i++) {
		int accountType;
		double argument1, argument2;
		cout << "==========================" << endl;
		cout << "Account " << i + 1 << ":" << endl;
		cout << "Which kind of account?" << endl;
		cout << "1.Savings account" << endl;
		cout << "2.Checking account" << endl << endl;
		cout << "Type: ";
		cin >> accountType;
		if (accountType == 1) {
			cout << "Initial balance: ";
			cin >> argument1;
			cout << "Initial interest rate: ";
			cin >> argument2;
			account[i] = new SavingsAccount(argument1, argument2);
		} else if (accountType == 2) {
			cout << "Initial balance: ";
			cin >> argument1;
			cout << "Initial fee: ";
			cin >> argument2;
			account[i] = new CheckingAccount(argument1, argument2);
		} else {
			cout << "Invalid number!" << endl << endl;
			i--;
			continue;
		}
	} //set up accounts
	cout << "Accounts setting completed!" << endl << endl;

	while (1) { //choosing account
		cout << "==========================" << endl;
		cout << "Choose an account or exit." << endl;
		for (int i = 0; i < accountCount; i++)
			cout << i + 1 << "." << account[i]->getType() << endl;
		cout << accountCount + 1 << ".Exit" << endl << endl;
		cout << "Account: ";
		int chooseAccount;
		cin >> chooseAccount;
		if (chooseAccount > accountCount + 1 || chooseAccount < 1) {
			cout << "Invalid choosing number!" << endl << endl;
			continue;
		} else if (chooseAccount == accountCount + 1) {
			cout << "Thanks for using!" << endl;
			break;
		}
		while (1) { //account option
			cout << "==========================" << endl;
			account[chooseAccount - 1]->printOption();
			cout << "Option: ";
			int option;
			cin >> option;
			if (account[chooseAccount - 1]->choose(option))
				continue;
			else
				break;
		} //account option
	} //choosing account

	for (int i = 0; i < accountCount; i++) //delete accounts
		delete account[i];
	return 0;
}

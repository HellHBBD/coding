#include "CheckingAccount.hpp"
using namespace std;

CheckingAccount::CheckingAccount(double initBalance, double initFee)
	: Account::Account(initBalance) {
	setFee(0);
	setFee(initFee);
}

void CheckingAccount::setFee(double fee) {
	if (fee >= 0)
		this->fee = fee;
}

double CheckingAccount::getFee() const {
	return fee;
}

bool CheckingAccount::credit(double add) {
	Account::debit(fee);
	return Account::credit(add);
}

bool CheckingAccount::debit(double minus) {
	if (Account::debit(minus)) {
		Account::debit(fee);
		return true;
	}
	return false;
}

string CheckingAccount::getType() const {
	return "Checking Account";
}

void CheckingAccount::printOption() const {
	cout << "Account type: " << getType() << endl;
	cout << "Balance remain: " << getBalance() << endl;
	cout << "Fee: " << getFee() << endl
		 << endl;
	cout << "Choose an option or exit." << endl;
	cout << "1.Credit" << endl;
	cout << "2.Debit" << endl;
	cout << "3.Set fee" << endl;
	cout << "4.Exit" << endl
		 << endl;
}

bool CheckingAccount::choose(int option) { //continue -> true, exit -> false
	if (option == 1) {
		double amount;
		cout << "Credit: ";
		cin >> amount;
		credit(amount);
		return true;
	} else if (option == 2) {
		double amount;
		cout << "Debit: ";
		cin >> amount;
		debit(amount);
		return true;
	} else if (option == 3) {
		double amount;
		cout << "Set fee: ";
		cin >> amount;
		setFee(amount);
		return true;
	} else if (option == 4) {
		return false;
	} else {
		cout << "Invalid option!" << endl;
		return true;
	}
}

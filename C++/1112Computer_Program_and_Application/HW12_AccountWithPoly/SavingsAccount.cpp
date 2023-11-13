#include "SavingsAccount.hpp"
using namespace std;

SavingsAccount::SavingsAccount(double initBalance, double initInterestRate)
	: Account::Account(initBalance) {
	setInterestRate(0);
	setInterestRate(initInterestRate);
}

bool SavingsAccount::setInterestRate(double interest) {
	if (interest >= 0) {
		interestRate = interest;
		return true;
	} else {
		cout << "Invalid interest rate!" << endl;
		return false;
	}
}

double SavingsAccount::getInterestRate() const {
	return interestRate;
}

double SavingsAccount::calculateInterest() {
	double interest = getBalance() * getInterestRate() * 0.01;
	credit(interest);
	return interest;
}

string SavingsAccount::getType() const {
	return "Savings Account";
}

void SavingsAccount::printOption() const {
	cout << "Account type: " << getType() << endl;
	cout << "Balance remain: " << getBalance() << endl;
	cout << "Interest rate: " << getInterestRate() << endl
		 << endl;
	cout << "Choose an option or exit." << endl;
	cout << "1.Credit" << endl;
	cout << "2.Debit" << endl;
	cout << "3.Set interest rate" << endl;
	cout << "4.Calculate interest" << endl;
	cout << "5.Exit" << endl
		 << endl;
}

bool SavingsAccount::choose(int option) { //continue -> true, exit -> false
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
		cout << "Set interest rate: ";
		cin >> amount;
		setInterestRate(amount);
		return true;
	} else if (option == 4) {
		calculateInterest();
		return true;
	} else if (option == 5) {
		return false;
	} else {
		cout << "Invalid option!" << endl;
		return true;
	}
}

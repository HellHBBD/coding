#include "Account.hpp"
using namespace std;

Account::Account(double initBalance)
{
	if (!setBalance(initBalance))
		cout << "invalid initial balance!" << endl;
}

Account::~Account()
{
}

double Account::getBalance() const
{
	return balance;
}

bool Account::credit(double add)
{
	if (add <= 0) {
		cout << "invalid credit!" << endl;
		return false;
	} else {
		setBalance(getBalance() + add);
		return true;
	}
}

bool Account::debit(double minus)
{
	if (minus <= 0) {
		cout << "invalid debit!" << endl;
		return false;
	} else if (!setBalance(getBalance() - minus)) {
		cout << "Debit Amount exceeded account balance." << endl;
		return false;
	} else
		return true;
}

bool Account::setBalance(double balance)
{
	if (balance < 0)
		return false;
	else {
		this->balance = balance;
		return true;
	}
}

double Account::calculateInterest()
{
}

string Account::getType() const
{
	return "Account";
}

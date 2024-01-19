#include <iomanip>
#include <iostream>
using namespace std;

class Account
{
		public:
		virtual Account(double = 0);
		double getBalance() const;
		virtual bool credit(double);
		virtual bool debit(double);

		private:
		double balance;
		bool setBalance(double);
};

class SavingsAccount: public Account
{
		public:
		SavingsAccount(double = 0, double = 0);
		bool setInterestRate(double);
		double getInterestRate() const;
		double calculateInterest() const;

		private:
		double interestRate;
};

class CheckingAccount: public Account
{
		public:
		CheckingAccount(double = 0, double = 0);
		void setFee(double);
		double getFee() const;
		bool credit(double) override;
		bool debit(double) override;

		private:
		double fee;
};

int main()
{
		cout << fixed << setprecision(2);

		Account account1(50.0);
		cout << "account1 balance: $" << account1.getBalance() << endl;
		cout << "Attempting to debit $25.00 from account1." << endl;
		account1.debit(25.0);
		cout << "account1 balance: $" << account1.getBalance() << endl;
		cout << "Crediting $40.00 to account1." << endl;
		account1.credit(40.0);
		cout << "account1 balance: $" << account1.getBalance() << endl;

		cout << endl;

		SavingsAccount account2(25.0, 0.03);
		cout << "account2 balance: $" << account2.getBalance() << endl;
		cout << "Attempting to debit $30.00 from account2." << endl;
		account2.debit(30.0);
		cout << "account2 balance: $" << account2.getBalance() << endl;
		cout << "Crediting $65.00 to account2." << endl;
		account2.credit(65.0);
		cout << "account2 balance: $" << account2.getBalance() << endl;
		cout << "Adding $" << account2.calculateInterest() << " interest to account2." << endl;
		account2.credit(account2.calculateInterest());
		cout << "New account2 balance: $" << account2.getBalance() << endl;

		cout << endl;

		CheckingAccount account3(80.0, 1.0);

		cout << "account3 balance: $" << account3.getBalance() << endl;
		cout << "Attempting to debit $40.00 from account3." << endl;
		account3.debit(40.0);
		cout << "account3 balance: $" << account3.getBalance() << endl;
		cout << "Crediting $20.00 to account3." << endl;
		account3.credit(20.0);
		cout << "account3 balance: $" << account3.getBalance() << endl;
		return 0;
}

Account::Account(double initBalance)
{
		if (initBalance > 0)
				setBalance(initBalance);
		else
				cout << "invalid initial balance!" << endl;
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
		}
		return setBalance(getBalance() + add);
}

bool Account::debit(double minus)
{
		if (minus <= 0) {
				cout << "invalid debit!" << endl;
				return false;
		}
		if (!setBalance(getBalance() - minus)) {
				cout << "Debit Amount exceeded account balance." << endl;
				return false;
		}
		return true;
}

bool Account::setBalance(double balance)
{
		if (balance < 0)
				return false;
		this->balance = balance;
		return true;
}

SavingsAccount::SavingsAccount(double initBalance, double initInterestRate)
	: Account::Account(initBalance)
{
		setInterestRate(0);
		setInterestRate(initInterestRate);
}

bool SavingsAccount::setInterestRate(double interest)
{
		if (interest >= 0) {
				interestRate = interest;
				return true;
		}
		cout << "invalid interest rate!" << endl;
		return false;
}

double SavingsAccount::getInterestRate() const
{
		return interestRate;
}

double SavingsAccount::calculateInterest() const
{
		return getBalance() * getInterestRate() * 0.01;
}

CheckingAccount::CheckingAccount(double initBalance, double initFee)
	: Account::Account(initBalance)
{
		setFee(0);
		setFee(initFee);
}

void CheckingAccount::setFee(double fee)
{
		if (fee >= 0)
				this->fee = fee;
}

double CheckingAccount::getFee() const
{
		return fee;
}

bool CheckingAccount::credit(double add)
{
		Account::debit(fee);
		return Account::credit(add);
}

bool CheckingAccount::debit(double minus)
{
		if (Account::debit(minus)) {
				Account::debit(fee);
				return true;
		}
		return false;
}

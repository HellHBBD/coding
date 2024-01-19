#include <iostream>
using namespace std;

class Account
{
		public:
		Account(int);	  //init
		void credit(int); //add
		void debit(int);  //minus
		int getBalance(); //get
		private:
		int accountBalance;
};

int main()
{
		Account John(100), Jane(50);
		John.credit(30);
		John.debit(-15);
		cout << "your current account balance is " << John.getBalance() << endl;

		Jane.credit(-78);
		Jane.debit(60);
		cout << "your current account balance is " << Jane.getBalance() << endl;
		return 0;
}

Account::Account(int balance)
{
		if (balance >= 0)
				accountBalance = balance;
		else {
				cout << "invalid balance!" << endl;
				accountBalance = 0;
		}
}

void Account::credit(int balance)
{
		if (balance >= 0)
				accountBalance += balance;
		else
				cout << "invalid balance!" << endl;
}

void Account::debit(int balance)
{
		if (balance < 0)
				cout << "invalid balance!" << endl;
		else if (balance > accountBalance)
				cout << "Debit exceeded account balance." << endl;
		else
				accountBalance -= balance;
}

int Account::getBalance()
{
		return accountBalance;
}

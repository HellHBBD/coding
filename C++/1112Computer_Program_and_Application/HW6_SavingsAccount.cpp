#include <iostream>
using namespace std;

class SavingsAccount {
    public:
	SavingsAccount(double = 0.0);
	void setBalance(double = 0.0);
	double getBalance();
	double calculateMonthlyInterest();
	static double modifyInterestRate(int = 0);

    private:
	static double annualInterestRate;
	double savingsBalance;
};

double SavingsAccount::annualInterestRate = 0.0;

int main()
{
	SavingsAccount saver1(2000), saver2(3000);
	cout << "set interest rate to " << SavingsAccount::modifyInterestRate(3) << "%" << endl;
	cout << "saver1 monthly interest: " << saver1.calculateMonthlyInterest() << endl;
	cout << "saver1 new balance: " << saver1.getBalance() << endl;
	cout << "saver2 monthly interest: " << saver2.calculateMonthlyInterest() << endl;
	cout << "saver2 new balance: " << saver2.getBalance() << endl;
	cout << endl;
	cout << "set interest rate to " << SavingsAccount::modifyInterestRate(4) << "%" << endl;
	cout << "saver1 monthly interest: " << saver1.calculateMonthlyInterest() << endl;
	cout << "saver1 new balance: " << saver1.getBalance() << endl;
	cout << "saver2 monthly interest: " << saver2.calculateMonthlyInterest() << endl;
	cout << "saver2 new balance: " << saver2.getBalance() << endl;
	return 0;
}

SavingsAccount::SavingsAccount(double balance)
{
	setBalance(balance);
}

void SavingsAccount::setBalance(double balance)
{
	if (balance >= 0)
		savingsBalance = balance;
	else
		savingsBalance = 0.0;
}

double SavingsAccount::getBalance()
{
	return savingsBalance;
}

double SavingsAccount::calculateMonthlyInterest()
{
	double interest = savingsBalance * annualInterestRate;
	savingsBalance += interest;
	return interest / 12;
}

double SavingsAccount::modifyInterestRate(int percent)
{
	annualInterestRate = percent * 0.01;
	return percent;
}

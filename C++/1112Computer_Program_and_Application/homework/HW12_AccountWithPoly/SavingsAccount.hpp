#ifndef SAVINGSACCOUNT_HPP
#define SAVINGSACCOUNT_HPP

#include <iostream>
using namespace std;

#include "Account.hpp"

class SavingsAccount : public Account {
    public:
	SavingsAccount(double = 0, double = 0);
	bool setInterestRate(double);
	double getInterestRate() const;
	double calculateInterest();
	string getType() const override;
	void printOption() const override;
	bool choose(int) override;

    private:
	double interestRate;
};

#endif

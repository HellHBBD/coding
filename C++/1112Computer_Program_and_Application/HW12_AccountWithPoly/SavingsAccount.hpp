#ifndef SAVINGSACCOUNT_HPP
#define SAVINGSACCOUNT_HPP

#include "Account.hpp"
#include <iostream>

class SavingsAccount : public Account {
    public:
	SavingsAccount(double = 0, double = 0);
	bool setInterestRate(double);
	double getInterestRate() const;
	double calculateInterest();
	std::string getType() const;
	void printOption() const override;
	bool choose(int) override;

    private:
	double interestRate;
};

#endif

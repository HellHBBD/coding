#ifndef CHECKINGACCOUNT_HPP
#define CHECKINGACCOUNT_HPP

#include <iostream>
using namespace std;

#include "Account.hpp"

class CheckingAccount : public Account {
    public:
	CheckingAccount(double = 0, double = 0);
	void setFee(double);
	double getFee() const;
	bool credit(double) override;
	bool debit(double) override;
	string getType() const override;
	void printOption() const override;
	bool choose(int) override;

    private:
	double fee;
};

#endif

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
using namespace std;

class Account {
    public:
	Account(double = 0);
	virtual ~Account();
	double getBalance() const;
	virtual bool credit(double);
	virtual bool debit(double);
	virtual string getType() const;
	virtual void printOption() const = 0;
	virtual bool choose(int) = 0;

    private:
	double balance;
	bool setBalance(double);
};

#endif

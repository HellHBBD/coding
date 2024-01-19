#ifndef CHECKINGACCOUNT_HPP
#define CHECKINGACCOUNT_HPP

#include "Account.hpp"
#include <iostream>

class CheckingAccount: public Account
{
		public:
		CheckingAccount(double = 0, double = 0);
		void setFee(double);
		double getFee() const;
		bool credit(double) override;
		bool debit(double) override;
		std::string getType() const;
		void printOption() const;
		bool choose(int);

		private:
		double fee;
};

#endif

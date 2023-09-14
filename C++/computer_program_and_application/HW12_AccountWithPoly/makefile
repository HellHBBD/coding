final.out : main.o Account.o SavingsAccount.o CheckingAccount.o
	g++ -o final.out -g main.o Account.o SavingsAccount.o CheckingAccount.o

main.o : main.cpp Account.hpp SavingsAccount.hpp CheckingAccount.hpp
	g++ -c main.cpp

Account.o : Account.cpp Account.hpp
	g++ -c Account.cpp

SavingsAccount.o : SavingsAccount.cpp SavingsAccount.hpp Account.hpp
	g++ -c SavingsAccount.cpp

CheckingAccount.o : CheckingAccount.cpp CheckingAccount.hpp Account.hpp
	g++ -c CheckingAccount.cpp

clean :
	del final.out *.o

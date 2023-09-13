final : Date.o main.o
	g++ -o final main.o Date.o

Date.o : Date.cpp Date.hpp
	g++ -c Date.cpp

main.o : main.cpp Date.hpp
	g++ -c main.cpp

clean :
	rm final.exe *.o

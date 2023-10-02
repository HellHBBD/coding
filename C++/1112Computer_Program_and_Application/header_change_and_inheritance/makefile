final : main.o base.o derive.o header.o
	g++ -o final main.o base.o derive.o header.o

main.o : main.cpp derive.hpp
	g++ -c main.cpp

base.o : base.cpp base.hpp header.hpp
	g++ -c base.cpp

derive.o : derive.cpp derive.hpp
	g++ -c derive.cpp

header.o : header.cpp header.hpp
	g++ -c header.cpp

clean :
	del *.o final.exe

final:Time.o main.o
	g++ -o final main.o Time.o

Time.o:Time.cpp Time.hpp
	g++ -c Time.cpp

main.o:main.cpp Time.hpp
	g++ -c main.cpp

clean:
	rm final.exe *.o

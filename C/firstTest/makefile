final.exe : header.o main.o
	gcc -o final header.o main.o

header.o : header.h header.c
	gcc -c header.c

main.o : header.h main.c
	gcc -c main.c

clean :
	del *.o final.exe

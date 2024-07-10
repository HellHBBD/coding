CC = g++
OPT = -O0
DEPFLAG = -MP -MD
CFLAG = -Wall -Wextra -g $(OPT) $(DEPFLAG)

BIN = date employee final
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
DEP = $(patsubst %.cpp, %.d, $(SRC))

all: $(BIN)

date: fig11_11.o Date.o
	$(CC) $(CFLAG) -o $@ $^

employee: fig13_23.o Date.o Employee.o SalariedEmployee.o HourlyEmployee.o CommissionEmployee.o BasePlusCommissionEmployee.o
	$(CC) $(CFLAG) -o $@ $^

final : main.o Date.o Employee.o SalariedEmployee.o HourlyEmployee.o CommissionEmployee.o BasePlusCommissionEmployee.o
	$(CC) $(CFLAG) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAG) -c -o $@ $<

clean:
	rm -f $(OBJ) $(BIN) $(DEP)

remake: clean all

-include $(DEP)

.PHONY: all clean remake

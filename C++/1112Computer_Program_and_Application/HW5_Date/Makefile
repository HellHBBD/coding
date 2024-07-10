CC = g++
OPT = -O0
DEPFLAG = -MP -MD
CFLAG = -Wall -Wextra -g $(OPT) $(DEPFLAG)

BIN = final
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
DEP = $(patsubst %.cpp, %.d, $(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAG) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAG) -c -o $@ $<

clean:
	rm -f $(OBJ) $(BIN) $(DEP)

remake: clean all

-include $(DEP)

.PHONY: all clean remake

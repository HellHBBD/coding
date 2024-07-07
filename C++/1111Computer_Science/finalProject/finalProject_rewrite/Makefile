EXE = bulls-and-cows
ROOT = .
LIB_DIRS = $(ROOT) lib
INC_DIRS = $(ROOT) include

CC = gcc
OPT = -O2
DEPFLAGS = -MP -MMD
CFLAGS = -Wall -Wextra -g $(foreach dir, $(INC_DIRS), -I$(dir)) $(OPT) $(DEPFLAGS)

CFILES = $(foreach dir, $(LIB_DIRS), $(wildcard $(dir)/*.c))
OBJECTS = $(patsubst %.c, %.o, $(CFILES))
DEPFILES = $(patsubst %.c, %.d, $(CFILES))

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(EXE) $(OBJECTS) $(DEPFILES)

remake: clean all

test:
	echo $(OBJECTS)
	echo $(DEPFILES)

.PHONY: all clean remake test

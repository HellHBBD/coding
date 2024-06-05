SHELL := /bin/bash
JAVAFILES=$(wildcard *.java)
CLASSFILES=$(JAVAFILES:.java=.class)
DOCS=assets/corpus0.txt
DATA=corpus0
TC=assets/tc4.txt

all: $(CLASSFILES)

%.class: %.java
	javac $<

clean:
	rm -f *.class

build: all
	java -Xmx2g BuildIndex $(DOCS)

search: all
	java -Xmx2g TFIDFSearch $(DATA) $(TC)

test: all
	time make search
	nvim -d output.txt assets/ans4.txt

.PHONY: all clean build search test

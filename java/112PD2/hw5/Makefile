JAVAFILES=$(wildcard *.java)
CLASSFILES=$(JAVAFILES:.java=.class)
DOCS=assets/corpus0.txt
DATA=corpus0
TC=assets/tc0.txt

all: $(CLASSFILES)

%.class: %.java
	javac $<

clean:
	rm -f $(CLASSFILES)

build: all
	java -Xmx2g BuildIndex $(DOCS)

search: all
	java -Xmx2g TFIDFSearch $(DATA) $(TC)

.PHONY: all clean build search

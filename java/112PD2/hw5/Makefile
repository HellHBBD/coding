JAVAFILES=$(wildcard *.java)
CLASSFILES=$(JAVAFILES:.java=.class)
DOCS=assets/corpus0.txt
# DATA=
# TC=

all: $(CLASSFILES)

%.class: %.java
	javac $<

clean:
	rm -f $(CLASSFILES)

run: all
	java -Xmx2g BuildIndex $(DOCS)
	# java TFIDFSearch

.PHONY: all clean

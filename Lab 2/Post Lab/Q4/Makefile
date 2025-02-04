all: main

main: Main.o LetterCount.o WordCount.o LineCount.o
	g++ -o main Main.o LetterCount.o WordCount.o LineCount.o

Main.o: Main.cpp
	g++ -c Main.cpp

LetterCount.o: LetterCount.cpp LetterCount.h
	g++ -c LetterCount.cpp

WordCount.o: WordCount.cpp WordCount.h
	g++ -c WordCount.cpp

LineCount.o: LineCount.cpp LineCount.h
	g++ -c LineCount.cpp

clean:
	rm -f *.o main

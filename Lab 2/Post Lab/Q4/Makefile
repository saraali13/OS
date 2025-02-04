all: main

main: main.o LetterCount.o WordCount.o LineCount.o
	g++ -o main main.o LetterCount.o WordCount.o LineCount.o

main.o: main.cpp LetterCount.h WordCount.h LineCount.h
	g++ -c main.cpp

LetterCount.o: LetterCount.cpp LetterCount.h
	g++ -c LetterCount.cpp

WordCount.o: WordCount.cpp WordCount.h
	g++ -c WordCount.cpp

LineCount.o: LineCount.cpp LineCount.h
	g++ -c LineCount.cpp

clean:
	rm -f *.o main

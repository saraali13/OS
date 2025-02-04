#include <iostream>
#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"

using namespace std;

int main() {
    string filename = "f4.txt"; 

    LetterCount letterCounter;
    WordCount wordCounter;
    LineCount lineCounter;

    int letters = letterCounter.countLetters(filename);
    int words = wordCounter.countWords(filename);
    int lines = lineCounter.countLines(filename);

    if (letters == -1 || words == -1 || lines == -1) {
        cout << "Error: Could not open file.\n";
        return 1;
    }

    cout << "Letter Count: " << letters << endl;
    cout << "Word Count: " << words << endl;
    cout << "Line Count: " << lines << endl;

    return 0;
}

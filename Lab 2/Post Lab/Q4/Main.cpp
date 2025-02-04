#include <iostream>
#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"
using namespace std;

int main()
{
    string filename = "text.txt";

    cout << "Letters: " << LetterCount::countLetters(filename) << endl;
    cout << "Words: " << WordCount::countWords(filename) << endl;
    cout << "Lines: " << LineCount::countLines(filename) << endl;

    return 0;
}

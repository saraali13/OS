#include "WordCount.h"
#include <fstream>
#include <sstream>
using namespace std;

int WordCount::countWords(const string &filename)
{
    ifstream file(filename);
    if (!file)
        return -1;

    string word;
    int count = 0;
    while (file >> word)
    {
        count++;
    }

    return count;
}

#ifndef LETTERCOUNT_H
#define LETTERCOUNT_H

#include <fstream>
#include <cctype>
using namespace std;

class LetterCount
{
public:
    int countLetters(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            return -1;
        }

        char ch;
        int count = 0;
        while (file.get(ch))
        {
            if (isalpha(ch))
            {
                count++;
            }
            return count;
        }
    }
};

#endif

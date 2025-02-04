#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <fstream>
#include <string>
using namespace std;

class WordCount
{
public:
    int countWords(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            return -1;
        }

        string word;
        int count = 0;
        while (file >> word)
        {
            count++;
        }
        return count;
    }
};

#endif

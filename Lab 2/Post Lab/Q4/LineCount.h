#ifndef LINECOUNT_H
#define LINECOUNT_H

#include <fstream>
#include <string>
using namespace std;

class LineCount
{
public:
    static int countLines(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            return -1;
        }

        string line;
        int count = 0;
        while (getline(file, line))
        {
            count++;
        }
        return count;
    }
};

#endif

#include "LineCount.h"
#include <fstream>
using namespace std;

int LineCount::countLines(const string &filename)
{
    ifstream file(filename);
    if (!file)
        return -1;

    int count = 0;
    string line;
    while (getline(file, line))
    {
        count++;
    }

    return count;
}

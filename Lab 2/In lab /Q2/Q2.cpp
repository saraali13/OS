#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    ifstream file(argv[1]);

    if (!file)
    {
        cout << "Error: File not found.\n";
        return 1;
    }

    char ch;
    while (file.get(ch))
    {
        cout << ch; // Print file contents character by character
    }

    return 0;
}

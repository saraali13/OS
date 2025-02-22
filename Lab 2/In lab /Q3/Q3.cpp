#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <list of integers>\n";
        return 1;
    }

    int arr[argc - 1];
    for (int i = 0; i < argc - 1; i++)
    {
        arr[i] = atoi(argv[i+1]);
    }

    sort(arr, arr + (argc - 1));

    for (int i = 0; i < argc - 1; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << endl;

    return 0;
}

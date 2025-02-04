#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;

int findMissing(int arr[], int n)
{
    int total = ((n+1) * (n+2)) / 2;    // total sum of first n numbers

    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        sum += arr[i];

    return (total - sum); // Return missing number
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " <series of numbers>\n";
        return 1;
    }

    int n = argc - 1;
    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = atoi(argv[i + 1]);

    int missing = findMissing(arr, n);

    ofstream file("missing.txt");
    file << "Missing Element: " << missing;
    file.close();

    cout << "Missing Element written to missing.txt\n";
    return 0;
} 

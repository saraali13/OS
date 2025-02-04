#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;

int findMissing(int arr[], int n)
{
    int max = *max_element(arr, arr + n); // Find max number in the list
    int min = *min_element(arr, arr + n); // Find min number in the list

    // Correct formula for expected sum of numbers from min to max
    int total = (max * (max + 1)) / 2 - (min * (min - 1)) / 2;

    int sum = 0;
    for (int i = 0; i < n; i++) // Sum the given numbers
        sum += arr[i];

    return total - sum; // Return the missing number
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

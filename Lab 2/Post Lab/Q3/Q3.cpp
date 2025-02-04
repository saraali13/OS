#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
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
    ifstream file("f3.txt");
    if (!file)
    {
        cout << "Error: file not found\n";
    }

    int num;
    vector<int> arr;

    while (file >> num)
    {
        arr.push_back(num);
    }
    file.close();
    int n = arr.size();
    if (n == 0)
    {
        cout << "Error: No numbers found in file.\n";
        return 1;
    }
    int missing = findMissing(arr.data(), n);

    ofstream outFile("missing2.txt");
    outFile << "Missing Element: " << missing;
    outFile.close();
    cout << "Missing Element written to missing2.txt\n";
    return 0;
}

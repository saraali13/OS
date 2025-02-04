#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int findMissing(int arr[], int n)
{
    int max_num = *max_element(arr, arr + n);  // Find max number in array
    int total = (max_num * (max_num + 1)) / 2; // Correct sum formula

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return total - sum; // Return missing number
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

    ofstream outFile("missing.txt");
    outFile << "Missing Element: " << missing;
    outFile.close();
    cout << "Missing Element written to missing.txt\n";
    return 0;
}

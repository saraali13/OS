#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <integers\n>";
        return 1;
    }
    
    int sum = 0;
    for (int i = 0; i < argc - 1; i++)
    {
        sum += atoi(argv[i + 1]);
    }

    float avg = (float)sum / (argc - 1);
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;
    return 0;
}

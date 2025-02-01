#include <iostream>
#include <cstdlib> // For atoi()
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <integers>\n";
        return 1;
    }

    int sum = 0;
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }

    double avg = (double)sum / (argc - 1);
    cout << "Sum: " << sum << "\nAverage: " << avg << endl;

    return 0;
}

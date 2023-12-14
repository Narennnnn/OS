#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

const int MARKED_REQUEST = numeric_limits<int>::max();

int main() {
    vector<int> RQ;
    int n, TotalHeadMovement = 0, initial, count = 0;

    cout << "Enter the number of Requests\n";
    cin >> n;

    if (n <= 0) {
        cerr << "Invalid number of requests. Exiting.\n";
        return 1;  // Exit with an error code
    }

    cout << "Enter the Requests sequence\n";
    RQ.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> RQ[i];

    cout << "Enter initial head position\n";
    cin >> initial;

    // Logic for SSTF disk scheduling
    while (count != n) {
        int min = numeric_limits<int>::max(), d, index;

        for (int i = 0; i < n; ++i) {
            if (RQ[i] == MARKED_REQUEST)
                continue;  // Skip marked requests

            d = abs(RQ[i] - initial);

            if (min > d) {
                min = d;
                index = i;
            }
        }

        TotalHeadMovement += min;
        initial = RQ[index];
        RQ[index] = MARKED_REQUEST;
        ++count;
    }

    cout << "Total head movement is " << TotalHeadMovement << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int MAX_PAGES = 100;

int findPageFaults(vector<int>& pages, int capacity) {
    vector<int> cache(capacity, -1);
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        int page = pages[i];
        auto it = find(cache.begin(), cache.end(), page);

        if (it == cache.end()) {
            auto lruIt = min_element(cache.begin(), cache.end(),
                [i](int a, int b) { return a == -1 || b == -1 || a == b; });

            *lruIt = page;
            ++pageFaults;
        }
    }

    return pageFaults;
}

int main() {
    int n, capacity;

    cout << "Enter the number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter the page references: ";
    for (int i = 0; i < n; ++i)
        cin >> pages[i];

    cout << "Enter the capacity of the cache: ";
    cin >> capacity;

    cout << "Total Page Faults: " << findPageFaults(pages, capacity) << endl;

    return 0;
}

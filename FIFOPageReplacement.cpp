#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_PAGES = 100;

int findPageFaults(vector<int>& pages, int capacity) {
    queue<int> cache;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        int page = pages[i];

        if (cache.size() < capacity) {
            cache.push(page);
            ++pageFaults;
        } else {
            if (find(cache.front(), cache.back(), page) == cache.end()) {
                cache.pop();
                cache.push(page);
                ++pageFaults;
            }
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

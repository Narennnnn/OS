#include <stdio.h>
#include <stdbool.h>

#define MAX_PAGES 100

int findPageFaults(int pages[], int numPages, int cacheCapacity) {
    int cache[cacheCapacity];
    int pageFaults = 0;

    for (int i = 0; i < cacheCapacity; ++i)
        cache[i] = -1;

    for (int i = 0; i < numPages; ++i) {
        int page = pages[i];
        bool pageFound = false;

        for (int j = 0; j < cacheCapacity && !(pageFound = cache[j] == page); ++j);

        if (!pageFound) {
            int leastRecentlyUsedIndex = 0;

            for (int j = 1; j < cacheCapacity; ++j) {
                if (cache[j] == -1 || cache[j] == cache[leastRecentlyUsedIndex]) {
                    leastRecentlyUsedIndex = j;
                }
            }

            cache[leastRecentlyUsedIndex] = page;
            ++pageFaults;
        }
    }

    return pageFaults;
}

int main() {
    int numPages, cacheCapacity;

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    int pages[MAX_PAGES];
    
    printf("Enter the page references: ");
    for (int i = 0; i < numPages; ++i)
        scanf("%d", &pages[i]);

    printf("Enter the capacity of the cache: ");
    scanf("%d", &cacheCapacity);

    printf("Total Page Faults: %d\n", findPageFaults(pages, numPages, cacheCapacity));

    return 0;
}

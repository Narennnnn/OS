#include <stdio.h>
#include <stdlib.h>

int find(int frameCount, int *frames, int toFind) {
    int index = -1;
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == toFind) {
            index = i;
            break;
        }
    }
    return index;
}

int traverse(int no_of_pages, int *pageArray, int currentIndex, int toFind) {
    int index = -1;
    for (int j = currentIndex - 1; j >= 0; j--) {
        if (pageArray[j] == toFind) {
            index = j;
            break;
        }
    }
    return index;
}

int findMRU(int *pageArray, int currentIndex, int no_of_pages, int frameCount, int *frames) {
    int *flag = (int *)calloc(frameCount, sizeof(int));
    int index = -1;
    int idx = -1;
    int max = -1; // Just some high value later to be replaced

    for (int j = 0; j < frameCount; j++) {
        flag[j] = 0;
    }

    for (int j = 0; j < frameCount; j++) {
        idx = traverse(no_of_pages, pageArray, currentIndex, frames[j]);
        if (idx != -1) {
            if (idx > max) {
                max = idx;
                index = j;
            }
            flag[j] = 1;
        }
    }

    free(flag);
    return index;
}

int main() {
    int frameCount, no_of_pages;

    printf("Enter the number of frames:\n");
    scanf("%d", &frameCount);

    printf("Enter the number of pages:\n");
    scanf("%d", &no_of_pages);

    if (frameCount <= 0 || no_of_pages <= 0) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    printf("Enter the page array:\n");
    int *pageArray = (int *)calloc(no_of_pages, sizeof(int));
    for (int i = 0; i < no_of_pages; i++) {
        scanf("%d", &pageArray[i]);
    }

    int *frames = (int *)calloc(frameCount, sizeof(int));
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    int index = 0;
    int pageFaults = 0;
    int pageHits = 0;
    int idx;
    int count = 0;

    for (int i = 0; i < no_of_pages; i++) {
        if (count < frameCount) {
            idx = find(frameCount, frames, pageArray[i]);
            if (idx != -1) {
                pageHits++;
                printf("Page Hit: Successfully found Page %d at Frame %d\n", pageArray[i], idx + 1);
            } else {
                frames[count] = pageArray[i];
                printf("Page Miss: Storing %d Page no in Frame %d\n", pageArray[i], count + 1);
                count++;
                pageFaults++;
            }
        } else {
            idx = find(frameCount, frames, pageArray[i]);
            if (idx != -1) {
                pageHits++;
                printf("Page Hit: Successfully found Page %d at Frame %d\n", pageArray[i], idx + 1);
            } else {
                index = findMRU(pageArray, i, no_of_pages, frameCount, frames);
                printf("Page Miss: Replacing %d Frame Page with %d Page no:\n", index + 1, pageArray[i]);
                pageFaults++;
                frames[index] = pageArray[i];
            }
        }
    }

    printf("The total number of page faults: %d\n", pageFaults);
    printf("The total number of page hits: %d\n", pageHits);

    // Free dynamically allocated memory
    free(pageArray);
    free(frames);

    return 0;
}

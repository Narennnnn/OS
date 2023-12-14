#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames = MAX_FRAMES;
    int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf(" Incoming \tFrame 1 \tFrame 2 \tFrame 3 ");

    int frameBuffer[MAX_FRAMES];

    for (int m = 0; m < frames; m++) {
        frameBuffer[m] = -1;
    }

    for (int m = 0; m < pages; m++) {
        int pageFound = 0;

        for (int n = 0; n < frames; n++) {
            if (incomingStream[m] == frameBuffer[n]) {
                pageFound = 1;
                pageFaults--;
            }
        }

        pageFaults++;

        if ((pageFaults <= frames) && (!pageFound)) {
            frameBuffer[m] = incomingStream[m];
        } else if (!pageFound) {
            frameBuffer[(pageFaults - 1) % frames] = incomingStream[m];
        }

        printf("\n%d\t\t\t", incomingStream[m]);

        for (int n = 0; n < frames; n++) {
            if (frameBuffer[n] != -1) {
                printf(" %d\t\t\t", frameBuffer[n]);
            } else {
                printf(" - \t\t\t");
            }
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);

    return 0;
}

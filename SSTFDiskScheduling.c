#include<stdio.h>
#include<stdlib.h>

#define MAX_REQUESTS 100
#define MARKED_REQUEST 1000

int main() {
    int RQ[MAX_REQUESTS], i, n, TotalHeadMovement = 0, headPos, count = 0;

    printf("Enter the number of Requests\n");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_REQUESTS) {
        printf("Invalid number of requests. Exiting.\n");
        return 1;  // Exit with an error code
    }

    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter headPos head position\n");
    scanf("%d", &headPos);

    // Logic for SSTF disk scheduling
    while (count != n) {
        int min = 1000, d, index;

        for (i = 0; i < n; i++) {
            if (RQ[i] == MARKED_REQUEST)
                continue;  // Skip marked requests

            d = abs(RQ[i] - headPos);

            if (min > d) {
                min = d;
                index = i;
            }
        }

        TotalHeadMovement += min;
        headPos = RQ[index];
        RQ[index] = MARKED_REQUEST;
        count++;
    }

    printf("Total head movement is %d\n", TotalHeadMovement);

    return 0;
}

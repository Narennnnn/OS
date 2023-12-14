#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, n, req[50], totalHeadMovement = 0, currentPos;

    printf("Enter the current position\n");
    scanf("%d", &currentPos);

    printf("Enter the number of requests\n");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Invalid number of requests. Exiting.\n");
        return 1;  // Exit with an error code
    }

    printf("Enter the request order\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    totalHeadMovement += abs(currentPos - req[0]);
    printf("%d -> %d", currentPos, req[0]);

    for (i = 1; i < n; i++) {
        totalHeadMovement += abs(req[i] - req[i - 1]);
        printf(" -> %d", req[i]);
    }

    printf("\n");
    printf("Total head movement = %d\n", totalHeadMovement);

    return 0;
}

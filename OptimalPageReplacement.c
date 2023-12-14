#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_REFERENCE_STRING 20

void display(int fr[], int m);

int main() {
    int i, j, page[MAX_REFERENCE_STRING], fr[MAX_FRAMES], n, m;
    int max, found = 0, lg[MAX_FRAMES], index, k, flag1 = 0, flag2 = 0, pf = 0;
    float pr;

    printf("Enter length of the reference string: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_REFERENCE_STRING) {
        printf("Invalid length of the reference string. Exiting.\n");
        return 1;  // Exit with an error code
    }

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &m);

    if (m <= 0 || m > MAX_FRAMES) {
        printf("Invalid number of frames. Exiting.\n");
        return 1;  // Exit with an error code
    }

    for (i = 0; i < m; i++)
        fr[i] = -1;

    pf = m;

    for (j = 0; j < n; j++) {
        flag1 = 0;
        flag2 = 0;

        for (i = 0; i < m; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (i = 0; i < m; i++) {
                if (fr[i] == -1) {
                    fr[i] = page[j];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            for (i = 0; i < m; i++)
                lg[i] = 0;

            for (i = 0; i < m; i++) {
                for (k = j + 1; k < n; k++) {
                    if (fr[i] == page[k]) {
                        lg[i] = k - j;
                        break;
                    }
                }
            }

            found = 0;

            for (i = 0; i < m; i++) {
                if (lg[i] == 0) {
                    index = i;
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                max = lg[0];
                index = 0;

                for (i = 0; i < m; i++) {
                    if (max < lg[i]) {
                        max = lg[i];
                        index = i;
                    }
                }
            }

            fr[index] = page[j];
            pf++;
        }

        display(fr, m);
    }

    printf("Number of page faults: %d\n", pf);
    pr = (float)pf / n * 100;
    printf("Page fault rate = %f \n", pr);

    return 0;
}

void display(int fr[], int m) {
    int i;

    for (i = 0; i < m; i++)
        printf("%d\t", fr[i]);

    printf("\n");
}

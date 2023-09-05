#include <stdio.h>
#include <math.h>

int main() {
    int n;

    printf("Enter the number of processes: \n");
    scanf("%d", &n);

    int at[n], bt[n];
    printf("Enter the arrival and burst time of processes: \n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }

    int wt[n], tat[n];
    tat[0] = bt[0];

    int avgwt = 0, turnArndAvg = 0;

    for (int i = 1; i < n; i++) {
        tat[i] = bt[i] + tat[i - 1];
        turnArndAvg += tat[i];
    }

    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - (at[i] + bt[i]);
        avgwt += wt[i];
    }

    printf("Average waiting time is %0.2f\n", (float)(avgwt) / n);
    printf("Average Turn around time is %0.2f\n", (float)(turnArndAvg) / n);

    return 0;
}

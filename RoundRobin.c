#include<stdio.h>

#define MAX_PROCESSES 10

int main() {
    int processIndex, n, t, remain, flag, timeQuantum, wt = 0, tat = 0;
    int arrivalTime[MAX_PROCESSES], burstTime[MAX_PROCESSES], remainingTime[MAX_PROCESSES];

    printf("Enter Total Processes:\t ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESSES) {
        printf("Invalid number of processes. Exiting.\n");
        return 1;
    }

    remain = n;

    for (processIndex = 0; processIndex < n; processIndex++) {
        printf("Enter Arrival Time and Burst Time for Process Number %d: ", processIndex + 1);
        scanf("%d", &arrivalTime[processIndex]);
        scanf("%d", &burstTime[processIndex]);
        remainingTime[processIndex] = burstTime[processIndex];
    }

    printf("Enter Time Quantum:\t");
    scanf("%d", &timeQuantum);

    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");

    for (t = 0, processIndex = 0; remain != 0;) {
        flag = 0;

        if (remainingTime[processIndex] <= timeQuantum && remainingTime[processIndex] > 0) {
            t += remainingTime[processIndex];
            remainingTime[processIndex] = 0;
            flag = 1;
        } else if (remainingTime[processIndex] > 0) {
            t += timeQuantum;
            remainingTime[processIndex] -= timeQuantum;
        }

        if (remainingTime[processIndex] == 0 && flag == 1) {
            remain--;

            printf("P[%d]\t|\t%d\t|\t%d\n", processIndex + 1, t - arrivalTime[processIndex],
                   t - arrivalTime[processIndex] - burstTime[processIndex]);

            wt += t - arrivalTime[processIndex] - burstTime[processIndex];
            tat += t - arrivalTime[processIndex];
            flag = 0;
        }

        processIndex = (processIndex + 1) % n;
    }

    printf("\nAverage Waiting Time= %f\n", wt * 1.0 / n);
    printf("Avg Turnaround Time = %f\n", tat * 1.0 / n);

    return 0;
}

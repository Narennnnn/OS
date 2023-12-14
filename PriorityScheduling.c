#include<stdio.h>

#define MAX_PROCESSES 10

int main() {
    int processNumber[MAX_PROCESSES], burstTime[MAX_PROCESSES], priority[MAX_PROCESSES], waitTime[MAX_PROCESSES], turnaroundTime[MAX_PROCESSES];
    int n, i, j, temp, totalWaitTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESSES) {
        printf("Invalid number of processes. Exiting.\n");
        return 1;
    }

    printf("\nEnter process time priorities:\n");
    for (i = 0; i < n; i++) {
        printf("Process no %d: ", i + 1);
        scanf("%d %d", &burstTime[i], &priority[i]);
        processNumber[i] = i + 1;
    }

    // Sorting based on priority
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[i] < priority[j]) {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                temp = processNumber[i];
                processNumber[i] = processNumber[j];
                processNumber[j] = temp;
            }
        }
    }

    // Calculating wait time and turnaround time
    waitTime[0] = 0;
    turnaroundTime[0] = burstTime[0];

    for (i = 1; i < n; i++) {
        waitTime[i] = turnaroundTime[i - 1];
        totalWaitTime += waitTime[i];
        turnaroundTime[i] = waitTime[i] + burstTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Printing the results
    printf("\nJob \t Burst Time \t Wait Time \t Turnaround Time \t Priority\n");
    for (i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n", processNumber[i], burstTime[i], waitTime[i], turnaroundTime[i], priority[i]);
    }

    // Calculating and printing averages
    float averageWaitTime = (float)totalWaitTime / n;
    float averageTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("\nAverage Wait Time: %.2f\n", averageWaitTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);

    return 0;
}

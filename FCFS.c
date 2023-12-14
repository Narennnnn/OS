#include <stdio.h>
#include <unistd.h>

#define NUM_PROCESSES 5

void calculateWaitTime(int burst[], int wait[]) {
    for (int i = 1; i < NUM_PROCESSES; i++) {
        wait[i] = wait[i - 1] + burst[i - 1];
    }
}

void calculateTurnaroundTime(int burst[], int wait[], int tat[]) {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        tat[i] = wait[i] + burst[i];
    }
}

void printAverages(int wait[], int tat[]) {
    int sum_wait = 0, sum_tat = 0;

    for (int i = 0; i < NUM_PROCESSES; i++) {
        sum_wait += wait[i];
        sum_tat += tat[i];
    }

    float avg_w = sum_wait / (float)NUM_PROCESSES;
    float avg_t = sum_tat / (float)NUM_PROCESSES;

    printf("Average Waiting Time: %f\nAverage Turnaround Time: %f\n", avg_w, avg_t);
}

int main() {
    int arrival[NUM_PROCESSES] = {0, 0, 0, 0, 0};
    int burst[NUM_PROCESSES] = {7, 2, 8, 5, 4};
    int wait[NUM_PROCESSES] = {0, 0, 0, 0, 0};
    int tat[NUM_PROCESSES] = {0, 0, 0, 0, 0};

    calculateWaitTime(burst, wait);
    calculateTurnaroundTime(burst, wait, tat);
    printAverages(wait, tat);

    return 0;
}

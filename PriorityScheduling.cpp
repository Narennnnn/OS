#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_PROCESSES = 10;

struct Process {
    int processNumber;
    int burstTime;
    int priority;
    int waitTime;
    int turnaroundTime;
};

bool comparePriority(const Process& a, const Process& b) {
    return a.priority > b.priority;
}

int main() {
    vector<Process> processes(MAX_PROCESSES);
    int n, totalWaitTime = 0, totalTurnaroundTime = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    if (n <= 0 || n > MAX_PROCESSES) {
        cout << "Invalid number of processes. Exiting." << endl;
        return 1;
    }

    cout << "\nEnter process time priorities:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process no " << i + 1 << ": ";
        cin >> processes[i].burstTime >> processes[i].priority;
        processes[i].processNumber = i + 1;
    }

    // Sorting based on priority
    sort(processes.begin(), processes.begin() + n, comparePriority);

    // Calculating wait time and turnaround time
    processes[0].waitTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        processes[i].waitTime = processes[i - 1].turnaroundTime;
        totalWaitTime += processes[i].waitTime;
        processes[i].turnaroundTime = processes[i].waitTime + processes[i].burstTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    // Printing the results
    cout << "\nJob \t Burst Time \t Wait Time \t Turnaround Time \t Priority\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].processNumber << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].waitTime
             << "\t\t" << processes[i].turnaroundTime << "\t\t" << processes[i].priority << endl;
    }

    // Calculating and printing averages
    float averageWaitTime = static_cast<float>(totalWaitTime) / n;
    float averageTurnaroundTime = static_cast<float>(totalTurnaroundTime) / n;

    cout << "\nAverage Wait Time: " << averageWaitTime << endl;
    cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;

    return 0;
}

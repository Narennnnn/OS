#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int p;
    p = fork(); // Create a new process

    if (p == 0) {
        // This code block executes in the child process
        printf("Child process created (PID: %d)\n", getpid());
    }
    
    if (p > 0) {
        // This code block executes in the parent process
        printf("Parent process is running (PID: %d)\n", getpid());
    }

    if (p < 0) {
        // This code block executes if an error occurred
        printf("Child process not created\n");
    }

    return 0;
}

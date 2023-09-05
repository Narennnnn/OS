#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("ORPHAN PROCESS\n");

    int p_id = fork(); // Create a new process

    if (p_id == 0) {
        // Code in the child process
        sleep(10); // Child sleeps for 10 seconds
        printf("Child process\n");
    }

    if (p_id > 0) {
        // Code in the parent process
        printf("Parent process\n");
    }

    return 0;
}

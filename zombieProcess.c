#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("ZOMBIE PROCESS\n");

    int p_id = fork(); // Create a new process

    if (p_id > 0) {
        // Code in the parent process
        sleep(10); // Parent sleeps for 10 seconds
        printf("Parent process\n");
    } else {
        // Code in the child process
        exit(0); // Child exits immediately
    }

    return 0;
}

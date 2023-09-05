#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2], n, p;
    char buffer[50];

    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    p = fork();

    if (p < 0) {
        perror("Fork failed");
        return 1;
    }

    if (p > 0) {
        close(fd[0]); // Close the read end of the pipe in the parent process
        printf("\nPassing Values to child (PID=%d)\n", getpid());
        write(fd[1], "Deemed Geu\n", 11); // Write data to the pipe
        close(fd[1]); // Close the write end of the pipe in the parent process
    } else {
        close(fd[1]); // Close the write end of the pipe in the child process
        printf("\nChild received the data (PID=%d)\n", getpid());
        n = read(fd[0], buffer, sizeof(buffer)); // Read data from the pipe
        close(fd[0]); // Close the read end of the pipe in the child process
        write(1, buffer, n); // Write the received data to the standard output (stdout)
    }
    return 0;
}

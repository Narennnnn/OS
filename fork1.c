#include <stdio.h>  // Include standard input-output library
#include <unistd.h> // Include the library for the fork() system call
#include <stdlib.h> // Include standard library functions

int main() {
    fork(); // Create a new process by duplicating the current process
    printf("hello world \n"); // Print "hello world" from both parent and child processes
    return 0; // Exit the program
}

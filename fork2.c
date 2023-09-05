#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    fork();  // First fork, 2 processes (including the original one)
    fork();  // Second fork, now 4 processes
    fork();  // Third fork, finally 8 processes
    printf("hello world \n");  // Each of the 8 processes will print "hello world"
    return 0;
}





Original Process
   |
   +-- Child 1
   |     |
   |     +-- Grandchild 1
   |     |     |
   |     |     +-- Great-grandchild 1
   |     |
   |     +-- Grandchild 2
   |           |
   |           +-- Great-grandchild 2
   |
   +-- Child 2
   |     |
   |     +-- Grandchild 3
   |           |
   |           +-- Great-grandchild 3
   |
   +-- Child 3
         |
         +-- Grandchild 4
               |
               +-- Great-grandchild 4

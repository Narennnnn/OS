#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of terms: \n");
    scanf("%d", &n);

    int p_id = fork(); // Create a new process

    if (p_id == 0) {
        // Code in the child process
        int sum = 0, a = 0, b = 1, c;
        for (int i = 0; i < n; i++) {
            sum = sum + a;
            c = a + b;
            a = b;
            b = c;
        }
        printf("Sum of Fibonacci series up to %d terms is %d\n", n, sum);
    } else {
        // Code in the parent process
        int a = 0, b = 1, c;
        printf("Fibonacci Series: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a);
            c = a + b;
            a = b;
            b = c;
        }
        printf("\n");
    }

    return 0;
}

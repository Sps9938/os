#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process: exiting now.\n");
        exit(0);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process: child has exited. Parent exists.\n");
        sleep(10);
        while (1);
    } else {
        // fork failed
        perror("fork failed");
        exit(1);
    }

    return 0;
}

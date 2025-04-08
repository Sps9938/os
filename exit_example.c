#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>  // Needed for wait()

int main() {
    if (fork() == 0) {
        // Child process
        printf("Child exiting\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);  // Waits for the child to finish
        printf("Parent done\n");
    }
    return 0;
}

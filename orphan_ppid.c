#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) exiting.\n", getpid());
        exit(0);  // Parent exits immediately
    } else {
        // Child process
        sleep(2);  // Give time for parent to exit and child to become orphan
        printf("Orphan child process:\n");
        printf("  PID  = %d\n", getpid());
        printf("  PPID = %d (should be 1 or systemd)\n", getppid());
    }

    return 0;
}

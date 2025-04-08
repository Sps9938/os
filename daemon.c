#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    if (pid > 0) {
        // Parent process exits
        exit(0);
    }

    // Child continues
    if (setsid() < 0) {
        perror("setsid failed");
        exit(1);
    }

    // Set file permissions mask
    umask(0);

    // Change working directory to root
    if (chdir("/") < 0) {
        perror("chdir failed");
        exit(1);
    }

    // Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Open a log file to show it's working (optional)
    int fd = open("/tmp/daemon.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) exit(1);

    // Main daemon loop
    while (1) {
        dprintf(fd, "Daemon is alive: PID %d\n", getpid());
        sleep(10);
    }

    close(fd);
    return 0;
}


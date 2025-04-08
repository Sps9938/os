#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) printf("Child running\n");
    else { wait(NULL); printf("Parent waited.\n"); }
    return 0;
}

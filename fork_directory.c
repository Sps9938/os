#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char cwd[PATH_MAX];
    pid_t pid = fork();
    getcwd(cwd, sizeof(cwd));
    if (pid == 0) printf("Child Dir: %s\n", cwd);
    else printf("Parent Dir: %s\n", cwd);
    return 0;
}

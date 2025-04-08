#include <stdio.h>
#include <unistd.h>

int main() {
    if (fork() > 0) printf("Parent exiting\n");
    else { sleep(5); printf("Orphan process. PPID: %d\n", getppid()); }
    return 0;
}

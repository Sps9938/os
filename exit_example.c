#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    if (fork() == 0) { printf("Child exiting\n"); exit(0); }
    else { wait(NULL); printf("Parent done\n"); }
    return 0;
}

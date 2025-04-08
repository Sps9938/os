#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *dir = "/";  // You can change this to any path, e.g., "/home/user"

    printf("Listing contents of directory: %s\n\n", dir);

    // Replace current process with 'ls' command
    execl("/bin/ls", "ls", "-l", dir, NULL);

    // If execl fails, this line will run
    perror("execl failed");

    return 1;
}

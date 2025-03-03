#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd;
    char buffer[256];

    // Open input.txt for reading/writing
    fd = open("input.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    // Read file content into buffer
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        exit(1);
    }
    buffer[bytesRead] = '\0';

    // Create child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        exit(1);
    }

    if (pid == 0) {  // Child process
        const char *msg = "Processed by child process\n";
        write(fd, msg, sizeof(msg));

        // Replace child process with "cat input.txt"
        execlp("cat", "cat", "input.txt", NULL);

        perror("execlp failed"); // If execlp fails
        exit(1);
    } else {  // Parent process
        wait(NULL); // Wait for child to finish
        printf("Parent process completed.\n");
    }

    close(fd);
    return 0;
}

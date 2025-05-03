#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

FILE *tempFile;

void cleanup(int sig) {
    fclose(tempFile);
    remove("temp.txt");
    printf("\n[+] Caught SIGINT. Temporary file closed and deleted. Exiting now.\n");
    exit(0);
}

int main() {
    signal(SIGINT, cleanup);
    tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        perror("File open failed");
        return 1;
    }

    int count = 1;
    while (1) {
        fprintf(tempFile, "Line %d: writing to file...\n", count++);
        fflush(tempFile);
        sleep(1);
    }

    return 0;
}

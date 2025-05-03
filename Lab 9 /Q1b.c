#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>

void proc_exit() {
    int wstat;
    pid_t pid;
    while (1) {
        pid = waitpid(-1, &wstat, WNOHANG);
        if (pid <= 0) {
            break;
        }
        printf("Child with PID %d terminated, return code: %d\n", pid, wstat);
    }
}

int main() {
    signal(SIGCHLD, proc_exit);

    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        }
        if (pid == 0) {
            // Child process
            printf("Child %d alive, PID: %d\n", i, getpid());
            int ret_code = rand() % 100; // Random exit code
            sleep(1 + rand() % 3); // Random sleep to simulate work
            exit(ret_code);
        }
    }

    // Parent process
    while (1) {
        pause(); // Wait for SIGCHLD
    }

    return 0;
}

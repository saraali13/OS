#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>

void proc_exit() {
    int wstat;
    pid_t pid;

    while (1) {
       
       //    WNOHANG returns immediately if there is no child to wait 
        pid = wait3(&wstat, WNOHANG, NULL);
        if (pid == 0 || pid == -1) {
            if (pid == 0)
                printf(stdout, "Return value of wait3() is %d\n", pid);
            return;
        }
        printf(stdout, "Return code: %d\n", wstat);
    }
}

int main() {
    signal(SIGCHLD, proc_exit);
    switch (fork()) {
        case -1:
            perror("main: fork");
            exit(1);
        case 0:
            printf("I'm alive (temporarily)\n"); // child only executes this and exits
            int ret_code = rand();
            printf("Return code is %d\n", ret_code);
            exit(ret_code);
        default:
            break;
    }
    pause(); // suspends main process execution until a signal arrives
    exit(0);
}

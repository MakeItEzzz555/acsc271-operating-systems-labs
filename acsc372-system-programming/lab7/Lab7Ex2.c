#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int child_start[2];

    if (pipe(child_start) == -1) {
        perror("pipe");
        return 1;
    }

    printf("Program started.\n");
    fflush(stdout);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        char start_signal;

        close(child_start[1]);
        if (read(child_start[0], &start_signal, 1) == -1) {
            perror("read");
            exit(1);
        }
        close(child_start[0]);

        printf("I am the child.\n");
        printf("Child PID: %d\n", getpid());
        printf("My parent PID: %d\n", getppid());
        sleep(2);
        exit(0);
    }

    close(child_start[0]);
    printf("I am the parent. Waiting for child to finish...\n");
    fflush(stdout);
    if (write(child_start[1], "1", 1) == -1) {
        perror("write");
        close(child_start[1]);
        return 1;
    }
    close(child_start[1]);

    if (wait(NULL) == -1) {
        perror("wait");
        return 1;
    }

    printf("Child finished. My PID is %d\n", getpid());

    return 0;
}

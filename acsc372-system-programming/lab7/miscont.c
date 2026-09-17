#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    const char *messages[] = {
        "[Navigation] Calculating coordinates...",
        "[Life Support] Oxygen levels stable.",
        "[Communications] Sending ping to Earth...",
        "[Science] Running microgravity experiment..."
    };

    printf("Mission Control (PID %d) initializing...\n", getpid());
    fflush(stdout);

    for (int i = 0; i < 4; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            return 1;
        }

        if (pid == 0) {
            printf("Astronaut %d reporting for duty! PID: %d\n", i + 1, getpid());
            printf("%s\n", messages[i]);
            exit(0);
        }
    }

    for (int i = 0; i < 4; i++) {
        pid_t completed_pid = wait(NULL);

        if (completed_pid == -1) {
            perror("wait");
            return 1;
        }

        printf("Mission Control: Astronaut (PID %d) has completed their task.\n", completed_pid);
    }

    printf("Mission Control: All astronauts have returned.\n");

    return 0;
}

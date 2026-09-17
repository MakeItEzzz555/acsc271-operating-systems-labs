#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int value = 0; // Global variable shared within threads

void *runner(void *param); // The function executed by the thread

int main(int argc, char *argv[]) {
    int pid;
    pthread_t tid; // Thread ID
    pthread_attr_t attr; // Thread attributes

    pid = fork();
    if (pid == 0) {
        // This is the child process
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, argv[1]);
        pthread_join(tid, NULL);
        printf("Child process: value = %d\n", value); // LINE C
    } else if (pid > 0) {
        // This is the parent process
        wait(NULL);
        printf("Parent process: value = %d\n", value); // LINE P
    }

    return 0;
}

void *runner(void *param) {
    value = 5; // Modify global variable
    pthread_exit(0); // Exit thread
}

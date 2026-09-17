#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; // Global variable to be shared by thread(s)
void *runner(void *param); // The function executed by the thread

int main(int argc, char *argv[]) {
    pthread_t tid; // Thread ID
    pthread_attr_t attr; // Thread attributes

    // If the number of arguments != 2, print an error
    if (argc != 2) {
        printf("Usage: %s <integer value>\n", argv[0]);
        return -1;
    }

    // If the number entered is not positive
    if (atoi(argv[1]) < 0) {
        printf("%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }

    // Get the default thread attributes
    pthread_attr_init(&attr);

    // Create the thread to run function runner
    pthread_create(&tid, &attr, runner, argv[1]);

    // Wait for thread to complete and exit
    pthread_join(tid, NULL);

    // Print the sum
    printf("Sum = %d\n", sum);
    return 0;
}

// Function Implementation
void *runner(void *param) {
    int counter, upper = atoi(param);
    sum = 0;

    for (counter = 1; counter <= upper; counter++)
        sum += counter;

    pthread_exit(0); // Exit thread
}

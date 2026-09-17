#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/* Prints x's to stderr. */
void *print_xs(void *unused) {
    while (1) {
        fputc('x', stderr);
        usleep(10000); // Slow down for readability
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    // Create a new thread to run print_xs
    pthread_create(&thread_id, NULL, print_xs, NULL);

    // Main thread prints o's
    while (1) {
        fputc('o', stderr);
        usleep(10000); // Slow down for readability
    }

    return 0;
}

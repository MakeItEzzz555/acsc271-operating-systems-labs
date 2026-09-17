#include <pthread.h>
#include <stdio.h>

/* Parameters to print_function. */
struct char_print_parms {
    char character; // The character to print
    int count;      // The number of times to print it
};

/* Prints a number of characters to stderr, as given by PARAMETERS. */
void *char_print(void *parameters) {
    struct char_print_parms *p = (struct char_print_parms *)parameters;
    for (int i = 0; i < p->count; ++i)
        fputc(p->character, stderr);
    return NULL;
}

int main() {
    pthread_t thread1_id, thread2_id;
    struct char_print_parms thread1_args, thread2_args;

    // Create a new thread to print 30,000 x’s
    thread1_args.character = 'x';
    thread1_args.count = 30000;
    pthread_create(&thread1_id, NULL, char_print, &thread1_args);

    // Create a new thread to print 20,000 o’s
    thread2_args.character = 'o';
    thread2_args.count = 20000;
    pthread_create(&thread2_id, NULL, char_print, &thread2_args);

    // Wait for the threads to finish
    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);

    return 0;
}

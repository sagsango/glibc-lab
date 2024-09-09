#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Thread function
void* threadFunc(void* arg) {
    int* threadNum = (int*)arg;
    printf("Hello from thread %d\n", *threadNum);
    free(threadNum); // Free the allocated memory for the argument
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int* threadNum = malloc(sizeof(int)); // Allocate memory for the thread argument
    if (threadNum == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }
    *threadNum = 1;

    // Create a new thread
    int rc = pthread_create(&thread, NULL, threadFunc, threadNum);
    if (rc) {
        fprintf(stderr, "Error: Unable to create thread, %d\n", rc);
        free(threadNum); // Free the allocated memory if thread creation fails
        return 1;
    }

    // Wait for the thread to complete
    rc = pthread_join(thread, NULL);
    if (rc) {
        fprintf(stderr, "Error: Unable to join thread, %d\n", rc);
        return 1;
    }

    printf("Main thread completed\n");
    return 0;
}


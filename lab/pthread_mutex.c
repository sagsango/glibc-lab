#include <stdio.h>
#include <pthread.h>

// Define a mutex
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

// Example usage
void* thread_function(void* arg) {
    pthread_mutex_lock(&my_mutex);
    printf("Thread acquired the lock\n");
    // Do some work while holding the lock
    pthread_mutex_unlock(&my_mutex);
    printf("Thread released the lock\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    thread_function(NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}


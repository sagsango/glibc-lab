#include <stdio.h>
#include <pthread.h>

// Define a spinlock
pthread_spinlock_t my_lock;

// Example usage
void* thread_function(void* arg) {
    pthread_spin_lock(&my_lock);
    printf("Thread acquired the lock\n");
    // Do some work while holding the lock
    pthread_spin_unlock(&my_lock);
    printf("Thread released the lock\n");
    return NULL;
}

int main() {
    // Initialize the spinlock
    pthread_spin_init(&my_lock, 0);

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    thread_function(NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the spinlock
    pthread_spin_destroy(&my_lock);

    return 0;
}


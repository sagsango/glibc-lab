#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

// Signal handler function for the parent process
void handle_sigalrm(int sig) {
    char msg[] = "Parent: Caught SIGALRM. Continuing execution...\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
    // Do not exit the program; just return to continue execution
}

int main() {
    pid_t pid;

    // Register the signal handler for SIGALRM in the parent process
    signal(SIGALRM, handle_sigalrm);

    // Fork the process to create a child
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // This is the child process
        char msg[] = "Child: Sending SIGALRM to parent\n";
        write(STDOUT_FILENO, msg, sizeof(msg) - 1);
        sleep(2);  // Give the parent time to set up the handler
        kill(getppid(), SIGALRM);
        exit(0);  // Child exits after sending the signal
    } else {
        // This is the parent process
        char msg[] = "Parent: Waiting for the child to terminate and for signals...\n";
        write(STDOUT_FILENO, msg, sizeof(msg) - 1);

        // Wait for the child process to terminate
        int status;
        pid_t child_pid = wait(&status);

        if (child_pid > 0) {
            char buf[100];
            int len = snprintf(buf, sizeof(buf), "Parent: Child process %d terminated with status %d.\n", child_pid, status);
            write(STDOUT_FILENO, buf, len);
        } else {
            perror("Wait failed");
        }

        // After the child has terminated, the parent can continue running and handling signals
        char exit_msg[] = "Parent: going to exit!\n";
        write(STDOUT_FILENO, exit_msg, sizeof(exit_msg) - 1);
    }

    return 0;
}


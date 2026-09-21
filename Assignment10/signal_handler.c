#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count signal triggers
volatile sig_atomic_t signal_count = 0;

// TODO: Write your signal handler function here
void handle_sigint(int sig) {
	signal_count++;

	printf("\nSIGINT received! Count: %d\n", signal_count);

	if(signal_count==3){
		printf("Exiting program \n");
		exit(0);
	}

	printf("Program is running \n");
}

int main() {
    // TODO: Register the signal handler.
    signal(SIGINT, handle_sigint);

    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}

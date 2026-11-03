#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define SLEEP_TIME 1

void handler(int sig) {
	switch(sig) {
		case SIGUSR1:
			fprintf(stdout, "Father Woke-up\n");
		break;

		case SIGUSR2:
			fprintf(stdout, "Child Woke-up\n");
		break;

		default:
			return;
	}
}

int main(void) {
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	int pid = fork();
	
	while (1) {
		if (pid) {
			sleep(SLEEP_TIME);
			kill(pid, SIGUSR2);
			pause();
		} else {
			pause();
			sleep(SLEEP_TIME);
			kill(getppid(), SIGUSR1);
		}
	}

	return 0;
}

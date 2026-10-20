#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
	printf("P1\n");

	pid_t pid1 = fork(),
	    pid2;

	if (pid1 != 0) {
		printf("P2\n");
		sleep(2);
		pid2 = fork();

		if (pid2 != 0) {
			printf("P4\n");
			waitpid(pid2, 0, 0);
			printf("P7\n");
			waitpid(pid1, 0, 0);
			printf("P9\n");
		} else {
			printf("P5\n");
		}

	} else {
		printf("P3\n");
		printf("P6\n");
		printf("P8\n");
	}

	return 0;
}

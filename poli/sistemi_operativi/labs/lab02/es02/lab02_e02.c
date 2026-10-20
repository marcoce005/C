#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("Must be: %s [n] [t]", argv[0]);
		return -1;
	}

	int i, v,
	    n = atoi(argv[1]), 
	    t = atoi(argv[2]);

	for (i = 0; i < n; i++) {
		if (fork() != 0)
			if (fork()!= 0)
				break;
	}

	if (i == n) {
		sleep(t);
		printf("terminanted PID = %x PPID = %x \n", getpid(), getppid());
	}

	return 0;
}

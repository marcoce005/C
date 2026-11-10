#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <wait.h>
#include <stdlib.h>

#define SLEEP_TIME 1
#define MAX_LEN_STR 20

void string_to_upper(char *str)
{
	for (int i = 0; i < strlen(str); str[i] = toupper(str[i]), i++)
		;
}

void handler(int sig) { return; }

void producer(int fd_in[2], int fd_out[2])
{
	char str[MAX_LEN_STR];

	pause();

	close(fd_in[1]);
	close(fd_out[0]);

	pid_t pid_c;
	read(fd_in[0], &pid_c, sizeof(pid_c));
	close(fd_in[0]);

	while (1)
	{
		fprintf(stdout, "Insert string [%x] [exit = 'end']:\t", getpid());
		fflush(stdout);
		fscanf(stdin, "%s", str);

		write(fd_out[1], str, sizeof(str[0]) * MAX_LEN_STR);

		sleep(SLEEP_TIME);
		kill(pid_c, SIGUSR2);

		if (strcmp(str, "end") == 0)
			exit(0);

		pause();
	}
}

void consumer(int fd_in[2], int fd_out[2], pid_t pid_p)
{
	char str[MAX_LEN_STR];

	close(fd_out[0]);
	close(fd_in[1]);

	pid_t x = getpid();
	write(fd_out[1], &x, sizeof(pid_t));
	close(fd_out[1]);

	kill(pid_p, SIGUSR1);

	while (1)
	{
		pause();

		read(fd_in[0], str, sizeof(str[0]) * MAX_LEN_STR);

		if (strcmp(str, "end") == 0)
			exit(0);

		string_to_upper(str);
		fprintf(stdout, "[%x] %s\n", getpid(), str);
		fflush(stdout);

		sleep(SLEEP_TIME);
		kill(pid_p, SIGUSR1);
	}
}

int main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	setbuf(stdin, 0);

	int fd_c2p[2], fd_p2c[2];
	pid_t pid_p, pid_c;

	if (pipe(fd_c2p) < 0 || pipe(fd_p2c) < 0)
	{
		fprintf(stderr, "Error creating pipes.");
		return -1;
	}

	pid_p = fork();
	if (pid_p)
		pid_c = fork();

	if (pid_p && pid_c)
	{
		waitpid(pid_p, (int *)0, 0);
		waitpid(pid_c, (int *)0, 0);
	}

	if (pid_p == 0)
	{
		producer(fd_c2p, fd_p2c);
		exit(0);
	}

	if (pid_c == 0)
	{
		consumer(fd_p2c, fd_c2p, pid_p);
		exit(0);
	}

	return 0;
}
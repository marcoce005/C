#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <wait.h>
#include <stdlib.h>

#define SLEEP_TIME 1
#define MAX_LEN_STR 20
#define PID_FILE "pid.txt"

FILE *fp;
char *path;
pid_t pid_p, pid_c;

void string_to_upper(char *str)
{
	for (int i = 0; i < strlen(str); str[i] = toupper(str[i]), i++)
		;
}

void handler(int sig) { return; }

void producer()
{
	char str[MAX_LEN_STR];

	pause();
	FILE *fp = fopen(PID_FILE, "r");
	fscanf(fp, "%d", &pid_c);
	fclose(fp);

	while (1)
	{
		fprintf(stdout, "Insert string [%x] [exit = 'end']:\t", getpid());
		fflush(stdout);
		fscanf(stdin, "%s", str);

		fp = fopen(path, "w");

		fprintf(fp, "%s", str);
		fclose(fp);

		sleep(SLEEP_TIME);
		kill(pid_c, SIGUSR2);

		if (strcmp(str, "end") == 0)
			exit(0);

		pause();
	}
}

void consumer()
{
	char str[MAX_LEN_STR];

	FILE *fp = fopen(PID_FILE, "w");
	fprintf(fp, "%d", getpid());
	fclose(fp);
	kill(pid_p, SIGUSR1);

	while (1)
	{
		pause();

		fp = fopen(path, "r");
		fscanf(fp, "%s", str);
		fclose(fp);

		if (strcmp(str, "end") == 0)
			exit(0);

		string_to_upper(str);
		fprintf(stdout, "[%x] %s\n", getpid(), str);
		fflush(stdout);

		sleep(SLEEP_TIME);
		kill(pid_p, SIGUSR1);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "%s [file_path]\n", argv[0]);
		return -1;
	}

	path = argv[1];

	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	setbuf(stdin, 0);

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
		producer();
		exit(0);
	}

	if (pid_c == 0)
	{
		consumer();
		exit(0);
	}

	return 0;
}

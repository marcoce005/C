#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1024
#define END_FLAG "end\n"
#define SLEEP_TIME 3
#define DEFAULT_PATH_EXEC "/bin/"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stdout, "%s [file_path]", argv[0]);
		return -1;
	}

	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stdout, "Error: file %s not found", argv[1]);
		return -1;
	}

	char line[BUF_SIZE];
	while (fgets(line, sizeof(line), fp))
	{
		char clean_line[strlen(line)];

		strncpy(clean_line, line, strlen(line) - strlen(END_FLAG));
		clean_line[strlen(line) - strlen(END_FLAG)] = '\0';

		fprintf(stdout, "Command: [%s]\n", clean_line);

		char *words[strlen(clean_line)];
		for (int i = 0; i < strlen(clean_line); words[i] = (char *)malloc(strlen(clean_line)), i++)
			;

		int words_count = 0,
			offset = 0,
			consumed;
		while (sscanf(clean_line + offset, "%s%n", words[words_count], &consumed) == 1)
		{
			offset += consumed;
			words_count++;
		}

		words[words_count] = (char *)0;

		char tmp[strlen(clean_line)];
		sprintf(tmp, "%s%s", DEFAULT_PATH_EXEC, words[0]);

		if (!fork())
			execv(tmp, words);

		sleep(SLEEP_TIME);
	}

	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1024
#define END_FLAG "end\n"

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stdout, "%s [file_path]", argv[0]);
		return -1;
	}
	
	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL) {
		fprintf(stdout, "Error: file %s not found", argv[1]);
		return -1;
	}
	
	char line[BUF_SIZE];
	while(fgets(line, sizeof(line), fp)) {
		char clean_line[strlen(line)];	
		strncpy(clean_line, line, strlen(line) - strlen(END_FLAG));
		clean_line[strlen(line) - strlen(END_FLAG)] = '\0';

		fprintf(stdout, "Command: [%s]\n", clean_line);
		system(clean_line);
	}

	return 0;
}

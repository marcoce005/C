#include <stdio.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "%s [file_path.txt]", argv[0]);
		return -1;
	}

	FILE *fp = open(argv[1], "r");
	
	if (fp == NULL) {
		fprintf(stderr, "File %s not found.\n", argv[1]);
		return -1;
	}

	


	return 0;
}

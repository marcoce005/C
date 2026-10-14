#include <stdio.h>

int main(int argc, char **argv) {
	FILE *fp_in, *fp_out;    

	if (argc != 3) {
		fprintf(stdout, "Error, must be:\n%s [source_file] [destination_file]", argv[0]);
		return -1;
	}

	fp_in = fopen(argv[1], "r");
	fp_out = fopen(argv[2], "w");

	char c;
	while((c = fgetc(fp_in)) != EOF)
		fputc(c, fp_out);

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}

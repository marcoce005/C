#include <stdio.h>

int main(int argc, char **argv) {
	FILE *fp_in, *fp_out;    

	if (argc != 3) {
		fprintf(stdout, "Error, must be:\n%s [source_file] [destination_file]", argv[0]);
		return -1;
	}

	fp_in = fopen(argv[1], "rb");
	fp_out = fopen(argv[2], "wb");

	char c;
	while(fread(&c, sizeof(char), 1, fp_in) != 0)
		fwrite(&c, sizeof(char), 1, fp_out);

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}

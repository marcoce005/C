#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stdout, "Error, must be:\n%s [source_file] [destination_file]", argv[0]);
		return -1;
	}

	int fp_in = open(argv[1], O_RDONLY),
		fp_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	char c;
	while (read(fp_in, &c, sizeof(char)) > 0)
		write(fp_out, &c, sizeof(char));

	close(fp_in);
	close(fp_out);

	return 0;
}

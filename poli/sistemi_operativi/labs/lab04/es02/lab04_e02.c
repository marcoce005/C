#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "%s [binary_file]", argv[0]);
		return -1;
	}

	int fd = open(argv[1], O_RDONLY, S_IRUSR);

	if (fd < 0)
	{
		fprintf(stderr, "File %s not found", argv[1]);
		return -1;
	}

	int n;

	read(fd, &n, sizeof(n));

	int elements[n];
	lseek(fd, sizeof(n), SEEK_SET);
	read(fd, elements, sizeof(elements[0]) * n);
	close(fd);

	fprintf(stdout, "Original order: {");
	for (int i = 0; i < n; fprintf(stdout, i != n - 1 ? "%d, " : "%d", elements[i]), i++)
		;
	fprintf(stdout, "}\n");

	pid_t pid1 = fork();

	if (pid1 == 0)
		for (int i = 0; i < n - 1; i++)
		{
			pid_t x;
			int values[2];
			for (int j = 0; j < n - i - 1; j++)
			{
				if ((x = fork()))
				{
					waitpid(x, (int *)0, 0);
					fprintf(stdout, "Child %3d\t-->\t", j);

					fd = open(argv[1], O_RDONLY, S_IRUSR);
					lseek(fd, sizeof(int) * (1 + j), SEEK_SET);
					read(fd, values, sizeof(values[0]) * 2);
					close(fd);

					fprintf(stdout, "%3d - %3d", values[0], values[1]);

					if (values[0] > values[1])
					{
						values[0] = values[0] ^ values[1];
						values[1] = values[0] ^ values[1];
						values[0] = values[0] ^ values[1];

						fd = open(argv[1], O_WRONLY, S_IRUSR);
						lseek(fd, sizeof(int) * (1 + j), SEEK_SET);
						write(fd, values, sizeof(values[0]) * 2);
						close(fd);
					}

					fprintf(stdout, "\t-->\t%3d - %3d\n", values[0], values[1]);

					return 0;
				}
			}
		}
	else
	{
		waitpid(pid1, (int *)0, 0);
		fd = open(argv[1], O_RDONLY, S_IRUSR);
		lseek(fd, sizeof(n), SEEK_SET);
		read(fd, elements, sizeof(elements[0]) * n);
		close(fd);

		fprintf(stdout, "Sorted: {");
		for (int i = 0; i < n; fprintf(stdout, i != n - 1 ? "%d, " : "%d", elements[i]), i++)
			;
		fprintf(stdout, "}\n");
	}

	return 0;
}

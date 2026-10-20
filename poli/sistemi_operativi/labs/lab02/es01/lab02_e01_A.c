#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i;

	printf("PID main: %x\n", getpid());

	for (i = 1; i <= 2; i++)
	{
		if (!fork())
			// printf ("%d\n", i);
			printf("%d - PID: %x\n", i, getpid());
	}
	// printf ("%d\n", i);
	printf("%d - PID: %x\n", i, getpid());

	return 0;
}
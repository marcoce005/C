#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int i;

	for (i = 3; i > 1; i--)
	{
		if (fork())
			printf("%d\n", i);
		sleep(1);
	}
	printf("%d\n", i);

	return 0;
}
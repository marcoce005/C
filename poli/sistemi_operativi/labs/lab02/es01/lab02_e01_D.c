#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int i;
	
	for (i = 2; i >= 1; i--)
	{
		if (!fork())
			printf("%d\n", -i);
		else
			printf("%d\n", i);
		sleep(1);
	}

	return 0;
}
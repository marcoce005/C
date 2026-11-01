#include <stdio.h>

int main(void) {		// A. execute the normal file
						// B. execute the file with input the redirection of inFile.txt [< inFile.txt]
						// 	  the output redirection for evenFile.txt [> evenFile.txt]
						// 	  the output error redirection for oddFile.txt [2> oddFile.txt]
	int n;

	do {
		scanf("%d", &n);

		if (n != 0)
			fprintf(n % 2 == 0 ? stdout : stderr, "%d\n", n);		// with the redirection > even 2> odd
	} while (n != 0);

	return 0;
}

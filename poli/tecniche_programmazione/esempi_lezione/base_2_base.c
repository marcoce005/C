#include <stdio.h>

void base_2_base(char *n, int b0, int b1);

void dec_2_base(int n, int base);

int main(void)
{
	int base_0, base_1;
	char n[10];

	printf("\nSelect the original base:\t");
	scanf("%d", &base_0);

	printf("\nDigit the number you what convert:\t");
	scanf("%s", n);

	printf("\nSelect the expected base:\t");
	scanf("%d", &base_1);

	printf("\nBase %d:\t%s\nBase %d:\t", base_0, n, base_1);
	base_2_base(n, base_0, base_1);

	return 0;
}

void dec_2_base(int n, int base)
{
	int next;

	for (next = 1; next * base <= n; next *= base);

	while (next > 0)
	{
		if (n >= next) {
			printf("%d", n / next);
			n -= next;
		} else
			printf("0");
		next /= base;
	}
}

void base_2_base(char *n, int b0, int b1)
{
	int i = 0, cifra, tot = 0;

	while (n[i] != '\0')
	{
		cifra = n[i++] - '0';
		
		if (cifra >= 0 && cifra < b0)
			tot = b0 * tot + cifra;
			
		if (b0 > 10 && cifra >= 17  && cifra < 17 + (b0 - 10)) {
			tot = b0 * tot + (cifra - 7);
		}
	}

	dec_2_base(tot, b1);
}
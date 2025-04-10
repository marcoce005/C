#include <stdio.h>

#define LEN 3

int *swap_arr(int v[]);

int main(void) {
	int v[] = {1, 2, 3};
	int *v1 = v;

	printf("Array:\t");
	for(int i = 0; i < 3; i++)
	printf("%d ", v1[i]);

	v1 = swap_arr(v1);

	printf("\nArray:\t");
	for(int i = 0; i < 3; i++)
		printf("%d ", v1[i]);

	return 0;
}

int *swap_arr(int v[]) {
	static int v2[LEN];

	for (int i = 0; i < LEN; i++)
		v2[i] = v[i] * 10;

	return v2;
}

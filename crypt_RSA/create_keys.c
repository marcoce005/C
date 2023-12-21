#include <stdio.h>
#include <stdlib.h>

int check_primo(int n) {		// 1 è primo 		0 non lo è
	int p = 1;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int cal_n_public(int n_priv, int V) {
	int n = 0;
	for (;;) {
		if (((n * n_priv) % V) == 1) {
			return n;
		}
		n++;
	}
}

int cal_n_priv(int n) {
	n++;
	for(;;) {
		if (check_primo(n)) {
			return n;
		}
		n++;
	}
}

int main(int argc, char **argv) {
    if (argc != 3) {
		printf("<p numero primo> <q numero primo>\n");
		return 0;
	}

	int p = atoi(argv[1]), q = atoi(argv[2]);

	if (!check_primo(p) || !check_primo(q)) {
		printf("Error: <p> e <q> devono essere numeri primi\n");
		return 0;
	}

	int N = p * q;
	if (N <= 255) {
		printf("Il prodotto di <p> e <q> deve essere >255\n");
		return 0;
	}
	int V = (p - 1) * (q - 1);
	int k_priv = cal_n_priv(p > q ? p : q);
	int k_public = cal_n_public(k_priv, V);

	printf("private key = (%d, %d)\npublic key = (%d, %d)\n", N, k_priv, N, k_public);

    return 0;
}

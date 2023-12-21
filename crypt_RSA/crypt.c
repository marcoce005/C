#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

void pow_fatta_bene(int b, int e, mpz_t *result) {
    mpz_t base;
    
    // Initialize variables
    mpz_inits(base, result, NULL);
    // Set value for the base
    mpz_set_ui(base, b); // Change this to the desired base
    // Perform exponentiation
    mpz_pow_ui(*result, base, e);
}

#define CHAR_TO_ASCII(x) (int)x

int size = 0;

void push(int *array, int new_int) {
  size++;
  array = realloc(array, size * sizeof(int));
  array[size - 1] = new_int;
}

void init_mpz(mpz_t *num, int N) {
  mpz_init(*num);
  mpz_set_ui(*num, N);

}
int main(int argc, char **argv) {
  
  if(argc != 4) {
    printf("%s: <N> <npub> <message>", argv[0]);
    return 0;
  }
  
  int N = atoi(argv[1]);
  int npub = atoi(argv[2]);
  char *message = argv[3];
  mpz_t divisor;
  init_mpz(&divisor, N);

  // address of the block created hold by this pointer
  int *ptr;

  //  Memory allocates dynamically using malloc()
  ptr = (int *)malloc(size * sizeof(int));

  // Checking for memory allocation
  if (ptr == NULL) {
    printf("Memory not allocated.\n");
  } else {
    
    for (int i = 0; i < strlen(message); i++) {
	mpz_t pow_result, module_result;
	init_mpz(&pow_result, 0);
	init_mpz(&module_result, 0);
	
	pow_fatta_bene(CHAR_TO_ASCII(message[i]), npub, &pow_result);
        mpz_mod(module_result, pow_result, divisor);
        
        push(ptr, mpz_get_ui(module_result));
    }

    for (int i = 0; i < size; i++) {
      printf("%i", ptr[i]);
      if(i < size - 1){
        printf(",");
      }
    }
    printf("\n");
  }

  return 0;
}

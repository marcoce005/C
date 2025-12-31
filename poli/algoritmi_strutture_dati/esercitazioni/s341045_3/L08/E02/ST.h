#ifndef _ST
#define _ST

#define MAX_STR_LEN 30 + 1

typedef struct 
{
    char id[MAX_STR_LEN], net[MAX_STR_LEN];
} computer_t;

typedef struct symbol_table *ST;

ST ST_init(int max_elements);

void ST_free(ST st);

/* boolean value --> found / not found */
int computer_is_void(computer_t x);

computer_t ST_search_by_index(ST st, int index);

/* -1 --> not found */
int ST_search_by_computer_id(ST st, char *name);

void ST_insert(ST st, computer_t value, int index);

#endif
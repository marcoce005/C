#ifndef _CHARACTER
#define _CHARACTER

#include "inventory.h"

typedef struct TabPg *tabPg_t;
typedef struct Pg *pg;

pg search_character_by_code(tabPg_t tab, char *codice);
tabPg_t get_characters(char *path);
void print_character(pg x);
void add_obj_2_equip(obj val, pg character);
void remove_obj_2_equip(obj object, pg character);
void insert_character(tabPg_t tab);
void remove_character(tabPg_t tab, char *code);

#endif
#ifndef _CHARACTER
#define _CHARACTER

#include "inventory.h"

typedef struct TabPg *tabPg_t;
typedef struct Pg *pg;

pg search_character_by_code(tabPg_t tab, char *codice);
tabPg_t get_characters(char *path);
void print_character(pg character_p);
void add_obj_2_equip(obj object_p, pg character_p);
void remove_obj_2_equip(obj object_p, pg character_p);
void insert_character(tabPg_t tab);
void remove_character(tabPg_t tab, char *code);
void cal_statistics(pg character_p);

#endif
#ifndef _INVENTORY
#define _INVENTORY

typedef struct inv_t *tabInv_t;
typedef struct Obj *obj;
typedef struct Stat *stat_p;

tabInv_t get_inventory(char *path);
obj search_obj_by_name(tabInv_t tab, char *name);
stat_p get_object_stat(obj object_p);
void print_obj(obj object_p);
void free_inventory(tabInv_t tab);

#endif
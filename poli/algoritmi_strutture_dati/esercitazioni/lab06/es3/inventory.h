#ifndef _INVENTORY
#define _INVENTORY

typedef struct inv_t *tabInv_t;
typedef struct Obj *obj;

tabInv_t get_inventory(char *path);
void print_obj(obj x);
obj search_obj_by_name(tabInv_t tab, char *name);

#endif
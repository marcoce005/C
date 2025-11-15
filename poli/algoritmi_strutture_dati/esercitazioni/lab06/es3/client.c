#include <stdio.h>
#include "character.h"
#include "inventory.h"

#define FILE_PATH_INVENTORY "inventario.txt"
#define FILE_PATH_CHARACTER "pg.txt"

int main(void)
{
    tabInv_t inventory = get_inventory(FILE_PATH_INVENTORY);
    tabPg_t characters = get_characters(FILE_PATH_CHARACTER);

    // print_obj(search_obj_by_name(inventory, "MantoElfico"));

    pg my_character = search_character_by_code(characters, "PG0007");

    print_character(my_character);

    add_obj_2_equip(search_obj_by_name(inventory, "Fiocco"), my_character);
    add_obj_2_equip(search_obj_by_name(inventory, "AmmazzaDraghi"), my_character);
    add_obj_2_equip(search_obj_by_name(inventory, "Tempesta"), my_character);

    print_character(my_character);

    remove_obj_2_equip(search_obj_by_name(inventory, "Excalibur"), my_character); // does not change becuase the object isn't in the equipment

    print_character(my_character);

    remove_character(characters, "PG0003");

    print_character(search_character_by_code(characters, "PG0003"));

    insert_character(characters);

    print_character(search_character_by_code(characters, "PG0069"));

    return 0;
}
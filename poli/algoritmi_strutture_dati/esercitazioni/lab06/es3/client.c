#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "character.h"
// #include "inventory.h"

#define FILE_PATH_INVENTORY "inventario.txt"
#define FILE_PATH_CHARACTER "pg.txt"
#define N_ACTIONS 6
#define LEN_BUFFER 64

typedef enum // enum --> "string"
{
    add_character,          //  --> "add-character"
    delete_character,       //  --> "delete-character"
    add_obj_2_character,    //  --> "add-object"
    delete_obj_2_character, //  --> "delete-object"
    calc_stat,              //  --> "calc-statistics"
    end                     // --> "end"
} command_t;

command_t str_2_command(char *str);
void str_2_lower(char *str, int n);

int main(void)
{
    tabInv_t inventory = get_inventory(FILE_PATH_INVENTORY);
    tabPg_t characters = get_characters(FILE_PATH_CHARACTER);
    obj selected_object;
    pg selected_character;
    int exit = 0;
    char buf[LEN_BUFFER];

    while (!exit)
    {
        printf("\nCommand:\n");
        printf(" - 'add-character'\n");
        printf(" - 'delete-character'\n");
        printf(" - 'add-object'\n");
        printf(" - 'delete-object'\n");
        printf(" - 'calc-statistics'\n");
        printf(" - 'end'\n--> ");
        scanf("%s", buf);

        str_2_lower(buf, strlen(buf));
        switch (str_2_command(buf))
        {
        case add_character:
            insert_character(characters);
            break;

        case delete_character:
            printf("\nInsert code of the character you want delete [PGXXXX X are digits]: ");
            scanf("%s", buf);
            remove_character(characters, buf);
            break;

        case add_obj_2_character:
            printf("\nInsert code of the character [PGXXXX X are digits]: ");
            scanf("%s", buf);
            selected_character = search_character_by_code(characters, buf);
            printf("Insert object name to insert [pay attantion to uppercase and lowercase]: ");
            scanf("%s", buf);
            selected_object = search_obj_by_name(inventory, buf);

            if (selected_character != NULL && selected_object != NULL)
                add_obj_2_equip(selected_object, selected_character);
            else
                printf("\nError: character or object not found");
            break;

        case delete_obj_2_character:
            printf("\nInsert code of the character [PGXXXX X are digits]: ");
            scanf("%s", buf);
            selected_character = search_character_by_code(characters, buf);
            printf("Insert object name to remove [pay attantion to uppercase and lowercase]: ");
            scanf("%s", buf);
            selected_object = search_obj_by_name(inventory, buf);

            if (selected_character != NULL && selected_object != NULL)
                remove_obj_2_equip(selected_object, selected_character);
            else
                printf("\nError: character or object not found");
            break;

        case calc_stat:
            printf("\nInsert code of the character [PGXXXX X are digits]: ");
            scanf("%s", buf);
            selected_character = search_character_by_code(characters, buf);
            if (selected_character == NULL)
                printf("\nError: character not found\n");
            else
                cal_statistics(selected_character);
            break;

        case end:
            exit = 1;
            break;

        default:
            printf("\nCommand '%s' not found.\n", buf);
            break;
        }
    }

    // print_obj(search_obj_by_name(inventory, "MantoElfico"));

    // pg my_character = search_character_by_code(characters, "PG0007");

    // print_character(my_character);

    // add_obj_2_equip(search_obj_by_name(inventory, "Fiocco"), my_character);
    // add_obj_2_equip(search_obj_by_name(inventory, "AmmazzaDraghi"), my_character);
    // add_obj_2_equip(search_obj_by_name(inventory, "Tempesta"), my_character);

    // print_character(my_character);

    // remove_obj_2_equip(search_obj_by_name(inventory, "Excalibur"), my_character); // does not change becuase the object isn't in the equipment

    // print_character(my_character);

    // remove_character(characters, "PG0003");

    // print_character(search_character_by_code(characters, "PG0003"));

    // insert_character(characters);

    // print_character(search_character_by_code(characters, "PG0069"));

    return 0;
}

void str_2_lower(char *str, int n)
{
    for (int i = 0; i < n; str[i] = tolower(str[i]), i++)
        ;
}

command_t str_2_command(char *str)
{
    char *possible[N_ACTIONS] = {
        "add-character",
        "delete-character",
        "add-object",
        "delete-object",
        "calc-statistics",
        "end"};

    for (int i = 0; i < N_ACTIONS; i++)
        if (strcmp(possible[i], str) == 0)
            return i;
    return -1;
}
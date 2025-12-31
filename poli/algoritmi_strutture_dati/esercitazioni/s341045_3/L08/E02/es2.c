#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "graph.h"

#define BUFFER_SIZE 128

typedef enum
{
    vertex,
    adjacency,
    list,
    quit
} command_t;

const char *command_str[] = {
    "vertex",
    "adjacency",
    "list",
    "quit"};

command_t str_2_command(char *str);
void str_2_lower(char *str);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("\nArguments Error: %s <file_path>\n", argv[0]);
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("\nFile error: file %s not found or corrupted.\n", argv[1]);
        return -1;
    }

    graph_t g = Graph_load(fp);
    int exit = 0;
    char buf[BUFFER_SIZE];
    command_t type;

    while (!exit)
    {
        printf("\nSelect the action:\n");
        printf(" - 'vertex' [print all vertices in alphabetic order and thier connected edges]\n");
        printf(" - 'adjacency' [check adjacency of 3 vertex and the possibilty of a sub-graph]\n");
        printf(" - 'list' [generate the adjacency list]\n");
        printf(" - 'quit' [stop the program]\n--> ");

        scanf("%s", buf);
        str_2_lower(buf);
        type = str_2_command(buf);
        switch (type)
        {
        case vertex:
            Graph_print_vertex(g);
            break;

        case adjacency:
            Graph_check_adjacency_beetwen_3_vertex(g);
            break;

        case list:
            Graph_create_list_adjacency(g);
            break;

        case quit:
            Graph_free(g);
            exit = 1;
            break;

        default:
            printf("\nCommand not found.\n");
            break;
        }
    }

    fclose(fp);
    return 0;
}

void str_2_lower(char *str)
{
    for (int i = 0; i < strlen(str); str[i] = tolower(str[i]), i++)
        ;
}

command_t str_2_command(char *str)
{
    for (int i = 0; i < (int)(sizeof(command_str) / sizeof(command_str[0])); i++)
        if (strcmp(command_str[i], str) == 0)
            return i;
    return -1;
}
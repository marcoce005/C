#include <stdio.h>
#include <string.h>

#define MAX_LEN 30 + 1

typedef struct Date
{
    unsigned int yyyy, mm, dd;
} date;

typedef struct Time
{
    unsigned int hh, mm, ss;
} time;

typedef struct Tratte
{
    char codice_tratta[MAX_LEN],
        partenza[MAX_LEN],
        destinazione[MAX_LEN];
    date data;
    time ora_partenza,
        ora_arrivo;
    unsigned int ritardo;
} tratte;

typedef enum // --> typed command
{
    r_date,        // -->  "date"
    r_partenza,    // -->  "partenza"
    r_capolinea,   // -->  "capolinea"
    r_ritardo,     // -->  "ritardo"
    r_ritardo_tot, // -->  "ritardo_tot"
    r_fine         // --> "fine"
} comando_e;

comando_e leggiComando(char str[]); // return -1 --> command not found
void selezionatiDati(tratte logs[], int n, comando_e command);

int main(void)
{
    return 0;
}

comando_e leggiComando(char str[])
{
    char possible_command[][MAX_LEN] = {
        "date",
        "partenza",
        "capolinea",
        "ritardo",
        "ritardo_tot",
        "fine"};
    int i;

    for (i = 0; i < sizeof(possible_command) / sizeof(possible_command[0]); i++)
        if (strcmp(str, possible_command[i]) == 0)
            return i;
    return -1;
}
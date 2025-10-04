#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 30 + 1
#define MAX_ROW 1000
#define FILE_PATH_SOURCE "corse.txt"
#define FILE_PATH_DEST "output.txt"

FILE *fp_output;

typedef struct Date
{
    int yyyy, mm, dd;
} date;

typedef struct Time
{
    int hh, mm, ss;
} time;

typedef struct Tratte
{
    char codice_tratta[MAX_LEN],
        partenza[MAX_LEN],
        destinazione[MAX_LEN];
    date data;
    time ora_partenza,
        ora_arrivo;
    int ritardo;
} tratte;

typedef enum // --> typed command
{
    r_date,                     // -->  "date"
    r_partenza,                 // -->  "partenza"
    r_capolinea,                // -->  "capolinea"
    r_ritardo,                  // -->  "ritardo"
    r_ritardo_tot,              // -->  "ritardo_tot"
    r_ordina,                   // --> "ordina"
    r_codice_tratta,            // --> "codice_tratta"
    r_ricerca_partenza,         // --> "ricerca_partenza"               [linear research]
    r_ricerca_binaria_partenza, // --> "ricerca_binaria_partenza"       [binary research]
    r_fine                      // --> "fine"
} comando_e;

comando_e leggiComando(char str[]); // return -1 --> command not found
tratte *read_file(int *len);
void selezionatiDati(tratte logs[], int n, comando_e command);
void to_lower(char *str);
void to_upper(char *str);
void date_and_ritardo(tratte logs[], int n, comando_e command, char str[], int file);
void print_tratta(tratte tr, int file);
void partenza_and_capolinea(tratte logs[], int len, comando_e command, char str[], int file);
void ritardo_tot(tratte logs[], int len, char str[]);
void open_output_file();
void sort(tratte log[], int n, comando_e command);
void linear_search(tratte log[], int n, char str[]);
void binary_search(tratte log[], int n, char str[], int l, int r);
int between_date(date d0, date d1, date d2);          // check if d2 is between d0 and d1 or viceversa
int compare_date(date d0, time t0, date d1, time t1); // check if d1,t1 < d0,t0

int main(void)
{
    int n_logs, exit = 0;
    comando_e command_enum;
    char command[MAX_LEN];
    tratte *logs = read_file(&n_logs);

    while (exit == 0)
    {
        printf("\nCommand:\n");
        printf(" - 'date' <data1> <data2>\n");
        printf(" - 'partenza' <fermata>\n");
        printf(" - 'capolinea' <fermata>\n");
        printf(" - 'ritardo' <data1> <data2>\n");
        printf(" - 'ritardo_tot' <ID corsa>\n");
        printf(" - 'ordina'\n");
        printf(" - 'ricerca_partenza'\n");
        printf(" - 'ricerca_binaria_partenza'\n");
        printf(" - 'fine'\n--> ");
        scanf("%s", command);

        to_lower(command);
        command_enum = leggiComando(command);
        if (command_enum == r_fine)
            break;
        selezionatiDati(logs, n_logs, command_enum);
    }

    free(logs);
    return 0;
}

void linear_search(tratte log[], int n, char str[])
{
    int i;
    char sub_str[MAX_LEN];

    to_lower(str);
    for (i = 0; i < n; i++)
    {
        strcpy(sub_str, log[i].partenza);
        to_lower(sub_str);
        sub_str[strlen(str)] = '\0';

        if (strcmp(sub_str, str) == 0)
            print_tratta(log[i], 0);
    }
}

void binary_search(tratte log[], int n, char str[], int l, int r)
{
    if (l > r)
        return;

    int m = (l + r) / 2, check;
    char sub_str[MAX_LEN];

    strcpy(sub_str, log[m].partenza);
    sub_str[strlen(str)] = '\0';
    to_lower(sub_str);
    check = strcmp(str, sub_str);

    if (check == 0)
    {
        print_tratta(log[m], 0);
        binary_search(log, n, str, l, m - 1);
    }
    if (check < 0)
        binary_search(log, n, str, l, m - 1);
    else
        binary_search(log, n, str, m + 1, r);
}

int compare_date(date d0, time t0, date d1, time t1)
{
    int n0 = d0.yyyy * 365 + d0.mm * 31 + d0.dd,
        n1 = d1.yyyy * 365 + d1.mm * 31 + d1.dd;

    if (n1 == n0) // if the date is the same --> sort by depature's time
    {
        n0 = t0.hh * 24 + t0.mm * 60 + t0.ss;
        n1 = t1.hh * 24 + t1.mm * 60 + t1.ss;
    }
    return n1 < n0;
}

void sort(tratte log[], int n, comando_e command)
{
    int i, j, i_min, is_less;
    tratte tmp;
    for (i = 0; i < n - 1; i++)
    {
        i_min = i;
        for (j = i + 1; j < n; j++)
        {
            switch (command)
            {
            case r_date:
                is_less = compare_date(log[i_min].data, log[i_min].ora_partenza, log[j].data, log[j].ora_partenza);
                break;

            case r_codice_tratta:
                is_less = strcmp(log[j].codice_tratta, log[i_min].codice_tratta) < 0;
                break;

            case r_partenza:
                is_less = strcmp(log[j].partenza, log[i_min].partenza) < 0;
                break;

            case r_capolinea:
                is_less = strcmp(log[j].destinazione, log[i_min].destinazione) < 0;
                break;

            default:
                break;
            }
            if (is_less)
                i_min = j;
        }

        if (i != i_min)
        {
            tmp = log[i];
            log[i] = log[i_min];
            log[i_min] = tmp;
        }
    }
}

void open_output_file()
{
    fp_output = fopen(FILE_PATH_DEST, "a");

    if (fp_output == NULL)
    {
        printf("\nFIle not found");
        exit(1);
    }
}

void ritardo_tot(tratte logs[], int len, char str[])
{
    char tmp[MAX_ROW];
    int i, tot = 0;

    to_upper(str);
    str[strlen(str) - 1] = '\0'; // remove '\n' at the and of the command

    for (i = 0; i < len; i++)
        if (strcmp(logs[i].codice_tratta, str) == 0)
            tot += logs[i].ritardo;

    if (tot > 0)
        printf("\nThe delay collect by the route %s is %d minutes\n", str, tot);
    else
        printf("\nThe route %s was not found in the logs or it's not delayed\n", str);
}

void partenza_and_capolinea(tratte logs[], int len, comando_e command, char str[], int file)
{
    char tmp[MAX_LEN];

    if (file)
        open_output_file();

    str[strlen(str) - 1] = '\0'; // remove '\n' at the and of the command
    to_lower(str);
    for (int i = 0; i < len; i++)
    {
        strcpy(tmp, (command == r_partenza ? logs[i].partenza : logs[i].destinazione));
        to_lower(tmp);
        if ((command == r_partenza && strcmp(str, tmp) == 0) || (command == r_capolinea && strcmp(str, tmp) == 0))
            print_tratta(logs[i], file);
    }

    if (file) // made space for new output
    {
        fprintf(fp_output, "\n\n");
        fclose(fp_output);
    }
}

void print_tratta(tratte tr, int file)
{
    if (!file)
        printf("%s %s %s %d/%02d/%02d %02d:%02d:%02d %02d:%02d:%02d %d\n",
               tr.codice_tratta,
               tr.partenza,
               tr.destinazione,
               tr.data.yyyy,
               tr.data.mm,
               tr.data.dd,
               tr.ora_partenza.hh,
               tr.ora_partenza.mm,
               tr.ora_partenza.ss,
               tr.ora_arrivo.hh,
               tr.ora_arrivo.mm,
               tr.ora_arrivo.ss,
               tr.ritardo);
    else
        fprintf(fp_output, "%s %s %s %d/%02d/%02d %02d:%02d:%02d %02d:%02d:%02d %d\n",
                tr.codice_tratta,
                tr.partenza,
                tr.destinazione,
                tr.data.yyyy,
                tr.data.mm,
                tr.data.dd,
                tr.ora_partenza.hh,
                tr.ora_partenza.mm,
                tr.ora_partenza.ss,
                tr.ora_arrivo.hh,
                tr.ora_arrivo.mm,
                tr.ora_arrivo.ss,
                tr.ritardo);
}

int between_date(date d0, date d1, date d2) // convert in a pseudo unix time and compare
{
    int n0 = d0.yyyy * 365 + d0.mm * 31 + d0.dd,
        n1 = d1.yyyy * 365 + d1.mm * 31 + d1.dd,
        n2 = d2.yyyy * 365 + d2.mm * 31 + d2.dd;

    return (n2 >= n0 && n2 <= n1) || (n2 >= n1 && n2 <= n0);
}

void date_and_ritardo(tratte logs[], int len, comando_e command, char str[], int file)
{
    date date0, date1;

    if (sscanf(str, "%d/%d/%d %d/%d/%d", &date0.yyyy, &date0.mm, &date0.dd, &date1.yyyy, &date1.mm, &date1.dd) != 6)
    {
        printf("\nError date or ritardo need two date after the command");
        return;
    }

    if (file)
        open_output_file();

    for (int i = 0; i < len; i++)
        if (between_date(date0, date1, logs[i].data) && (logs[i].ritardo > 0 || command == r_date))
            print_tratta(logs[i], file);

    if (file) // made space for new output
    {
        fprintf(fp_output, "\n\n");
        fclose(fp_output);
    }
}

void selezionatiDati(tratte logs[], int n, comando_e command)
{
    char str[MAX_LEN];
    int file = 0, i;

    fgetc(stdin); // flush the stream
    switch (command)
    {
    case r_date:
        printf("Enter the dates you want search [format date = yyyy/mm/dd]:\n--> ");
        fgets(str, MAX_LEN, stdin);
        printf("Where do you want see the output?\n - file type '1'\n - console type '0'\n--> ");
        scanf("%d", &file);
        date_and_ritardo(logs, n, r_date, str, file);
        break;

    case r_partenza:
        printf("Enter the departure's station [don't use space ' ' instead use underscore '_']:\n--> ");
        fgets(str, MAX_LEN, stdin);
        printf("Where do you want see the output?\n - file type '1'\n - console type '0'\n--> ");
        scanf("%d", &file);
        partenza_and_capolinea(logs, n, r_partenza, str, file);
        break;

    case r_capolinea:
        printf("Enter the arrive's station [don't use space ' ' instead use underscore '_']:\n--> ");
        fgets(str, MAX_LEN, stdin);
        printf("Where do you want see the output?\n - file type '1'\n - console type '0'\n--> ");
        scanf("%d", &file);
        partenza_and_capolinea(logs, n, r_capolinea, str, file);
        break;

    case r_ritardo:
        printf("Enter the dates between you want seach the delayed routes [format date = yyyy/mm/dd]:\n--> ");
        fgets(str, MAX_LEN, stdin);
        printf("Where do you want see the output?\n - file type '1'\n - console type '0'\n--> ");
        scanf("%d", &file);
        date_and_ritardo(logs, n, r_ritardo, str, file);
        break;

    case r_ritardo_tot:
        printf("Enter the codice_tratta ID [codice_tratta format: GTTXXX, X are numbers]:\n--> ");
        fgets(str, MAX_LEN, stdin);
        ritardo_tot(logs, n, str);
        break;

    case r_ordina:
        printf("Choose the sorting method:\n - 'date'\n - 'codice_tratta'\n - 'partenza'\n - 'capolinea'\n--> ");
        fgets(str, MAX_LEN, stdin);
        str[strlen(str) - 1] = '\0'; // remove '\n' at the end
        sort(logs, n, leggiComando(str));
        for (i = 0; i < n; i++)
            print_tratta(logs[i], 0);
        break;

    case r_ricerca_partenza:
        printf("Enter the departure's station or a part of the name [don't use space ' ' instead use underscore '_']:\n--> ");
        fgets(str, MAX_LEN, stdin);
        str[strlen(str) - 1] = '\0'; // remove '\n' at the end
        linear_search(logs, n, str);
        break;

    case r_ricerca_binaria_partenza:
        printf("Enter the departure's station or a part of the name [don't use space ' ' instead use underscore '_']:\n--> ");
        fgets(str, MAX_LEN, stdin);
        str[strlen(str) - 1] = '\0'; // remove '\n' at the end
        sort(logs, n, r_partenza);
        to_lower(str);
        binary_search(logs, n, str, 0, n);
        break;

    default:
        printf("\nCommand not found");
        break;
    }
}

void to_lower(char *str)
{
    for (; *str != '\0'; *str = tolower(*str), str++)
        ;
}

void to_upper(char *str)
{
    for (; *str != '\0'; *str = toupper(*str), str++)
        ;
}

tratte *read_file(int *len)
{
    FILE *fp = fopen(FILE_PATH_SOURCE, "r");
    int i;

    if (fp == NULL)
    {
        printf("\nFile not found");
        exit(1);
    }

    fscanf(fp, "%d", len);
    if (*len <= 0 || *len > MAX_LEN)
    {
        fclose(fp);
        printf("\nWrong row number");
        exit(1);
    }
    tratte *t = (tratte *)malloc((*len) * sizeof(tratte));

    for (i = 0; i < *len; i++)
        fscanf(fp, "%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d",
               t[i].codice_tratta,
               t[i].partenza,
               t[i].destinazione,
               &t[i].data.yyyy,
               &t[i].data.mm,
               &t[i].data.dd,
               &t[i].ora_partenza.hh,
               &t[i].ora_partenza.mm,
               &t[i].ora_partenza.ss,
               &t[i].ora_arrivo.hh,
               &t[i].ora_arrivo.mm,
               &t[i].ora_arrivo.ss,
               &t[i].ritardo);

    fclose(fp);
    return t;
}

comando_e leggiComando(char str[])
{
    char possible_command[][MAX_LEN] = {
        "date",
        "partenza",
        "capolinea",
        "ritardo",
        "ritardo_tot",
        "ordina",
        "codice_tratta",
        "ricerca_partenza",
        "ricerca_binaria_partenza",
        "fine"};
    int i;

    for (i = 0; i < sizeof(possible_command) / sizeof(possible_command[0]); i++)
        if (strcmp(str, possible_command[i]) == 0)
            return i;
    return -1;
}
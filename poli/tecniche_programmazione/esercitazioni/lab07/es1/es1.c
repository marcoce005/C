#include <stdio.h>
#include <string.h>
#include <ctype.h>
// #include <time.h>

#define LOGS_FILE "./log.txt"
#define MAX_ROW 1000
#define MAX_STR 30 + 1

typedef struct Log
{
    char route_ID[MAX_STR],
        departure[MAX_STR],
        destination[MAX_STR],
        date[MAX_STR],
        time_start[MAX_STR],
        time_end[MAX_STR];
    int delay;
} log;

typedef enum
{
    r_date,
    r_partenza,
    r_capolinea,
    r_ritardo,
    r_ritardo_tot,
    r_fine
} command_e;

int read_logs(FILE *in, log l[], int *len);
command_e read_command(char str[], char keys[][MAX_STR], int len);
void to_lower(char str[]);
void date_and_ritardo(log logs[], int len, command_e type, char str[]);
void partenza_and_capolinea(log logs[], int len, command_e type, char str[]);
void ritardo_tot(log logs[], int len, char str[]);
int between_date(char d1[], char d2[], char d3[]); // check is d3 is between d1 and d2
// long int date_2_int(char str[]);         // convert to unix time

int main(void)
{
    FILE *in;
    log logs[MAX_ROW];
    int ans,
        len,
        exit = 0;
    char command[MAX_STR],
        others_info[50],
        keys_word[][MAX_STR] = {"date", "partenza", "capolinea", "ritardo", "ritardo_tot", "fine"};

    in = fopen(LOGS_FILE, "r");

    ans = read_logs(in, logs, &len);

    if (ans < 0)
    {
        fclose(in);
        return -1;
    }

    // printf("%d\n", between_date("2018/10/10", "2018/10/20", "2018/10/10"));

    while (exit == 0)
    {
        printf("\nCommand [format date = yyyy/mm/dd] :\n");
        printf(" - 'date' <data1> <data2>\n");
        printf(" - 'partenza' <fermata>\n");
        printf(" - 'capolinea' <fermata>\n");
        printf(" - 'ritardo' <data1> <data2>\n");
        printf(" - 'ritardo_tot' <ID corsa>\n");
        printf(" - 'fine'\n--> ");
        scanf("%s", command);

        to_lower(command);
        if (read_command(command, keys_word, sizeof(keys_word) / sizeof(keys_word[0])) == r_fine)
            break;

        fgets(others_info, sizeof(others_info), stdin);
        to_lower(others_info);

        switch (read_command(command, keys_word, sizeof(keys_word) / sizeof(keys_word[0])))
        {
        case r_date:
            date_and_ritardo(logs, len, r_date, others_info);
            break;

        case r_partenza:
            partenza_and_capolinea(logs, len, r_partenza, others_info);
            break;

        case r_capolinea:
            partenza_and_capolinea(logs, len, r_capolinea, others_info);
            break;

        case r_ritardo:
            date_and_ritardo(logs, len, r_ritardo, others_info);
            break;

        case r_ritardo_tot:
            ritardo_tot(logs, len, others_info);
            break;

        default:
            printf("\nCommand not found");
            break;
        }
    }

    fclose(in);

    return 0;
}

void ritardo_tot(log logs[], int len, char str[])
{
    char ID[MAX_ROW];
    int tot = 0, found = 0;

    if (sscanf(str, "%s", ID) != 1)
    {
        printf("\nError ritardo_tot need a route ID after the command");
        return;
    }

    for (int i = 0; i < len; i++)
        if (strcmp(logs[i].route_ID, ID) == 0)
        {
            found = 1;
            tot += logs[i].delay;
        }
    if (found)
        printf("\nThe delay collect by the %s is %d minutes", ID, tot);
    else
        printf("\nThe %s was not found in the logs", ID);
}

void partenza_and_capolinea(log logs[], int len, command_e type, char str[])
{
    char station[MAX_STR];

    if (sscanf(str, "%s", station) != 1)
    {
        printf("\nError partenza or capolinea need a station after the command");
        return;
    }

    printf("\n%s\n", station);

    for (int i = 0; i < len; i++)
        if ((type == r_partenza && strcmp(station, logs[i].departure) == 0) || (type == r_capolinea && strcmp(station, logs[i].destination) == 0))
            printf("%s %s %s %s %s %s %d\n",
                   logs[i].route_ID,
                   logs[i].departure,
                   logs[i].destination,
                   logs[i].date,
                   logs[i].time_start,
                   logs[i].time_end,
                   logs[i].delay);
}

void date_and_ritardo(log logs[], int len, command_e type, char str[])
{
    char date1[MAX_STR], date2[MAX_STR];
    // long int date1_int, date2_int, confront;

    if (sscanf(str, "%s %s", date1, date2) != 2)
    {
        printf("\nError date or ritardo need two date after the command");
        return;
    }

    // date1_int = date_2_int(date1);               // another way using unix time
    // date2_int = date_2_int(date2);

    // if (date1_int > date2_int)
    // {
    //     printf("Date2 have to be greater than date1");
    //     return;
    // }

    for (int i = 0; i < len; i++)
    {
        // confront = date_2_int(logs[i].date);
        if (between_date(date1, date2, logs[i].date)) // if (confront >= date1_int && confront <= date2_int)
            if (logs[i].delay > 0 || type == r_date)
                printf("%s %s %s %s %s %s %d\n",
                       logs[i].route_ID,
                       logs[i].departure,
                       logs[i].destination,
                       logs[i].date,
                       logs[i].time_start,
                       logs[i].time_end,
                       logs[i].delay);
    }
}

int between_date(char d1[], char d2[], char d3[])
{
    int y[3], m[3], d[3];

    sscanf(d1, "%d/%d/%d", &y[0], &m[0], &d[0]);
    sscanf(d2, "%d/%d/%d", &y[1], &m[1], &d[1]);
    sscanf(d3, "%d/%d/%d", &y[2], &m[2], &d[2]);

    if ((y[2] > y[0] && y[2] < y[1]) || (y[2] > y[1] && y[2] < y[0]))
        return 1;
    else if (y[0] == y[2] || y[1] == y[2])
        if ((m[2] > m[0] && m[2] < m[1]) || (m[2] > m[1] && m[2] < m[0]))
            return 1;
        else if (m[2] == m[1] || m[2] == m[0])
            if ((d[2] >= d[0] && d[2] <= d[1]) || (d[2] >= d[1] && d[2] <= d[0]))
                return 1;
    return 0;
}

// long int date_2_int(char str[])              // convert to unix time
// {
//     int y, m, d;
//     struct tm tm = {0}; // Inizializza tutto a 0

//     sscanf(str, "%d/%d/%d", &y, &m, &d);

//     if (m <= 0 || m > 12 || d <= 0 || d > 31)
//     {
//         printf("\nInvalid date.");
//         return -1;
//     }

//     tm.tm_year = y;
//     tm.tm_mon = m;
//     tm.tm_mday = d;
//     // Aggiustamenti per struct tm
//     tm.tm_year -= 1900; // tm_year = anni dal 1900
//     tm.tm_mon -= 1;     // tm_mon = mesi [0-11]

//     return mktime(&tm);
// }

command_e read_command(char str[], char keys[][MAX_STR], int len)
{
    for (int i = 0; i < len; i++)
        if (strcmp(str, keys[i]) == 0)
            return i;
    return -1;
}

void to_lower(char str[])
{
    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int read_logs(FILE *in, log l[], int *len)
{
    if (in == NULL)
    {
        printf("\nFile Error.\nFile %s not found", LOGS_FILE);
        return -1;
    }

    fscanf(in, "%d", &(*len));

    if (*len < 0 || *len > MAX_ROW)
    {
        printf("\nParameter error.\nYou can only read 0 to 1000 lines of logs");
        return -1;
    }

    for (int i = 0; i < (*len); i++)
    {
        fscanf(in, "%s %s %s %s %s %s %d",
               l[i].route_ID,
               l[i].departure,
               l[i].destination,
               l[i].date,
               l[i].time_start,
               l[i].time_end,
               &l[i].delay);
        to_lower(l[i].route_ID);
        to_lower(l[i].departure);
        to_lower(l[i].destination);
    }
    return 0;
}
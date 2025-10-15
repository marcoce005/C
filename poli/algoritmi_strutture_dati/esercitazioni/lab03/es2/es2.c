#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 50 + 1
#define CODICE_LEN 5 + 1

typedef enum
{               // command --> <string>
    r_aggiungi, //         --> "aggiungi"
    r_cerca,    //         --> "cerca"
    r_cancella, //         --> "cancella"
    r_codice,   //         --> "codice"
    r_date,     //         --> "date"
    r_stampa,   //         --> "stampa"
    r_fine      //         --> "fine"
} comando_e;

typedef struct Date
{
    int dd, mm, yyyy;
} date;

typedef struct Item
{
    char codice[CODICE_LEN],
        nome[MAX_LEN],
        cognome[MAX_LEN],
        via[MAX_LEN],
        citta[MAX_LEN];
    int cap;
    date data_di_nascita;
} item;

typedef struct Node *link;
typedef struct Node
{
    item val;
    link next;
} node;

link new_node(item val, link next);
link insert_in_order(link h, item val);
link aggiungi_file(link h);
link aggiungi_keyboard(link h);
comando_e convert_command(char str[]); // -1 --> not found
void str_2_lower(char *s);
link deal_command(comando_e r_command, link head);

int key_less(date d0, date d1); // is d0 < d1 ?

int main(void)
{
    link head = NULL;
    char command[MAX_LEN];
    comando_e r_comando;

    while (1) // menu
    {
        printf("\nCommand:\n");
        printf(" - 'aggiungi'\n");
        printf(" - 'cerca'\n");
        printf(" - 'cancella'\n");
        printf(" - 'stampa'\n");
        printf(" - 'fine'\n--> ");
        scanf("%s", command);

        r_comando = convert_command(command);

        if (r_comando == r_fine)
            break;
        head = deal_command(r_comando, head);
    }

    return 0;
}

link aggiungi_file(link h) {}

link aggiungi_keyboard(link h)
{
    item val;
    char birth[10 + 1];

    getchar(); // clean the stdin file

    printf("Enter your ID code [AXXXX, X are numbers]:\n---> ");
    fgets(val.codice, CODICE_LEN, stdin);
    val.codice[strlen(val.codice) - 1] = '\0'; // remove '\n' at the end

    getchar();

    printf("Enter your name:\n---> ");
    fgets(val.nome, MAX_LEN, stdin);
    val.nome[strlen(val.nome) - 1] = '\0'; // remove '\n' at the end

    printf("Enter your surname:\n---> ");
    fgets(val.cognome, MAX_LEN, stdin);
    val.cognome[strlen(val.cognome) - 1] = '\0'; // remove '\n' at the end

    printf("Enter your date of birth [format dd/mm/yyyy]:\n---> ");
    scanf("%s", birth);
    sscanf(birth, "%02d/%02d/%04d", &val.data_di_nascita.dd, &val.data_di_nascita.mm, &val.data_di_nascita.yyyy);

    getchar();

    printf("What is you address:\n---> ");
    fgets(val.via, MAX_LEN, stdin);
    val.via[strlen(val.via) - 1] = '\0'; // remove '\n' at the end

    printf("Which city do you live:\n---> ");
    fgets(val.citta, MAX_LEN, stdin);
    val.citta[strlen(val.citta) - 1] = '\0'; // remove '\n' at the end

    printf("Enter the CAP [only numbers]:\n---> ");
    scanf(" %d", &val.cap);

    return insert_in_order(h, val);
}

int key_less(date d0, date d1)
{
    int n0 = d0.yyyy * 365 + d0.mm * 31 + d0.dd,
        n1 = d1.yyyy * 365 + d1.mm * 31 + d1.dd;
    return n0 < n1;
}

link insert_in_order(link h, item val)
{
    link x, p;

    if (h == NULL || key_less(val.data_di_nascita, h->val.data_di_nascita))
        return new_node(val, h);

    for (x = h->next, p = h; x != NULL && key_less(val.data_di_nascita, x->val.data_di_nascita); p = x, x = x->next)
        p->next = new_node(val, x);
    return h;
}

link new_node(item val, link next)
{
    link x = malloc(sizeof(*x));
    if (x == NULL)
    {
        printf("\nAllocation Error");
        exit(1);
    }

    x->val = val;
    x->next = next;
    return x;
}

link deal_command(comando_e r_command, link head)
{
    int file;
    switch (r_command)
    {
    case r_aggiungi:
        printf("Select the input method:\n - 0 --> by keybord insert 1 element\n - 1 --> using a file\n--> ");
        scanf("%d", &file);

        head = file ? aggiungi_file(head) : aggiungi_keyboard(head);

        break;

    default:
        printf("\nCommand not found.");
        break;
    }
    return head;
}

void str_2_lower(char *s)
{
    for (; *s != '\0'; s++)
        *s = tolower(*s);
}

comando_e convert_command(char str[])
{
    char possible[][MAX_LEN] = {
        "aggiungi",
        "cerca",
        "cancella",
        "codice",
        "date",
        "stampa",
        "fine"};
    int i;

    str_2_lower(str);

    for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++)
        if (strcmp(str, possible[i]) == 0)
            return i;
    return -1;
}
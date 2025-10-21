#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 50 + 1
#define CODICE_LEN 5 + 1
#define FILE_OUT_PATH "output.txt"

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
link deal_command(comando_e r_command, link head);
comando_e convert_command(char str[]); // -1 --> not found
void str_2_lower(char *s);
void print_list(link h, FILE *fp);
void wrapper_print_list(link h, int file);
void print_item(item val, FILE *fp);
void deal_cancella(link *hp, comando_e method);
void free_list(link h);
int key_less(date d0, date d1);              // is d0 < d1 ?
int between_date(date d0, date d1, date d2); // d2 is between d0 and d1?
item search_by_ID(link h, char id[]);
item void_item();
item canc_codice(link *hp, char id[]);
item canc_date(link *hp, date d0, date d1, link *pprev);

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

        printf("\n\n");
        wrapper_print_list(head, 0);
    }

    free_list(head);
    return 0;
}

void free_list(link h)
{
    if (h == NULL)
        return;
    free_list(h->next);
    free(h);
}

int between_date(date d0, date d1, date d2)
{
    return (key_less(d0, d2) && key_less(d2, d1)) || (key_less(d1, d2) && key_less(d2, d0));
}

item canc_date(link *hp, date d0, date d1, link *pprev)
{
    item tmp = void_item();
    link *xp, t;

    for (xp = hp; *xp != NULL; xp = &((*xp)->next))
    {
        if (between_date(d0, d1, (*xp)->val.data_di_nascita))
        {
            t = *xp;
            *xp = (*xp)->next;
            tmp = t->val;
            free(t);
            break;
        }
        else
            *pprev = *xp;
    }
    return tmp;
}

item canc_codice(link *hp, char id[])
{
    item tmp = void_item();
    link *xp, t;

    for (xp = hp; *xp != NULL; xp = &((*xp)->next))
    {
        if (strcmp((*xp)->val.codice, id) == 0)
        {
            t = *xp;
            *xp = (*xp)->next;
            tmp = t->val;
            free(t);
            break;
        }
    }
    return tmp;
}

void deal_cancella(link *hp, comando_e method)
{
    char str[MAX_LEN];
    date d0, d1;
    item val;
    link prev;
    switch (method)
    {
    case r_codice:
        printf("Enter the the ID code [AXXXX X are number] you want delete:\n--> ");
        scanf("%s", str);

        printf("\nDeleted informations:\n");
        print_item(canc_codice(hp, str), stdout);
        break;

    case r_date:
        printf("Enter the date between you want to delete:\n--> ");
        getchar();
        fgets(str, sizeof(str), stdin);
        sscanf(str, "%d/%d/%d %d/%d/%d",
               &d0.dd,
               &d0.mm,
               &d0.yyyy,
               &d1.dd,
               &d1.mm,
               &d1.yyyy);

        val = canc_date(hp, d0, d1, &prev);
        print_item(val, stdout);

        while (val.cap != -1)
        {
            val = canc_date(&prev, d0, d1, &prev);
            if (val.cap != -1)
                print_item(val, stdout);
        }
        break;

    default:
        break;
    }
}

item void_item()
{
    item x;
    x.cap = -1;
    return x;
}

item search_by_ID(link h, char id[])
{
    if (h == NULL)
        return void_item();

    if (strcmp(h->val.codice, id) == 0)
        return h->val;

    return search_by_ID(h->next, id);
}

void print_item(item val, FILE *fp)
{
    if (val.cap == -1)
        fprintf(fp, "Void Item\n");
    else
        fprintf(fp, "%s | %s | %s | %02d/%02d/%04d | %s | %s | %05d\n",
                val.codice,
                val.nome,
                val.cognome,
                val.data_di_nascita.dd,
                val.data_di_nascita.mm,
                val.data_di_nascita.yyyy,
                val.via,
                val.citta,
                val.cap);
}

void print_list(link h, FILE *fp)
{
    if (h == NULL)
        return;
    print_item(h->val, fp);
    print_list(h->next, fp);
}

void wrapper_print_list(link h, int file)
{
    if (file)
    {
        FILE *fp = fopen(FILE_OUT_PATH, "a");

        if (fp == NULL)
        {
            printf("\nFile error.");
            exit(1);
        }

        print_list(h, fp);
        fprintf(fp, "\n\n");

        fclose(fp);
    }
    print_list(h, stdout);
}

link aggiungi_file(link h)
{
    FILE *fp;
    char file_path[MAX_LEN];
    item val;

    printf("Enter file path:\n--> ");
    scanf("%s", file_path);

    fp = fopen(file_path, "r");

    if (fp == NULL)
    {
        printf("\nFile Error");
        exit(1);
    }

    while (fscanf(fp, "%s %s %s %d/%d/%d %s %s %d",
                  val.codice,
                  val.nome,
                  val.cognome,
                  &val.data_di_nascita.dd,
                  &val.data_di_nascita.mm,
                  &val.data_di_nascita.yyyy,
                  val.via,
                  val.citta,
                  &val.cap) == 9)
    {
        h = insert_in_order(h, val);
    }

    fclose(fp);
    return h;
}

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
    return n0 <= n1;
}

link insert_in_order(link h, item val)
{
    link x, p;

    if (h == NULL || key_less(val.data_di_nascita, h->val.data_di_nascita))
        return new_node(val, h);

    for (x = h->next, p = h; x != NULL && !key_less(val.data_di_nascita, x->val.data_di_nascita); p = x, x = x->next)
        ;
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
    char str[MAX_LEN];
    item val;
    comando_e method;
    switch (r_command)
    {
    case r_aggiungi:
        printf("Select the input method:\n - 0 --> by keybord insert 1 element\n - 1 --> using a file\n--> ");
        scanf("%d", &file);

        head = file ? aggiungi_file(head) : aggiungi_keyboard(head);
        break;

    case r_cerca:
        printf("Enter the the ID code [AXXXX X are number] you want search:\n--> ");
        scanf("%s", str);

        val = search_by_ID(head, str);
        if (val.cap == -1)
            printf("\nItem not found");
        else
            print_item(val, stdout);
        break;

    case r_stampa:
        wrapper_print_list(head, 1);
        break;

    case r_cancella:
        printf("Enter the deleting method:\n - 'codice <AXXXX>'\n - 'date' <date0> <date1>\n--> ");
        scanf("%s", str);
        method = convert_command(str);
        deal_cancella(&head, method);
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
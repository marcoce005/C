#include <stdio.h>
#include <ctype.h>

#define FILE_PATH "./input.txt"

#define NUMBER_ERROR "Error during the reading of the number (line"
#define OPERATOR_ERROR "Error during the reading of the operator (line"
#define BRACKET_ERROR "Error wrong sequence of brackets (line"

int check_oper(FILE *in);
void skip_line(FILE *in, int *l, int *op, int *pre);
void change_prev(char curr, int *pre, int *op);

int main(void)
{
    FILE *in;

    in = fopen(FILE_PATH, "r");

    printf(check_oper(in) < 0 ? "\nSomething went wrong\nPlease check file's path.\n" : "\nFile has been analized.\n");

    fclose(in);

    return 0;
}

void skip_line(FILE *in, int *l, int *op, int *pre)
{
    char waste[50];
    fgets(waste, 50, in); // get the rest of the line
    (*l)++;               // increment line counter
    *op = 0;              // set open brackets to 0
    *pre = -1;            // set to for a new line
}

void change_prev(char curr, int *pre, int *op)
{
    /*
        if it's a number [n] => prev = 0
        if it's ( => prev = 1
        if it's ) => prev = 2
        if it's an opetator [+ - * / %] => prev = 3
    */

    if (isdigit(curr))
        *pre = 0;
    else
        switch (curr)
        {
        case '(':
            *pre = 1;
            (*op)++;
            break;

        case ')':
            *pre = 2;
            (*op)--;
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            *pre = 3;
            break;
        }
}

int check_oper(FILE *in)
{
    if (in == NULL)
        return -1;

    char curr, previus_char;
    int line = 0, open = 0, prev = -1;

    while (fscanf(in, "%c", &curr) == 1)
    {
        if ((curr == '(' || isdigit(curr)) && (prev == 2))
        {
            isdigit(curr) ? printf("%s %d)\n", NUMBER_ERROR, line + 1) : printf("%s %d)\n", OPERATOR_ERROR, line + 1);
            skip_line(in, &line, &open, &prev);
        }
        else if (curr == ')' && (prev == -1 && prev == 3))
        {
            printf("%s %d)\n", OPERATOR_ERROR, line + 1);
            skip_line(in, &line, &open, &prev);
        }
        else if ((curr == '+' || curr == '-' || curr == '*' || curr == '/' || curr == '%') && (prev != 0 && prev != 2))
        {
            printf("%s %d)\n", OPERATOR_ERROR, line + 1);
            skip_line(in, &line, &open, &prev);
        }
        else if (prev == 0 && previus_char == ' ' && isdigit(curr))
        {
            printf("%s %d)\n", NUMBER_ERROR, line + 1);
            skip_line(in, &line, &open, &prev);
        }
        else
        {
            change_prev(curr, &prev, &open);

            if (curr == '\n')
            {
                if (open != 0)
                    printf("%s %d)\n", BRACKET_ERROR, line + 1);

                if (prev == 3)
                    printf("%s %d)\n", OPERATOR_ERROR, line + 1);

                prev = -1;
                open = 0;
                line++;
            }
        }
        previus_char = curr;
    }

    if (prev == 3)
        printf("%s %d)\n", OPERATOR_ERROR, line + 1);
    if (open != 0)
        printf("%s %d)\n", BRACKET_ERROR, line + 1);

    return 0;
}
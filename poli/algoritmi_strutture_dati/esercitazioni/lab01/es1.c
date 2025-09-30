#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *cercaRegexp(char *src, char *regexp); // NULL --> not found
char *copy_sub(char *regex);

int main()
{
    char p[][20] = {"ciro", "noto", "Foto"}, regex[] = "\\aoto", *found;
    int i;

    for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++)
    {
        found = cercaRegexp(p[i], regex);
        printf("%s\n", found == NULL ? "NULL" : found);
    }

    return 0;
}

char *copy_sub(char *regex)
{
    int i;
    for (i = 0; regex[i] != ']'; i++)
        ;
    regex[i] = '\0';
    char *sub = (char *)malloc(i * sizeof(char));
    strcpy(sub, regex);
    return sub;
}

char *cercaRegexp(char *src, char *regexp)
{
    int i, special = 0, skip = 0;
    char *sub_str;

    for (i = 0; i < strlen(regexp) && skip != 1; i++)
    {
        printf("(%c, %c) --> ", regexp[i], src[i - special]);
        printf("\ni = %d\tspec = %d\n", i, special);

        switch (regexp[i])
        {
        case '.':
            break;

        case '[':
            sub_str = copy_sub(regexp + 1);
            if ((regexp[i + 1] == '^' && strchr(sub_str, src[i - special]) != NULL) || strchr(sub_str, src[i - special]) == NULL)
                skip = 1;
            special += strlen(sub_str) + (regexp[i + 1] == '^' ? 1 : 0);
            i += special;
            free(sub_str);
            break;

        case '\\':
            if ((regexp[i + 1] == 'a' && !islower(src[i - special])) || (regexp[i + 1] == 'A' && !isupper(src[i - special])))
                skip = 1;
            i++;
            special++;
            break;

        default:
            if (src[i - special] != regexp[i])
                skip = 1;
            break;
        }
    }

    printf("\n");

    if (strlen(src + 1) - strlen(regexp) < 0 || *(src + 1) == '\0')
        return NULL;
    if (skip)
        return cercaRegexp(src + 1, regexp);
    return src;
}
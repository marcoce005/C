#include <stdlib.h>

#include "date_time.h"

datetime_t datetime_from_file(FILE *fp_in)
{
    int YYYY,
        MM,
        DD,
        hh,
        mm;

    fscanf(fp_in, "%d/%d/%d %d:%d", &YYYY, &MM, &DD, &hh, &mm);
    datetime_t x = {YYYY, MM, DD, hh, mm};
    return x;
}

datetime_t datetime_from_str(char *str) {
    datetime_t x;
    sscanf(str, "%d/%d/%d %d:%d", &x.YYYY, &x.MM, &x.DD, &x.hh, &x.mm);
    return x;
}

int datetime_compare(datetime_t a, datetime_t b)
{
    if (a.YYYY != b.YYYY)
        return a.YYYY - b.YYYY;
    if (a.MM != b.MM)
        return a.MM - b.MM;
    if (a.DD != b.DD)
        return a.DD - b.DD;
    if (a.hh != b.hh)
        return a.hh - b.hh;
    if (a.mm != b.mm)
        return a.mm - b.mm;
    return 0;
}

int date_compare(datetime_t a, datetime_t b)
{
    if (a.YYYY != b.YYYY)
        return a.YYYY - b.YYYY;
    if (a.MM != b.MM)
        return a.MM - b.MM;
    if (a.DD != b.DD)
        return a.DD - b.DD;
    return 0;
}

void datetime_print(FILE *fp_out, datetime_t date)
{
    fprintf(fp_out, "%04d/%02d/%02d %02d:%02d",
            date.YYYY,
            date.MM,
            date.DD,
            date.hh,
            date.mm);
}
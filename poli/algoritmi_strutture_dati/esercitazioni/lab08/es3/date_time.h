#ifndef _DATETIME
#define _DATETIME

#include <stdio.h>

typedef struct
{
    int YYYY,
        MM,
        DD,
        hh,
        mm;
} datetime_t;

/**
 * @brief Get the first date in the open file.
 * @param fp_in
 * @return * datetime_t
 */
datetime_t init_datetime(FILE *fp_in);

/**
 * @brief
 * 0 --> a == b
 *
 * positive --> a > b
 *
 * negative --> a < b
 */
int datetime_compare(datetime_t a, datetime_t b);

/**
 * @brief compare only date
 *
 * 0 --> a == b
 *
 * positive --> a > b
 *
 * negative --> a < b
 */
int date_compare(datetime_t a, datetime_t b);

void datetime_print(FILE *fp_out, datetime_t date);

#endif
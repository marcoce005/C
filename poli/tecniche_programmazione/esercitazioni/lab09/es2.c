#include <stdio.h>
#include <string.h>

struct IEEE
{
    int sgn, exp, mantissa;
} format;

void stampaCodifica(void *p, int size, int bigEndian);
int check_bigEndian();
void byte_2_bit(unsigned char byte, char *bits, int start, int bigEndian);

int main(void)
{
    float af;
    double ad;
    int bigEndian = check_bigEndian();

    format.sgn = 1;

    printf("\nThe system is:\t", bigEndian ? "BigEndian" : "LittleEndian");

    printf("\nfloat --> %d byte\t%d bit", sizeof(af), sizeof(af) * 8);
    printf("\ndouble --> %d byte\t%d bit", sizeof(ad), sizeof(ad) * 8);

    printf("\n\nInsert a  number:\t");
    scanf("%f", &af);
    ad = (double)af;

    check_bigEndian();

    printf("\n\t\t\tFloat");
    stampaCodifica((void *)&af, sizeof(af), bigEndian);
    printf("\n\n\t\t\tDouble");
    stampaCodifica((void *)&ad, sizeof(ad), bigEndian);

    return 0;
}

void byte_2_bit(unsigned char byte, char *bits, int start, int bigEndian)
{
    unsigned char mask = 0x01;
    for (int i = start; i < start + 8; i++, mask = mask << 1)
        bits[i] = (byte & mask) ? '0' + 1 : '0' + 0;
}

void stampaCodifica(void *p, int size, int bigEndian)
{
    int i;
    unsigned char *pc = p;
    char bits[(size * 8) + 1];
    strcpy(bits, "");

    if (size == 4)
    {
        format.exp = 8;
        format.mantissa = 23;
    }
    else
    {
        format.exp = 11;
        format.mantissa = 52;
    }

    for (i = 0; i < size; i++)
        byte_2_bit(*(pc + i), bits, i * 8, bigEndian);

    if (bigEndian)
        for (i = 0; i < size * 8; i++)
        {
            if (i + 1 == format.sgn)
                printf("\nSign:\t\t");
            if (i + 1 == format.sgn + 1)
                printf("\nExponent:\t");
            if (i + 1 == format.sgn + format.exp + 1)
                printf("\nMantissa:\t");
            printf("%c", bits[i]);
        }
    else
        for (i = (size * 8) - 1; i >= 0; i--)
        {
            if (i == (size * 8) - format.sgn)
                printf("\nSign:\t\t");
            if (i == (size * 8) - (format.sgn + 1))
                printf("\nExponent:\t");
            if (i == (size * 8) - (format.sgn + format.exp + 1))
                printf("\nMantissa:\t");
            printf("%c", bits[i]);
        }
}

int check_bigEndian()
{
    int i = 1;
    unsigned char *c = (char *)&i;
    return *c == 0;
}
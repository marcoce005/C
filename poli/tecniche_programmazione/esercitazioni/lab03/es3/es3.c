#include <stdio.h>

#define FILE_PATH "./input2.txt"

void somma_tempi(int *tot, int *count);
int convert_2_seconds(int h, int m, int s);
void seconds_2_format(int second, char str[10]);

void read_file(int *count, int T1[3], int T2[3]);
void sommaTempi(int T1[3], int T2[3]); // sum and put the output in T1
void dividiTempo(int T[3], int n, char str[10]);

int main(void)
{
    int tot_seconds = 0, count_temp = 0, T1[3] = {0, 0, 0}, T2[3];
    char avg_time[10];

    // read_file(&count_temp, T1, T2);
    somma_tempi(&tot_seconds, &count_temp);

    // dividiTempo(T1, count_temp, avg_time);

    printf("\nMedia dei tempi in secondi:\t%.1f s\n", (float)tot_seconds / count_temp);
    seconds_2_format((float)tot_seconds / count_temp, avg_time);

    printf("\nMedia dei tempi [hh:mm:ss]:\t%s\n", avg_time);

    return 0;
}

int convert_2_seconds(int h, int m, int s) { return h * 3600 + m * 60 + s; }

void somma_tempi(int *tot, int *count)
{
    FILE *file;
    file = fopen(FILE_PATH, "r");

    char str[10];
    int h, m, s;

    while (!feof(file))
    {
        fscanf(file, "%s", str);
        sscanf(str, "%d:%d:%d", &h, &m, &s);
        if (!feof(file))
        {
            (*tot) += convert_2_seconds(h, m, s);
            (*count)++;
        }
    }
    fclose(file);
}

void seconds_2_format(int second, char str[10])
{
    int h, m;

    h = second / 3600;
    second -= h * 3600;
    m = second / 60;
    second -= m * 60;

    sprintf(str, "%d:%d:%d", h, m, second);
}

void dividiTempo(int T[3], int n, char str[10])
{
    float h = (float)T[0] / n,
          m = (float)T[1] / n,
          s = (float)T[2] / n;

    T[0] = (int)h;
    T[1] = (int)m;
    T[2] = (int)s;

    m += (h - (int)h) * 60;
    if (m > 60)
        T[0]++;
    T[1] = (int)m % 60;

    s += (m - (int)m) * 60;
    if (s > 60)
        T[1]++;
    T[2] = (int)s % 60;

    sprintf(str, "%d:%d:%d", T[0], T[1], T[2]);
}

void sommaTempi(int T1[3], int T2[3])
{
    T1[0] = (T1[0] + T2[0]);
    T1[2] = (T1[2] + T2[2]);
    T1[1] = (T1[1] + T2[1]);
}

void read_file(int *count, int T1[3], int T2[3])
{
    FILE *file;
    file = fopen(FILE_PATH, "r");

    char str[10];
    int h, m, s;

    while (!feof(file))
    {
        fscanf(file, "%s", str);
        sscanf(str, "%d:%d:%d", &h, &m, &s);
        if (!feof(file))
        {
            T2[0] = h;
            T2[1] = m;
            T2[2] = s;
            sommaTempi(T1, T2);
            (*count)++;
        }
    }
}
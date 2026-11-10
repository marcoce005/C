#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void father(int fd_in[2], int fd_out[2]);
void child(int fd_in[2], int fd_out[2]);

int main(void)
{
    pid_t pid;
    int fd_f2c[2], fd_c2f[2];

    pipe(fd_c2f);
    pipe(fd_f2c);

    if ((pid = fork()))
        father(fd_c2f, fd_f2c);
    else
        child(fd_f2c, fd_c2f);

    return 0;
}

void father(int fd_in[2], int fd_out[2])
{
    close(fd_in[1]);
    close(fd_out[0]);

    char x = 'x';
    while (1)
    {
        fprintf(stdout, "I'm the father (PID = %x)\n", getpid());

        write(fd_out[1], &x, sizeof(x));

        read(fd_in[0], (char *)0, sizeof(char));
    }
}

void child(int fd_in[2], int fd_out[2])
{
    close(fd_in[1]);
    close(fd_out[0]);

    char x = 'x';
    while (1)
    {
        read(fd_in[0], (char *)0, sizeof(char));

        fprintf(stdout, "I'm the children (PID = %x)\n", getpid());

        write(fd_out[1], &x, sizeof(x));
    }
}
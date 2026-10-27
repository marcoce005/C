#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
  int i = 0;

  setbuf(stdout,0);
  while (i<=2 && fork()){
    if (!fork()) {
      fprintf (stdout, "Running Exec ...");
      execlp ("echo", "echo", "i*i", (char *) 0);
    }
    i++;
    fprintf (stdout, "Running System ...");
    system ("echo i+i");
  }

  return (0);
} 
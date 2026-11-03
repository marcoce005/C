#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define N 12

int
main (
  int argc,
  char **argv
  )
{
  int i, fd, count, val;
  int vet[N] = {0, 10, 5, 20, 15, 30, 25, 40, 35, 50, 45, 60};

  if (argc != 2) {
    fprintf (stderr, "usage: %s fileName\n", argv[0]);
    exit (-1);
  }

  /*
   * Write File
   */

  fd = creat (argv[1], 0666);
  if (fd == -1) {
    fprintf(stderr, "Cannot create file %s\n", argv[1]);
    exit (-1); 
  }

  fprintf (stdout, "Reading: ");
  for (i=0; i<N; i++) {
    write (fd, &vet[i], sizeof (int));
    fprintf (stdout, "%2d ", vet[i]);
  }
  fprintf (stdout, "\n");

  close (fd);

  /*
   * Read File in Reverse Order
   */

  fd = open (argv[1], O_RDONLY);
  if (fd == -1){
    fprintf(stderr,"Cannot open file %s\n", argv[1]);
    exit(-1);
  }

  fprintf (stdout, "Reading: ");
  for (i=N-1; i>=0; i--) {
    lseek (fd, i*sizeof (int), SEEK_SET);
    count = read (fd, &val, sizeof (int));
    if (count <= 0){
      fprintf (stderr, "Error reading file\n");
      exit (-1);
    }
    fprintf (stdout, "%2d ", val);
  }
  fprintf (stdout, "\n");

  close (fd);

 return (0);
}

/* Daniel Bravo
 * 2018-04-18
 * CPSC 223C-01/02
 * Exam 3
 */

#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "filter.h"

void set_options(int argc, char *argv[]) {
  uflag = 0;
  lflag = 0;
  tflag = 0;
  int o;
  // opterr = 0;

  while ((o = getopt (argc, argv, "ult")) != -1) {
    switch (o) {
      case 'u':
        uflag = 1;
        break;
      case 'l':
        lflag = 1;
        break;
      case 't':
        tflag = 1;
        break;
      default:
        break;
        // printf("Specify one of '-u', '-l', or '-t'\n");
        // exit(EXIT_FAILURE);
    }
  }
  // printf ("uflag = %d, lflag = %d, tflag = %d\n", uflag, lflag, tflag);
}

int main(int argc, char *argv[])
{
  FILE *fp;

  set_options(argc, argv);

  if((uflag + lflag + tflag) > 1 || (uflag + lflag + tflag) == 0) {
    printf("Specify one of '-u', '-l', or '-t'.\n");
    return -2;
  }

  for (int i = optind; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if(uflag) {
      filter(fp, toupper);
    } else if(lflag) {
      filter(fp, tolower);
    } else if(tflag) {
      filter(fp, toggle);
    } else {
      printf("Specify one of '-u', '-l', or '-t'.\n");
    }

  }
}

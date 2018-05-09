/* Daniel Bravo
 * 2018-04-18
 * CPSC 223C-01/02
 * Exam 3
 */

#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "filter.h"

int toggle(int i)
{
  return islower(i) ? toupper(i) : tolower(i);
}

void filter(FILE *fp, int (*function)(int))
{
  assert(fp != NULL);

  char c;
  while((c = fgetc(fp)) != EOF) {
    printf("%c", function(c));
  }
}

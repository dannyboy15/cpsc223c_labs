/* Daniel Bravo
 * 2018-04-18
 * CPSC 223C-01/02
 * Exam 3
 */

#ifndef FILTER_H
#define FILTER_H

#define NUM_FILTERS 3
#define FILTER_NAME_LEN 8

int uflag;
int lflag;
int tflag;

int toggle(int i);
void filter(FILE *fp, int (*function)(int));

#endif

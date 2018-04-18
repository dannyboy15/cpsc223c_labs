/* Daniel Bravo
 * 2018-04-11
 * Lab 8
 */

#ifndef COMMANDS_H
#define COMMANDS_H

#include "operations.h"

int dflag;

struct statement_list *program;
struct statement *current;

void do_step(void);
void do_continue(void);
void do_print(void);
void do_list(void);

#endif

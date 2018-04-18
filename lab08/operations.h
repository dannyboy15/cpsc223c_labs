/* Daniel Bravo
 * 2018-04-11
 * Lab 8
 */

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdint.h>
#include "bstrlib.h"

int vflag;
uint8_t byte;

struct statement {
    bstring operation;
    unsigned int value;
    unsigned int lineNum;

    struct statement * next;
};

struct statement_list {
    struct statement * head;
    struct statement * tail;
    int statement_count;
};

void execute_statement(struct statement * stmt);
struct statement_list * create_program(void);
void add_statement(struct statement_list * prog, bstring o, unsigned int v);
void print_statement(struct statement * stmt);
void delete_program(struct statement_list * prog);

#endif

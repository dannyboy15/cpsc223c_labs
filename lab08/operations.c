/* Daniel Bravo
 * 2018-04-11
 * Lab 8
 */

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "bstrlib.h"
#include "operations.h"

void execute_statement(struct statement * stmt)
{
    if (biseqcstr(stmt->operation, "set") == 1) {
        byte = stmt->value;
    } else if (biseqcstr(stmt->operation, "and") == 1) {
        byte = byte & stmt->value;
    } else if (biseqcstr(stmt->operation, "or") == 1) {
        byte = byte | stmt->value;
    } else if (biseqcstr(stmt->operation, "xor") == 1) {
        byte = byte ^ stmt->value;
    } else if (biseqcstr(stmt->operation, "shr") == 1) {
        byte = byte >> stmt->value;
    } else if (biseqcstr(stmt->operation, "shl") == 1) {
        byte = byte << stmt->value;
    } else {
        printf("Invalid command. Please try again.\n");
    }
}

struct statement_list * create_program(void)
{
    struct statement_list *s = malloc(sizeof(struct statement_list));
    if (s == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    s->head = NULL;
    s->tail = NULL;
    s->statement_count = 0;

    return s;
}

void add_statement(struct statement_list * prog, bstring o, unsigned int v)
{
    assert(prog != NULL);

    struct statement *s = malloc(sizeof(struct statement));
    if (s == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    s->operation = o;
    s->value = v;
    s->lineNum = prog->statement_count + 1;
    s->next = NULL;

    if (prog->head == NULL) {
        prog->head = s;
        prog->tail = s;
    } else {
        prog->tail->next = s;
        prog->tail = s;
    }

    prog->statement_count++;
}

void print_statement(struct statement * stmt)
{
    printf("%s %x => %x\n", stmt->operation->data, stmt->value, byte);
}

void delete_program(struct statement_list * prog)
{
    assert(prog != NULL);

    while(prog->statement_count > 0) {
        struct statement * tmp = prog->head;
        prog->head = prog->head->next;

        free(tmp);
        prog->statement_count--;
    }

    free(prog);
}

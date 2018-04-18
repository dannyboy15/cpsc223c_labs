/* Daniel Bravo
 * 2018-04-11
 * Lab 8
 */


#include <stdio.h>
#include <stdint.h>
#include "bstrlib.h"
#include "commands.h"

void do_step(void)
{
    if (current == NULL) {
        printf("You have reached the end of the program!\n");
        return;
    }

    execute_statement(current);
    if(vflag) {
        print_statement(current);
    }
    current = current->next;
}

void do_continue(void)
{
    if (current == NULL) {
        printf("You have reached the end of the program!\n");
        return;
    }

    while(current != NULL) {
        do_step();
        // do_print();
        // current = current->next;
    }
}

void do_print(void)
{
    printf("%x\n", byte);
}

void do_list(void)
{
    if(current == program->head) {
        printf(" %d %s %x\n", current->lineNum, current->operation->data, current->value);
        struct statement * next = current->next;
        printf(" %d %s %x\n", next->lineNum, next->operation->data, next->value);
    } else if(current == NULL && program->statement_count > 0) {
        struct statement * pprev = program->head;
        struct statement * prev = pprev->next;
        while(prev->next != current) {
            pprev = prev;
            prev = prev->next;
        }

        printf(" %d %s %x\n", pprev->lineNum, pprev->operation->data, pprev->value);
        printf(" %d %s %x\n", prev->lineNum, prev->operation->data, prev->value);
    } else if(current == NULL) {
        return;
    } else{
        struct statement * prev = program->head;
        while(prev->next != current) {
            prev = prev->next;
        }
        struct statement * next = current->next;

        printf(" %d %s %x\n", prev->lineNum, prev->operation->data, prev->value);
        printf(" %d %s %x\n", current->lineNum, current->operation->data, current->value);
        printf(" %d %s %x\n", next->lineNum, next->operation->data, next->value);
    }
}

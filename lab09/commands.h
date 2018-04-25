/* Daniel Bravo
 * 2018-04-23
 * CPSC 223C-01/02
 * Lab 9
 */

#ifndef COMMANDS_H
#define COMMANDS_H

#define NUM_COMMANDS 4

#define COMMAND_NAME_LEN 7

struct command {
    char name[COMMAND_NAME_LEN];
    int (*function)(char *);
};

extern struct command commands[NUM_COMMANDS];

int name_cmp(const void * a, const void * b);
int office_cmp(const void * a, const void * b);
int phone_cmp(const void * a, const void * b);
int email_cmp(const void * a, const void * b);

int find_by_name(char *);
int find_by_office(char *);
int find_by_phone(char *);
int find_by_email(char *);

#endif

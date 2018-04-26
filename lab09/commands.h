/* Daniel Bravo
 * 2018-04-25
 * CPSC 223C-01/02
 * Lab 9
 */

#ifndef COMMANDS_H
#define COMMANDS_H

#define NUM_COMMANDS 4
#define COMMAND_NAME_LEN 7

#include "faculty.h"

struct command {
    char name[COMMAND_NAME_LEN];
    int (*function)(struct professor *, char *);
};

extern struct command commands[NUM_COMMANDS];

// Compare functions
int cmd_cmp (const void *, const void *);
int name_cmp(const void *, const void *);
int office_cmp(const void *, const void *);
int phone_cmp(const void *, const void *);
int email_cmp(const void *, const void *);

// Search functions
int find_by_name(struct professor *, char *);
int find_by_office(struct professor *, char *);
int find_by_phone(struct professor *, char *);
int find_by_email(struct professor *, char *);
int find_faculty(struct professor *, char *, char *);

#endif

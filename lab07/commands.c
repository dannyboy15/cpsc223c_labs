/* Daniel Bravo
 * 2018-04-04
 * CPSC 223C-01/02
 * Lab 7
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "commands.h"
#include "faculty.h"

struct command commands[NUM_COMMANDS] = {
    { "email",  find_by_email},
    { "name",   find_by_name },
    { "office", find_by_office },
    { "phone",  find_by_phone },
};

int name_cmp(const void * a, const void * b)
{
    return strcmp(((struct professor *)a)->name, ((struct professor *)b)->name);
}

int office_cmp(const void * a, const void * b)
{
    return strcmp(((struct professor *)a)->office, ((struct professor *)b)->office);
}

int phone_cmp(const void * a, const void * b)
{
    return strcmp(((struct professor *)a)->phone, ((struct professor *)b)->phone);
}

int email_cmp(const void * a, const void * b)
{
    return strcmp(((struct professor *)a)->email, ((struct professor *)b)->email);
}

int find_by_name(char *name)
{
    if (strlen(name) ==  0) {
        return -1;
    }

    qsort(faculty, NUM_FACULTY, sizeof(struct professor), name_cmp);

    struct professor p;
    strcpy(p.name, name);

    struct professor * prof = (struct professor *) bsearch(
        &p,
        faculty,
        NUM_FACULTY,
        sizeof(struct professor),
        name_cmp);

    if (prof) {
        return prof - faculty;
    } else {
        return -1;
    }
}

int find_by_office(char *office)
{
    if (strlen(office) ==  0) {
        return -1;
    }

    qsort(faculty, NUM_FACULTY, sizeof(struct professor), office_cmp);

    struct professor p;
    strcpy(p.office, office);

    struct professor * prof = (struct professor *) bsearch(
        &p,
        faculty,
        NUM_FACULTY,
        sizeof(struct professor),
        office_cmp);

    if (prof) {
        return prof - faculty;
    } else {
        return -1;
    }
}

int find_by_phone(char *phone)
{
    if (strlen(phone) ==  0) {
        return -1;
    }

    qsort(faculty, NUM_FACULTY, sizeof(struct professor), phone_cmp);

    struct professor p;
    strcpy(p.phone, phone);

    struct professor * prof = (struct professor *) bsearch(
        &p,
        faculty,
        NUM_FACULTY,
        sizeof(struct professor),
        phone_cmp);

    if (prof) {
        return prof - faculty;
    } else {
        return -1;
    }
}

int find_by_email(char *email)
{
    if (strlen(email) ==  0) {
        return -1;
    }

    qsort(faculty, NUM_FACULTY, sizeof(struct professor), email_cmp);

    struct professor p;
    strcpy(p.email, email);

    struct professor * prof = (struct professor *) bsearch(
        &p,
        faculty,
        NUM_FACULTY,
        sizeof(struct professor),
        email_cmp);

    if (prof) {
        return prof - faculty;
    } else {
        return -1;
    }
}


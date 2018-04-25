/* Daniel Bravo
 * 2018-04-25
 * CPSC 223C-01/02
 * Lab 9
 */

#ifndef FACULTY_H
#define FACULTY_H

#define NUM_FACULTY 16

#define FACULTY_NAME_LEN 30
#define FACULTY_OFFICE_LEN 7
#define FACULTY_PHONE_LEN 15
#define FACULTY_EMAIL_LEN 30

struct professor {
    char name[FACULTY_NAME_LEN];
    char office[FACULTY_OFFICE_LEN];
    char phone[FACULTY_PHONE_LEN];
    char email[FACULTY_EMAIL_LEN];
};

void print_professor(struct professor *p);

extern struct professor faculty[NUM_FACULTY];

#endif

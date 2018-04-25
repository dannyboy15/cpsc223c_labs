/* Daniel Bravo
 * 2018-04-25
 * CPSC 223C-01/02
 * Lab 9
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "commands.h"
#include "faculty.h"

#define MAX_RECORD_SIZE FACULTY_NAME_LEN + FACULTY_OFFICE_LEN + FACULTY_PHONE_LEN + FACULTY_EMAIL_LEN + 5

int make_bin(char c)
{
    // Declare function and filename variables
    int (*cmp_func)(const void *, const void *);
    char filename[11];

    // Set function and filename variables
    switch (c) {
        case 'n':
            cmp_func = name_cmp;
            strcpy(filename, "name.bin");
            break;

        case 'o':
            cmp_func = office_cmp;
            strcpy(filename, "office.bin");
            break;

        case 'p':
            cmp_func = phone_cmp;
            strcpy(filename, "phone.bin");
            break;

        case 'e':
            cmp_func = email_cmp;
            strcpy(filename, "email.bin");
            break;

        default:
            printf("%c is an invalid option", c);
            return -1;
    }

    // Open the file
    int fp = open(filename, O_WRONLY | O_CREAT, S_IRUSR);
    if (fp < 0) {
        return -2;
    }

    // Sort the array
    qsort(faculty, NUM_FACULTY, sizeof(struct professor), cmp_func);

    // Write it out
    write(fp, faculty, sizeof(faculty));

    // Close the file
    close(fp);

    return 1;
}


int main(int argc, char *argv[])
{
    if (argc > 1) {
        printf("Usage: %s\n", argv[0]);
        return EXIT_FAILURE;
    }

    make_bin('n');
    make_bin('o');
    make_bin('p');
    make_bin('e');

    return EXIT_SUCCESS;
}

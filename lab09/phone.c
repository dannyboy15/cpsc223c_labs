/* Daniel Bravo
 * 2018-04-23
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

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <file> <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if(strlen(argv[1]) < 5) {
        printf("Usage: %s <file> <string>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int fp = open(argv[1], O_RDONLY);
    if (fp < 0) {
        return EXIT_FAILURE;
    }

    char fn[6];
    for (unsigned int i = 0; i < (strlen(argv[1]) - 4); i++) {
        fn[i] = argv[1][i];
    }

    struct professor f[NUM_FACULTY];
    read(fp, f, sizeof(faculty));
    close(fp);

    int i = find_faculty(f, argv[2], fn);
    if (i < 0) {
        printf("No match.\n");
    } else {
        print_professor(&f[i]);
    }

    return EXIT_SUCCESS;
}

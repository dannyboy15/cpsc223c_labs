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
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fp = open(argv[1], O_RDONLY);
    if (fp < 0) {
        return EXIT_FAILURE;
    }

    struct professor f[NUM_FACULTY];
    read(fp, f, sizeof(faculty));

    for (int i = 0; i < NUM_FACULTY; i++) {
        print_professor(&f[i]);
        printf("\n");
    }

    close(fp);

    return EXIT_SUCCESS;
}

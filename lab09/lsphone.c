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

#define MAX_BUFFER_SIZE 1

int read_file(int fp)
{
    char buffer[MAX_BUFFER_SIZE];
    int bytes_read;

    while (1) {
        // Read from the file
        bytes_read = read(fp, buffer, MAX_BUFFER_SIZE);
        if(bytes_read < 0) {
            return -2;
        } else if (bytes_read == 0) {
            break;
        } else {
            // Print the contents that were read
            for(int i = 0; i < MAX_BUFFER_SIZE; i++) {
                printf("%c", buffer[i]);
            }
        }
    }
    printf("\n");

    return 1;
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <bin file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char filename[11];
    strcpy(filename, argv[1]);

    int fp = open(filename, O_RDONLY);
    if (fp < 0) {
        return EXIT_FAILURE;
    }

    read_file(fp);

    close(fp);

    return EXIT_SUCCESS;
}

/* Daniel Bravo
 * 2018-04-04
 * CPSC 223C-01/02
 * Lab 7
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "faculty.h"

int cmd_cmp (const void * a, const void * b)
{
    const struct command * ca = a;
    const struct command * cb = b;

    return strcmp(ca->name, cb->name);
}


int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: phonebook <command> <string>\n");
        return EXIT_FAILURE;
    }

    struct command c;
    strcpy(c.name, argv[1]);

    struct command * cmd = (struct command *) bsearch(
        &c,
        commands,
        NUM_COMMANDS,
        sizeof(struct command),
        cmd_cmp);

    if (cmd) {
        int i = cmd->function(argv[2]);

        if (i >= 0) {
            printf("%s\n%s\n%s\n%s\n",
                faculty[i].name,
                faculty[i].office,
                faculty[i].phone,
                faculty[i].email);
        } else {
            printf("No match.\n");
        }
    } else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

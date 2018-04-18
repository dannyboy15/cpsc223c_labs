/* Daniel Bravo
 * 2018-04-11
 * Lab 8
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "bstrlib.h"
#include "commands.h"
#include "operations.h"

int set_options(int argc, char *argv[]) {
    vflag = 0;
    dflag = 0;
    int o;
    opterr = 0;

    while ((o = getopt (argc, argv, "vd")) != -1) {
        switch (o) {
            case 'v':
                vflag = 1;
                break;
            case 'd':
                dflag = 1;
                break;
            case '?':
                if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else {
                    fprintf (stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);
                }
                return 1;
            default:
                return EXIT_FAILURE;
        }
    }
    // printf ("vflag = %d, dflag = %d\n", vflag, dflag);
    return 1;
}

void read_files(int index, int max, char *files[], struct statement_list *prog)
{
    FILE *fp;
    for (int i = index; i < max; i++) {
        // printf("Reading %s\n", argv[i]);
        fp = fopen(files[i], "r");
        if (fp != NULL) {
            // printf("real file\n");

            bstring op;
            while((op = bgets((bNgetc) fgetc, fp, '\n'))) {
                // bgets consumes the new line character ('\n') therefore replace it
                // with the null character ('\0') to accurately check equality
                bfindreplace(op, bfromcstr("\n"), bfromcstr("\0"), 0);
                struct bstrList *list = bsplit(op, ' ');

                // struct statement s;
                // s.operation = list->entry[0];
                // s.value = strtol((const char *)list->entry[1]->data, NULL, 16);
                // s.lineNum = lines++;

                add_statement(prog,
                    list->entry[0],
                    strtol((const char *)list->entry[1]->data, NULL, 16));

                // printf("%d %s %x\n", s.lineNum, s.operation->data, s.value);

                // printf("%s:%s\n", list->entry[0]->data, list->entry[1]->data);
                // execCommand(cmds, &currPos, &maxPos, cmd, &val);
            }
            fclose(fp);
        } else {
            printf("not a real file\n");
        }
    }
}

int main(int argc, char *argv[])
{
    byte = 0;
    program = create_program();

    set_options(argc, argv);

    read_files(optind, argc, argv, program);

    current = program->head;

    if(dflag) {
        bstring cmd;
        while((cmd = bgets((bNgetc) fgetc, stdin, '\n'))) {
            // bgets consumes the new line character ('\n') therefore replace it
            // with the null character ('\0') to accurately check equality
            bfindreplace(cmd, bfromcstr("\n"), bfromcstr("\0"), 0);

            // printf("%s\n", cmd->data);

            if (biseqcstr(cmd, "step") == 1) {
                do_step();
            } else if (biseqcstr(cmd, "continue") == 1) {
                do_continue();
            } else if (biseqcstr(cmd, "print") == 1) {
                do_print();
            } else if (biseqcstr(cmd, "list") == 1) {
                do_list();
            } else if (biseqcstr(cmd, "quit") == 1) {
                return EXIT_SUCCESS;
            } else {
                printf("Invalid command. Please try again.\n");
            }
        }
    } else {
        do_continue();
        if(!vflag) {
            do_print();
        }
    }
}

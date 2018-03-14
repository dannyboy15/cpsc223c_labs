/* Daniel Bravo
 * 2018-03-14
 * Lab 6
 */

// Lab 6 - Re-write Lab 3 to use the Better String Library

/*
 * Lab 3 - Create a calculator that will step through cammands
 */

#include <stdio.h>
#include <stdint.h>
#include "bstrlib.h"

struct command {
    bstring cmd;
    unsigned int cmdVal;
    unsigned int lineNum;
};

void runCommand(uint8_t* val, bstring cmd, unsigned int* cmdVal)
{
    if (biseqcstr(cmd, "set") == 1) {
        *val = *cmdVal;
    } else if (biseqcstr(cmd, "and") == 1) {
        *val = *val & *cmdVal;
    } else if (biseqcstr(cmd, "or") == 1) {
        *val = *val | *cmdVal;
    } else if (biseqcstr(cmd, "xor") == 1) {
        *val = *val ^ *cmdVal;
    } else if (biseqcstr(cmd, "shr") == 1) {
        *val = *val >> *cmdVal;
    } else if (biseqcstr(cmd, "shl") == 1) {
        *val = *val << *cmdVal;
    } else {
        printf("Invalid command. Please try again.\n");
    }
    // printf("%s %x => %x\n", cmd, *cmdVal, *val);
}

void execCommand(struct command* cmds, unsigned int* pos, unsigned int* maxPos,
    bstring cmd, uint8_t* val)
{
    if (biseqcstr(cmd, "step") == 1) {
        if (*pos > *maxPos) {
            printf("You have reached the end of the program!\n");
            return;
        }
        runCommand(val, cmds[*pos].cmd, &cmds[*pos].cmdVal);
        (*pos)++;
        
    } else if (biseqcstr(cmd, "continue") == 1) {
        if (*pos > *maxPos) {
            printf("You have reached the end of the program!\n");
            return;
        }
        for(unsigned int i = *pos; i <= *maxPos; i++) {
            runCommand(val, cmds[i].cmd, &cmds[i].cmdVal);
            (*pos)++;
        }
    } else if (biseqcstr(cmd, "print") == 1) {
        printf("%x\n", *val);
    } else if (biseqcstr(cmd, "list") == 1) {
        if(*pos != 0 && *pos <= *maxPos) {
            printf(" %d %s %x\n", cmds[*pos - 1].lineNum, cmds[*pos - 1].cmd->data, cmds[*pos - 1].cmdVal);
        }
        if(*pos <= *maxPos) {
            printf(" %d %s %x\n", cmds[*pos].lineNum, cmds[*pos].cmd->data, cmds[*pos].cmdVal);
        }
        if(*pos < *maxPos) {
            printf(" %d %s %x\n", cmds[*pos + 1].lineNum, cmds[*pos + 1].cmd->data, cmds[*pos + 1].cmdVal);
        }
        if(*pos > *maxPos) {
            printf("%d %s %x\n", cmds[*pos - 2].lineNum, cmds[*pos - 2].cmd->data, cmds[*pos - 2].cmdVal);
            printf("%d %s %x\n", cmds[*pos - 1].lineNum, cmds[*pos - 1].cmd->data, cmds[*pos - 1].cmdVal);
        }
    } else {
        printf("Invalid command. Please try again.\n");
    }
}


int main()
{
    uint8_t val = 0;
    unsigned int currPos = 0;
    unsigned int maxPos = 12;
    bstring cmd;
    struct command cmds[] = {
        {
            .cmd = bfromcstr("set"),
            .cmdVal = 1,
            .lineNum = 1,
        },
        {
            .cmd = bfromcstr("shl"),
            .cmdVal = 1,
            .lineNum = 2,
        },
        {
            .cmd = bfromcstr("shl"),
            .cmdVal = 1,
            .lineNum = 3,
        },
        {
            .cmd = bfromcstr("or"),
            .cmdVal = 1,
            .lineNum = 4,
        },
        {
            .cmd = bfromcstr("or"),
            .cmdVal = 2,
            .lineNum = 5,
        },
        {
            .cmd = bfromcstr("shl"),
            .cmdVal = 2,
            .lineNum = 6,
        },
        {
            .cmd = bfromcstr("xor"),
            .cmdVal = 10,
            .lineNum = 7,
        },
        {
            .cmd = bfromcstr("xor"),
            .cmdVal = 10,
            .lineNum = 8,
        },
        {
            .cmd = bfromcstr("and"),
            .cmdVal = 4,
            .lineNum = 9,
        },
        {
            .cmd = bfromcstr("set"),
            .cmdVal = 0x1c,
            .lineNum = 10,
        },
        {
            .cmd = bfromcstr("and"),
            .cmdVal = 3,
            .lineNum = 11,
        },
        {
            .cmd = bfromcstr("set"),
            .cmdVal = 0x1c,
            .lineNum = 12,
        },
        {
            .cmd = bfromcstr("shr"),
            .cmdVal = 1,
            .lineNum = 13,
        },
    };

    while((cmd = bgets((bNgetc) fgetc, stdin, '\n'))) {
        // bgets consumes the new line character ('\n') therefore replace it
        // with the null character ('\0') to accurately check equality
        bfindreplace(cmd, bfromcstr("\n"), bfromcstr("\0"), 0);
        execCommand(cmds, &currPos, &maxPos, cmd, &val);
    }



}

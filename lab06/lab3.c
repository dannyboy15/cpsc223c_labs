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
//#include <string.h>
#include "bstrlib.h"

struct command {
    //char cmd[4];
    bstring cmd;
    unsigned int cmdVal;
    unsigned int lineNum;
};

void runCommand(uint8_t* val, bstring cmd, unsigned int* cmdVal) {
    if (bstrcmp(cmd, bfromcstr("set")) == 0) {
        *val = *cmdVal;
    } 
    else if (bstrcmp(cmd, bfromcstr("and")) == 0) {
        *val = *val & *cmdVal;
    }
    else if (bstrcmp(cmd, bfromcstr("or")) == 0) {
        *val = *val | *cmdVal;
    }
    else if (bstrcmp(cmd, bfromcstr("xor")) == 0) {
        *val = *val ^ *cmdVal;
    }
    else if (bstrcmp(cmd, bfromcstr("shr")) == 0) {
        *val = *val >> *cmdVal;
    }
    else if (bstrcmp(cmd, bfromcstr("shl")) == 0) {
        *val = *val << *cmdVal;
    }
    else {
        printf("Invalid command. Please try again.\n");
    }

    // printf("%s %x => %x\n", cmd, *cmdVal, *val);
}

void execCommand(struct command* cmds, unsigned int* pos, unsigned int* maxPos, bstring cmd, uint8_t* val) {
    if (bstrcmp(cmd, bfromcstr("step")) == 0) {
	//printf("%d", bstrcmp(cmd, bfromcstr("step")));
        if (*pos > *maxPos) {
            printf("You have reached the end of the program!\n");
            return;
        }
        runCommand(val, cmds[*pos].cmd, &cmds[*pos].cmdVal);
        (*pos)++;
        
    } 
    else if (bstrcmp(cmd, bfromcstr("continue")) == 0) {
        if (*pos > *maxPos) {
            printf("You have reached the end of the program!\n");
            return;
        }
        for(unsigned int i = *pos; i <= *maxPos; i++) {
            runCommand(val, cmds[i].cmd, &cmds[i].cmdVal);
            (*pos)++;
        }
    }
    else if (bstrcmp(cmd, bfromcstr("print")) == 0) {
        printf("%x\n", *val);
    }
    else if (bstrcmp(cmd, bfromcstr("list")) == 0) {
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
    }
    else {
        printf("Invalid command. Please try again.\n");
    }
}


int main() {
    uint8_t val = 0;
    unsigned int currPos = 0;
    unsigned int maxPos = 12;
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

    bstring cmd;
    
    while((cmd = bgets((bNgetc) fgetc, stdin, '\n'))) {
        // bgets consumes the new line character ('\n') therefore replace it
        // with the null character ('\0') to accurately check equality
        bfindreplace(cmd, bfromcstr("\n"), bfromcstr("\0"), 0);
        execCommand(cmds, &currPos, &maxPos, cmd, &val);
    }



}

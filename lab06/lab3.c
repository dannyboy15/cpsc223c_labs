// Daniel Bravo
// 2018-02-14

/*
 * Lab 3 - Create a calculator that will step through cammands
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct command {
    char cmd[4];
    unsigned int cmdVal;
    unsigned int lineNum;
};

void runCommand(uint8_t* val, char* cmd, unsigned int* cmdVal) {
    if (strcmp(cmd, "set") == 0) {
        *val = *cmdVal;
    } 
    else if (strcmp(cmd, "and") == 0) {
        *val = *val & *cmdVal;
    }
    else if (strcmp(cmd, "or") == 0) {
        *val = *val | *cmdVal;
    }
    else if (strcmp(cmd, "xor") == 0) {
        *val = *val ^ *cmdVal;
    }
    else if (strcmp(cmd, "shr") == 0) {
        *val = *val >> *cmdVal;
    }
    else if (strcmp(cmd, "shl") == 0) {
        *val = *val << *cmdVal;
    }
    else {
        printf("Invalid command. Please try again.\n");
    }

    // printf("%s %x => %x\n", cmd, *cmdVal, *val);
}

void execCommand(struct command* cmds, unsigned int* pos, unsigned int* maxPos, char* cmd, uint8_t* val) {
    if (strcmp(cmd, "step") == 0) {
        if (*pos > *maxPos) {
            printf("You have reached the end of the program!\n");
            return;
        }
        runCommand(val, cmds[*pos].cmd, &cmds[*pos].cmdVal);
        (*pos)++;
        
    } 
    else if (strcmp(cmd, "run") == 0) {
        if (*pos > *maxPos) {
            printf("You have reached the end of the program!\n");
            return;
        }
        for(unsigned int i = *pos; i <= *maxPos; i++) {
            runCommand(val, cmds[i].cmd, &cmds[i].cmdVal);
            (*pos)++;
        }
    }
    else if (strcmp(cmd, "print") == 0) {
        printf("%x\n", *val);
    }
    else if (strcmp(cmd, "list") == 0) {
        if(*pos != 0 && *pos <= *maxPos) {
            printf(" %d %s %x\n", cmds[*pos - 1].lineNum, cmds[*pos - 1].cmd, cmds[*pos - 1].cmdVal);
        }
        if(*pos <= *maxPos) {
            printf(" %d %s %x\n", cmds[*pos].lineNum, cmds[*pos].cmd, cmds[*pos].cmdVal);
        }
        if(*pos < *maxPos) {
            printf(" %d %s %x\n", cmds[*pos + 1].lineNum, cmds[*pos + 1].cmd, cmds[*pos + 1].cmdVal);
        }
        if(*pos > *maxPos) {
            printf("%d %s %x\n", cmds[*pos - 2].lineNum, cmds[*pos - 2].cmd, cmds[*pos - 2].cmdVal);
            printf("%d %s %x\n", cmds[*pos - 1].lineNum, cmds[*pos - 1].cmd, cmds[*pos - 1].cmdVal);
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
    char cmd[6];
    struct command cmds[] = {
        {
            .cmd = "set",
            .cmdVal = 1,
            .lineNum = 1,
        },
        {
            .cmd = "shl",
            .cmdVal = 1,
            .lineNum = 2,
        },
        {
            .cmd = "shl",
            .cmdVal = 1,
            .lineNum = 3,
        },
        {
            .cmd = "or",
            .cmdVal = 1,
            .lineNum = 4,
        },
        {
            .cmd = "or",
            .cmdVal = 2,
            .lineNum = 5,
        },
        {
            .cmd = "shl",
            .cmdVal = 2,
            .lineNum = 6,
        },
        {
            .cmd = "xor",
            .cmdVal = 10,
            .lineNum = 7,
        },
        {
            .cmd = "xor",
            .cmdVal = 10,
            .lineNum = 8,
        },
        {
            .cmd = "and",
            .cmdVal = 4,
            .lineNum = 9,
        },
        {
            .cmd = "set",
            .cmdVal = 0x1c,
            .lineNum = 10,
        },
        {
            .cmd = "and",
            .cmdVal = 3,
            .lineNum = 11,
        },
        {
            .cmd = "set",
            .cmdVal = 0x1c,
            .lineNum = 12,
        },
        {
            .cmd = "shr",
            .cmdVal = 1,
            .lineNum = 13,
        },
    };

    // Test the array
    // for(int i = 0; i < 13; i++) {
    //     runCommand(&val, cmds[i].cmd, &(cmds[i].cmdVal));
    // }

    while(scanf("%s", cmd) != EOF) {
        execCommand(cmds, &currPos, &maxPos, cmd, &val);
    }
}

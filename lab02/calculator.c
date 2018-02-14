// Daniel Bravo

/* Lab 2 - Create a calculator to work with hexadecimal numbers
 *
 * Create a calculator to work with hexadecimal numbers.
 *
 */

#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t val = 0;
    unsigned int inVal;
    char cmd[4];

    while(scanf("%s %x", cmd, &inVal) != EOF) {
        // scanf("%s", cmd);
        // scanf("%x", &inVal);

        switch(cmd[0]) {
            case 's' :
                switch(cmd[2]) {
                    case 't' :
                        val = inVal;
                        break;

                    case 'r' :
                        // printf("r %s", cmd);
                        val = val >> inVal;
                        break;

                    case 'l':
                        // printf("l %s", cmd);
                        val = val << inVal;
                        break;
                }
                break;

            case 'a' :
                val = val & inVal;
                break;

            case 'o' :
                val = val | inVal;
                break;
            
            case 'x' :
                val = val ^ inVal;
                break;

            default :
                printf("Invalid command. Please try again.\n");
        }

        printf("%s %x => %x\n", cmd, inVal, val);
    }
}

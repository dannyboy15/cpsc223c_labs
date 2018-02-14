// Daniel Bravo

/* Lab 2 - Create a calculator to work with hexadecimal numbers
 *
 * Create a calculator to work with hexadecimal numbers.
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    uint8_t val = 0;
    unsigned int inVal;
    char cmd[4];

    while(scanf("%s %x", cmd, &inVal) != EOF) {
	if (strcmp(cmd, "set") == 0) {
		val = inVal;
  	} 
	else if (strcmp(cmd, "and") == 0) {
		val = val & inVal;
	}
	else if (strcmp(cmd, "or") == 0) {
		val = val | inVal;
	}
	else if (strcmp(cmd, "xor") == 0) {
		val = val ^ inVal;
	}
	else if (strcmp(cmd, "shr") == 0) {
		val = val >> inVal;
	}
	else if (strcmp(cmd, "shl") == 0) {
		val = val << inVal;
	}
	else {
		printf("Invalid command. Please try again.\n");
	}

        printf("%s %x => %x\n", cmd, inVal, val);
    }
}

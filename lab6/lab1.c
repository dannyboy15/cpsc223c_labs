// Daniel Bravo

// lab1.cpp - convert this code to C11

/*
 *  This code should compile cleanly with the following options:
 *

    C:   -std=c11   -g -Og -Wall -Wextra -Wpedantic

    C++: -std=c++11 -g -Og -Wall -Wextra -Wpedantic

 */

#include <stdio.h>
#include <string.h>

void bumpInt(int* i, int* amt) {
    if(amt) {
        *i += *amt;
    }
    else {
        *i += 1;
    }
}


void bumpStr(char* s, char* c) {
    if(c) {
        strcat(s, c);
    }
    else {
        strcat(s, "o");
    }
}


int main()
{
    int i = 1;

    printf("%d\n", i);
    bumpInt(&i, NULL);
    printf("%d\n", i);
    int j = 2;
    bumpInt(&i, &j);
    printf("%d\n", i);

    char s[4] = "foo";

    printf("%s\n", s);
    bumpStr(s, NULL);
    printf("%s\n", s);
    char a[2] = "x";
    bumpStr(s, a);
    printf("%s\n", s);

    return 0;
}

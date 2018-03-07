/* Daniel Bravo
 * 2018-03-14
 * Lab 6
 */

// Lab 6 - Re-write Lab 1 to use the Better String Library

// lab1.cpp - convert this code to C11

/*
 *  This code should compile cleanly with the following options:
 *

    C:   -std=c11   -g -Og -Wall -Wextra -Wpedantic

    C++: -std=c++11 -g -Og -Wall -Wextra -Wpedantic

 */

#include <stdio.h>
#include "bstrlib.h"

void bumpInt(int* i, int* amt)
{
    if(amt) {
        *i += *amt;
    } else {
        *i += 1;
    }
}


void bumpStr(bstring s, bstring c)
{
    if(c) {
        bconcat(s, c);
    } else {
        bconcat(s, bfromcstr("o"));
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

    bstring s = bfromcstr("foo");
    //char s[4] = "foo";

    printf("%s\n", s->data);
    bumpStr(s, NULL);
    printf("%s\n", s->data);
    bstring a = bfromcstr("x");
    //char a[2] = "x";
    bumpStr(s, a);
    printf("%s\n", s->data);

    return 0;
}

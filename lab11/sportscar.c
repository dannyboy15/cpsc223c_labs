/* Daniel Bravo
 * 2018-05-09
 * CPSC 223C-01/02
 * Lab 11
 */

#include <stdio.h>

#include "sportscar.h"

void SportsCar_describe_impl(Automobile *obj)
{
    SportsCar *this = (SportsCar *) obj;

    printf(
        "%d %s with %d doors, %d miles and top speed of %d.\n",
        this->parent.parent.model,
        this->parent.parent.make,
        this->parent.doors,
        this->parent.parent.mileage,
        this->topSpeed
    );

    Automobile_describe_impl(&this->parent.parent);
}

struct vtbl SportsCar_vtable = {
    SportsCar_describe_impl,
};

/* Daniel Bravo
 * 2018-05-09
 * CPSC 223C-01/02
 * Lab 11
 */

#include <stdio.h>

#include "electriccar.h"

void ElectricCar_describe_impl(Automobile *obj)
{
    ElectricCar *this = (ElectricCar *) obj;

    printf(
        "%d %s with %d doors, %d miles and a maximum range of %d.\n",
        this->parent.parent.model,
        this->parent.parent.make,
        this->parent.doors,
        this->parent.parent.mileage,
        this->maximumRange
    );

    Automobile_describe_impl(&this->parent.parent);
}

struct vtbl ElectricCar_vtable = {
    ElectricCar_describe_impl,
};

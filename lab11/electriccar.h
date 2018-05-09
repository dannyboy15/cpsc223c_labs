/* Daniel Bravo
 * 2018-05-09
 * CPSC 223C-01/02
 * Lab 11
 */

#ifndef _ELECTRICCAR_H
#define _ELECTRICCAR_H

#include "car.h"

typedef struct {
    Car parent;

    int maximumRange;
} ElectricCar;

extern struct vtbl ElectricCar_vtable;

#endif

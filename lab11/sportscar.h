/* Daniel Bravo
 * 2018-05-09
 * CPSC 223C-01/02
 * Lab 11
 */

#ifndef _SPORTSCAR_H
#define _SPORTSCAR_H

#include "car.h"

typedef struct {
    Car parent;

    int topSpeed;
} SportsCar;

extern struct vtbl SportsCar_vtable;

#endif

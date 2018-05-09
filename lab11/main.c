/*
 * Starter code for Lab 11
 *
 * cf. Gaddis, Starting out With C++, Eighth Edition, p. 912
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "automobile.h"
#include "car.h"
#include "truck.h"
#include "suv.h"
#include "sportscar.h"
#include "electriccar.h"

#define LEN(array) (sizeof(array) / sizeof(array[0]))

void list_inventory(Automobile *inventory[], int size)
{
    printf("We have the following automobiles in inventory:\n\n");

    for (int i = 0; i < size; i++) {
        inventory[i]->vptr->describe(inventory[i]);
        printf("\n");
    }
}

void testDrive(Automobile *automobile, int length)
{
    printf("  > Test driving the %s for %d miles\n\n", automobile->make, length);
    automobile->mileage += length;
}

int main(void)
{
    Car c = {
        .parent.make     = "BMW",
        .parent.model    = 2017,
        .parent.mileage  = 50000,
        .parent.price    = 15000.0,
        .doors           = 4,
        .parent.vptr     = &Car_vtable,
    };

    Truck t = {
        .parent.make     = "Toyota",
        .parent.model    = 2006,
        .parent.mileage  = 40000,
        .parent.price    = 12000.0,
        .driveType       = "4WD",
        .parent.vptr     = &Truck_vtable,
    };

    SUV s = {
        .parent.make     = "Volvo",
        .parent.model    = 2005,
        .parent.mileage  = 30000,
        .parent.price    = 18000.0,
        .passengers      = 5,
        .parent.vptr     = &SUV_vtable,
    };

    SportsCar sc = {
        .parent.parent.make     = "Ferrari",
        .parent.parent.model    = 2016,
        .parent.parent.mileage  = 4000,
        .parent.parent.price    = 252800.0,
        .parent.doors           = 2,
        .topSpeed               = 349,
        .parent.parent.vptr     = &SportsCar_vtable,
    };

    ElectricCar ec = {
        .parent.parent.make     = "Tesla",
        .parent.parent.model    = 2018,
        .parent.parent.mileage  = 5,
        .parent.parent.price    = 101500.0,
        .parent.doors           = 4,
        .maximumRange           = 335,
        .parent.parent.vptr     = &ElectricCar_vtable,
    };

    Automobile *stock[] = {
        (Automobile *) &c,
        (Automobile *) &t,
        (Automobile *) &s,
        (Automobile *) &sc,
        (Automobile *) &ec
    };

    list_inventory(stock, LEN(stock));

    // Test drive the cars
    printf("Test driving the cars...\n\n");
    testDrive((Automobile *) &c, 45);
    testDrive((Automobile *) &t, 40);
    testDrive((Automobile *) &s, 13);
    testDrive((Automobile *) &sc, 49);
    testDrive((Automobile *) &ec, 34);

    list_inventory(stock, LEN(stock));

    return EXIT_SUCCESS;
}

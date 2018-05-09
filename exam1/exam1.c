/* Daniel Bravo
 * 2018-02-21
 *
 * Exam 1
 * Using the code from exam1.c, write a C program to compute teh total cost of
 * a backet of groceries.
 *
 * Compilation
 * Your code must compile cleanly without warnings using GCC and the following
 * compiler flags:
 * -std=c11 -Wall -Wextra -Wpedantic
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAX_RATE 0.0775
#define CATALOG_SIZE ((int) (sizeof(catalog) / sizeof(struct item)))

struct item {
    char *sku;
    char *desc;
    double price;
    bool taxable;
};

struct item catalog[] = {
    { .sku = "87465896", .desc = "milk",         .price = 3.59, .taxable = false },
    { .sku = "37485942", .desc = "eggs",         .price = 2.98, .taxable = false },
    { .sku = "37618947", .desc = "bread",        .price = 3.18, .taxable = false },
    { .sku = "09484232", .desc = "ziploc bags",  .price = 1.19, .taxable = true },
    { .sku = "83648591", .desc = "paper towels", .price = 2.76, .taxable = true },
};

void addItem(struct item * basket[], int* numItems, char* sku, int qty) {
    int newNumItems = *numItems + qty;
    struct item * itm;

    for(int i = 0; i < CATALOG_SIZE; i++) {
        if( strcmp(catalog[i].sku, sku) == 0 ) {
            itm = &catalog[i];
        }
    }

    while(*numItems < newNumItems) {
        basket[*numItems] = itm;
        (*numItems)++;
    }
}

double computeCost(struct item * basket[], int numItems) {
    double sum = 0.0;

    for(int i = 0; i < numItems; i++) {
        double itmCost = basket[i]->price;
        if(basket[i]->taxable) {
            itmCost = (1 + TAX_RATE) * itmCost;
        }

        sum += itmCost;
    }

    return sum;
}

int main(void) {
    struct item * basket[1000];
    int numItems = 0;

    char sku[9];
    int qty;

    // Add items to basket
    while(scanf("%s %d", sku, &qty) != EOF) {
        addItem(basket, &numItems, sku, qty);
    }

    // Get the cost of basket
    // double cost = computeCost(basket, numItems);
    printf("$%.2f\n", computeCost(basket, numItems));

    return EXIT_SUCCESS;
}

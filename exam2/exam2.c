/* Daniel Bravo
 * 2018-03-21
 * CPSC 233C
 * Exam 2
 */

// exam2.c - starter code for Exam 2

/*
 *  This code should compile cleanly with the following options:
 *

    -std=c11 -Wall -Wextra -Wpedantic -Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default -Wbad-function-cast -Wcast-qual -Waggregate-return

 */


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef WANT_BSTRING
#include "bstrlib.h"
#else
#include <string.h>
#endif

#define PRIORITY_SIZE 2

struct queue {
    struct queue_element *front;
    struct queue_element *back;
    int element_count;
};

struct queue_element {
    int label;
    struct queue_element *next;
};

struct queue *queue_create(void)
{
    struct queue *q = malloc(sizeof(struct queue));
    if (q == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    q->front = NULL;
    q->back = NULL;
    q->element_count = 0;

    return q;
}

void queue_add(struct queue *q, int label)
{
    assert(q != NULL);

    struct queue_element *e = malloc(sizeof(struct queue_element));
    if (e == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    e->label = label;
    e->next = NULL;

    if (q->front == NULL) {
      q->front = e;
      q->back = e;
    } else {
      q->back->next = e;
      q->back = e;
    }

    q->element_count++;
}

int queue_remove(struct queue *q)
{
    assert(q != NULL);

    int label = -1;

    if (q->front == NULL) {
      return -1;
    }

    struct queue_element *tmp;
    tmp = q->front;

    label = q->front->label;
    q->front = q->front->next;

    free(tmp);
    q->element_count--;

    return label;
}


void queue_destroy(struct queue *q)
{
    assert(q != NULL);

    while (q->element_count > 0) {
        queue_remove(q);
    }

    free(q);
}

int main(void)
{
    struct queue *high_priority = queue_create();
    struct queue *low_priority = queue_create();

    int label;
    char priority[PRIORITY_SIZE + 1];

    while (scanf("%d %s", &label, priority) != EOF) {
        if (strcmp(priority, "hi") ==  0) {
          queue_add(high_priority, label);
        } else {
          queue_add(low_priority, label);
        }
    }

    int flag = 1;
    struct queue_element *qeh = high_priority->front;
    struct queue_element *qel = low_priority->front;
    while (qeh || qel) {
      if ((flag % 3) != 0 && qeh) {
        printf("%d ", qeh->label);
        qeh = qeh->next;
      } else {
        printf("%d ", qel->label);
        qel = qel->next;
      }
      flag++;
    }
    printf("\n");


    // for testting
    // struct queue_element *qeh = high_priority->front;
    // struct queue_element *qel = low_priority->front;
    // printf("high size :%d\n", high_priority->element_count);
    // printf("low  size :%d\n", low_priority->element_count);
    // while(qeh) {
    //   printf("%d %s\n", qeh->label, "hi");
    //   qeh = qeh->next;
    // }
    //
    // while(qel) {
    //   printf("%d %s\n", qel->label, "lo");
    //   qel = qel->next;
    // }

    queue_destroy(high_priority);
    queue_destroy(low_priority);

    return EXIT_SUCCESS;
}

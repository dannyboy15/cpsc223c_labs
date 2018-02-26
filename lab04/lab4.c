// Daniel Bravo
// 2018-02-26
// Lab 4

/*
 * Convert your program from Lab 3 to use a linked list instead of an array.
 * Use this code as a starting point.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_SIZE 3
#define PROGRAM_SIZE 13

struct node *currentNode;
struct node *previousNode;
uint8_t byte = 0;

struct node {
    int line;
    char command[MAX_COMMAND_SIZE + 1];
    unsigned int argument;

    struct node *next;
};

struct node *create_node(int line, char *command, unsigned int argument)
{
    assert(strlen(command) <= MAX_COMMAND_SIZE);

    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__); 
        exit(EXIT_FAILURE);
    }

    new->line = line;
    strcpy(new->command, command);
    new->argument = argument;

    new->next = NULL;

    return new;
}

struct node *append_node(struct node *start, struct node *new)
{
    assert(start != NULL);

    struct node *current = start;
    
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new;

    return new;
}

void print_node(struct node *n)
{
    printf("%2d %s %x\n", n->line, n->command, n->argument);
}

void print_list(struct node *start)
{
    struct node *current = start;

    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
}

struct node *create_list(void)
{
    struct node *head, *next;
    int line = 1;

    head = create_node(line++, "set", 0x1);
    next = append_node(head, create_node(line++, "shl", 0x1));
    next = append_node(next, create_node(line++, "shl", 0x1));
    next = append_node(next, create_node(line++, "or", 0x1));
    next = append_node(next, create_node(line++, "or", 0x2));
    next = append_node(next, create_node(line++, "shl", 0x2));
    next = append_node(next, create_node(line++, "xor", 0x10));
    next = append_node(next, create_node(line++, "xor", 0x10));
    next = append_node(next, create_node(line++, "and", 0x4));
    next = append_node(next, create_node(line++, "set", 0x1c));
    next = append_node(next, create_node(line++, "and", 0x3));
    next = append_node(next, create_node(line++, "set", 0x1c));
    next = append_node(next, create_node(line++, "shr", 0x1));

    return head;
}

void free_list(struct node *start)
{
    struct node *prev, *current;

    current = start;
    while (current != NULL) {
        prev = current;    
        current = current->next;
        free(prev);
    }
}

void doStep() {
    if(currentNode->next == NULL) {
        return;
    }

    previousNode = currentNode;

    if(strcmp(currentNode->command, "set") == 0) {
        byte = currentNode->argument;
    }
    else if(strcmp(currentNode->command, "and") == 0) {
        byte &= currentNode->argument;
    }
    else if(strcmp(currentNode->command, "or") == 0) {
        byte |= currentNode->argument;
    }
    else if(strcmp(currentNode->command, "xor") == 0) {
        byte ^= currentNode->argument;
    }
    else if(strcmp(currentNode->command, "shr") == 0) {
        byte >>= currentNode->argument;
    }
    else if(strcmp(currentNode->command, "shl") == 0) {
        byte <<= currentNode->argument;
    }

    currentNode = currentNode->next;
}

void doContinue() {
    while(currentNode->next != NULL) {
	doStep();
    }
}

void doPrint() {
    printf("%x\n", byte);
}

void printNode(struct node * n) {
    printf("%2d %s %x\n", n->line, n->command, n->argument);
}

void doList() {
    if(previousNode == NULL) {
	printNode(currentNode);
	printNode(currentNode->next);
    }
    else if(currentNode->next == NULL) {
	printNode(previousNode);
	printNode(currentNode);
    }
    else {
	printNode(previousNode);
	printNode(currentNode);
	printNode(currentNode->next);
    }
}

int main(void)
{
    char command[MAX_COMMAND_SIZE + 1];
    struct node *head = create_list();
    currentNode = head;

    while(scanf("%s", command) != EOF) {
	if(strcmp(command, "step") == 0) {
	    doStep();
	}
	else if(strcmp(command, "continue") == 0) {
	    doContinue();
	}
	else if (strcmp(command, "print") == 0) {
	    doPrint();
	}
	else if(strcmp(command, "list") == 0) {
	    doList();
	}
    }

//    print_list(head);

    free_list(head);

    return EXIT_SUCCESS;
}

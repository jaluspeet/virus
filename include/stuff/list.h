#ifndef LIST_H
#define LIST_H

#include "settings.h"
#include "types.h"

typedef struct node {
  coord position;
  struct node *next;
} node;

// lifo
void push_lifo(node **head, coord position);
coord pop_lifo(node **head);

// fifo
void push_fifo(node **head, coord position);
coord pop_fifo(node **head);

#endif // LIST_H
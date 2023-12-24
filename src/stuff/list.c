#include "stuff/list.h"

#include <stdlib.h>

void push_lifo(node **head, coord position) {
  node *new = (node *)malloc(sizeof(node));
  new->position = position;

  new->next = *head;
  *head = new;
}

coord pop_lifo(node **head) {
  coord ret;

  if (!(*head)) {
    ret.x = -1;
    ret.y = -1;
    return ret;
  } else if (!(*head)->next) {
    ret = (*head)->position;
    *head = NULL;
    return ret;
  } else {
    node *last = (*head);
    node *prev = NULL;

    while (last->next) {
      prev = last;
      last = last->next;
    }

    ret = last->position;

    prev->next = NULL;
    free(last);
  }

  return ret;
}

void push_fifo(node **tail, coord position) {
  node *new = (node *)malloc(sizeof(node));
  new->position = position;
  new->next = NULL;

  if (!(*tail)) {
    *tail = new;
  } else {
    (*tail)->next = new;
    *tail = new;
  }
}

coord pop_fifo(node **head) {
  coord ret;

  if (!(*head)) {
    ret.x = -1;
    ret.y = -1;
    return ret;
  } else {
    node *first = (*head);
    ret = first->position;
    *head = first->next;
    free(first);
  }

  return ret;
}
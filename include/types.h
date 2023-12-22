#ifndef TYPES_H
#define TYPES_H

typedef struct coord {
  int x;
  int y;
} coord;

typedef struct nodo {
  coord cella;
  struct nodo *next;
} nodo;

#endif // TYPES_H

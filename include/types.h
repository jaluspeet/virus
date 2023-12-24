#ifndef TYPES_H
#define TYPES_H

#include "settings.h"

typedef struct coord {
  int x;
  int y;
} coord;

typedef struct module {
  void (*function)(int map[MAP_X][MAP_Y]);
  char name[10];
} module;

#endif // TYPES_H

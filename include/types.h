#ifndef TYPES_H
#define TYPES_H

#include "settings.h"

typedef struct coord {
  int x;
  int y;
} coord;

typedef void (*module)(int map[MAP_X][MAP_Y]);

#endif // TYPES_H

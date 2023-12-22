#ifndef UTILS_H
#define UTILS_H

#include "settings.h"
#include "types.h"

// stack
void push(nodo **testa, coord cella);
coord pop(nodo **testa);

// useful stuff
void draw_map(int map[MAP_X][MAP_Y]);

#endif // UTILS_H

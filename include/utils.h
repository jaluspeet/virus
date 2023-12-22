#ifndef UTILS_H
#define UTILS_H

#include "settings.h"
#include "types.h"

// stack
void push(nodo **testa, coord cella);
coord pop(nodo **testa);

// robe gioco
void show_map(int map[MAP_X][MAP_Y], coord target, char charset[CHARSET_LEN]);
int retry(int score);

#endif // UTILS_H

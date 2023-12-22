#ifndef VIRUS_H
#define VIRUS_H

#include "settings.h"
#include "types.h"
#include "utils.h"

void init_map_virus(int map[MAP_X][MAP_Y]);
void virus(int map[MAP_X][MAP_Y], nodo **coda, int area, int genoma);

#endif // VIRUS_H
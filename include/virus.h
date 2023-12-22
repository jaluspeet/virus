#ifndef VIRUS_H
#define VIRUS_H

#include "list.h"
#include "settings.h"

void run_virus(int map[MAP_X][MAP_Y]);
void virus(int map[MAP_X][MAP_Y], node **tail, int area, int flag);

#endif // VIRUS_H
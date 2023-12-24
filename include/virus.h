#ifndef VIRUS_H
#define VIRUS_H

#include "list.h"
#include "settings.h"

#define VIRUS_NUM 50
#define VIRUS_SIZE 10000
#define VIRUS_TRIES 1000

void run_virus(int map[MAP_X][MAP_Y]);
void virus(int map[MAP_X][MAP_Y], node **tail, int area, int flag);

#endif // VIRUS_H
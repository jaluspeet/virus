#ifndef WALKER_H
#define WALKER_H

#include "settings.h"
#include "types.h"

#define WALKER_NUM 200
#define WALKER_SIZE 1000
#define WALKER_TRIES 100

void run_walker(int map[MAP_X][MAP_Y]);
void walker(int map[MAP_X][MAP_Y], int flag);

#endif // WALKER_H
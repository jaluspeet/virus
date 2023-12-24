#ifndef WALKER_H
#define WALKER_H

#include "settings.h"
#include "types.h"

#define WALKER_NUM 50
#define WALKER_SIZE 10000
#define WALKER_TRIES 100

void run_walker(int map[MAP_X][MAP_Y]);

#endif // WALKER_H
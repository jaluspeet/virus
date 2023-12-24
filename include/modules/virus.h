#ifndef VIRUS_H
#define VIRUS_H

#include "settings.h"
#include "stuff/list.h"
#include "types.h"

#define VIRUS_NUM 50
#define VIRUS_SIZE 10000
#define VIRUS_TRIES 1000

void run_virus(int map[MAP_X][MAP_Y]);

#endif // VIRUS_H
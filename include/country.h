#ifndef COUNTRY_H
#define COUNTRY_H

#include "settings.h"
#include "types.h"
#include "utils.h"

#define COUNTRY_SIZE 200
#define COUNTRY_NUM 40
#define COUNTRY_TRIES 100

void run_country(int map[MAP_X][MAP_Y]);
void country(int map[MAP_X][MAP_Y], coord start, coord offset, int flag);
coord find_free_spot(int map[MAP_X][MAP_Y], coord size);

#endif // COUNTRY_H
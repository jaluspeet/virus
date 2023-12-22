#ifndef COUNTRY_H
#define COUNTRY_H

#include "settings.h"
#include "types.h"

void run_country(int map[MAP_X][MAP_Y]);
void country(int map[MAP_X][MAP_Y], coord start, coord offset, int flag);
coord find_free_spot(int map[MAP_X][MAP_Y], coord size);

#endif // COUNTRY_H

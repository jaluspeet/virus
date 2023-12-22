#ifndef COUNTRY_H
#define COUNTRY_H

#include "settings.h"
#include "types.h"

void init_map_country(int map[MAP_X][MAP_Y]);
coord find_free_spot(int map[MAP_X][MAP_Y], coord size);
void country(int map[MAP_X][MAP_Y], coord start, coord offset, int flag);

#endif // COUNTRY_H
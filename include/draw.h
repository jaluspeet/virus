#ifndef UTILS_H
#define UTILS_H

#include "settings.h"

// draw expand
#if DRAW_MAP == 0
#undef DRAW_MAP
#define DRAW_MAP printf("not drawing the map, sorry")

#elif DRAW_MAP == 1
#undef DRAW_MAP
#define DRAW_MAP draw_map_ascii(map)

#else
#undef DRAW_MAP
#define DRAW_MAP draw_map_png(map)

#endif

void init_map(int map[MAP_X][MAP_Y]);
void draw_map_ascii(int map[MAP_X][MAP_Y]);
void draw_map_png(int map[MAP_X][MAP_Y]);

#endif // UTILS_H

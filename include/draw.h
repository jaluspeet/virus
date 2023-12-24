#ifndef DRAW_H
#define DRAW_H

#include "settings.h"

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

#define COLOR 1
#define NO_SEA 0
#define CHARSET "$@%&#*/|(){}[]?-_+~<>!;:,^`'."
#define CHARSET_LEN sizeof(CHARSET)
void draw_map_ascii(int map[MAP_X][MAP_Y]);

#define RED 0
#define GREEN 0
#define BLUE 0
#define BRIGHTNESS 50
void draw_map_png(int map[MAP_X][MAP_Y]);

#endif // DRAW_H

#include "country.h"

#include "settings.h"
#include "types.h"

#include <stdlib.h>

void country(int map[MAP_X][MAP_Y], coord start, coord offset, int flag) {
  for (int i = start.x; i < start.x + offset.x; i++)
    for (int j = start.y; j < start.y + offset.y; j++)
      map[i][j] = flag;
}

coord find_free_spot(int map[MAP_X][MAP_Y], coord size) {

  coord not_found = {-1, -1};

  for (int i = 0; i < COUNTRY_TRIES; i++) {

    int discard = 0;
    int x = rand() % (MAP_X - size.x + 1);
    int y = rand() % (MAP_Y - size.y + 1);
    coord found = {x, y};

    for (int need_x = 0; need_x < size.x; need_x++)
      for (int need_y = 0; need_y < size.y; need_y++)
        if (map[x + need_x][y + need_y] != 0)
          discard++;

    if (!discard)
      return found;
  }

  return not_found;
}

void run_country(int map[MAP_X][MAP_Y]) {
  for (int i = 0; i < COUNTRY_NUM; i++) {
    coord size = {2 + rand() % COUNTRY_SIZE, 2 + rand() % COUNTRY_SIZE};
    coord free_spot = find_free_spot(map, size);

    if (free_spot.x < 0 || free_spot.y < 0)
      i--;
    else
      country(map, free_spot, size, i);
  }
}

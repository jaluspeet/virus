#include "walker.h"
#include "types.h"

#include <stdlib.h>

void walker(int map[MAP_X][MAP_Y], int flag) {
  coord position = {rand() % MAP_X, rand() % MAP_Y};
  int direction = rand() % 4;
  int tries = 0;

  for (int i = 0; i < WALKER_SIZE && tries < WALKER_TRIES; i++) {
    switch (direction) {
    case 0:
      if (position.x < MAP_X - 1 && map[position.x + 1][position.y] == 0) {
        position.x++;
        map[position.x][position.y] = flag;
      } else {
        direction = rand() % 4;
        tries++;
      }
      break;
    case 1:
      if (position.x > 0 && map[position.x - 1][position.y] == 0) {
        position.x--;
        map[position.x][position.y] = flag;
      } else {
        direction = rand() % 4;
        tries++;
      }
      break;
    case 2:
      if (position.y < MAP_Y - 1 && map[position.x][position.y + 1] == 0) {
        position.y++;
        map[position.x][position.y] = flag;
      } else {
        direction = rand() % 4;
        tries++;
      }
      break;
    case 3:
      if (position.y > 0 && map[position.x][position.y - 1] == 0) {
        position.y--;
        map[position.x][position.y] = flag;
      } else {
        direction = rand() % 4;
        tries++;
      }
      break;
    }
  }
}

void run_walker(int map[MAP_X][MAP_Y]) {
  for (int i = 0; i < WALKER_NUM; i++)
    walker(map, i);
}

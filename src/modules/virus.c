#include "modules/virus.h"

#include <stdlib.h>

void virus(int map[MAP_X][MAP_Y], node **tail, int area, int flag) {

  coord start;

  do {
    start = pop_lifo(tail);
    if (start.x == -1 || start.y == -1 || area == 0)
      return;
  } while (map[start.x][start.y] != 0);

  map[start.x][start.y] = flag;

  if (start.x + 1 < MAP_X && map[start.x + 1][start.y] == 0) {
    coord right = {start.x + 1, start.y};
    push_lifo(tail, right);
  }
  if (start.x - 1 >= 0 && map[start.x - 1][start.y] == 0) {
    coord left = {start.x - 1, start.y};
    push_lifo(tail, left);
  }
  if (start.y + 1 < MAP_Y && map[start.x][start.y + 1] == 0) {
    coord down = {start.x, start.y + 1};
    push_lifo(tail, down);
  }
  if (start.y - 1 >= 0 && map[start.x][start.y - 1] == 0) {
    coord up = {start.x, start.y - 1};
    push_lifo(tail, up);
  }

  virus(map, tail, area - 1, flag);
}

void run_virus(int map[MAP_X][MAP_Y]) {
  for (int i = 0; i < VIRUS_NUM; i++) {
    int tries = 0;
    coord start;

    do {
      start.x = rand() % MAP_X;
      start.y = rand() % MAP_Y;

      if (tries++ > VIRUS_TRIES)
        return;

    } while (map[start.x][start.y] != 0);

    int area = VIRUS_SIZE + rand() % VIRUS_SIZE;
    node *tail = NULL;

    push_lifo(&tail, start);
    virus(map, &tail, area, i + 1);
  }
}
#include "../include/virus.h"

#include <stdlib.h>

void init_map_virus(int map[MAP_X][MAP_Y]) {
  for (int i = 0; i < VIRUSES; i++) {
    int tries = 0;
    coord start;

    do {
      start.x = rand() % MAP_X;
      start.y = rand() % MAP_Y;

      if (tries++ > VIRUS_TRIES)
        return;

    } while (map[start.x][start.y] != 0);

    int area = AREA_VIRUS + rand() % AREA_VIRUS;
    nodo *coda = NULL;

    push(&coda, start);
    virus(map, &coda, area, i + 1);
  }
}

void virus(int map[MAP_X][MAP_Y], nodo **coda, int area, int genoma) {

  coord start;

  do {
    start = pop(coda);
    if (start.x == -1 || start.y == -1 || area == 0)
      return;
  } while (map[start.x][start.y] != 0);

  map[start.x][start.y] = genoma;

  if (start.x + 1 < MAP_X && map[start.x + 1][start.y] == 0) {
    coord destra = {start.x + 1, start.y};
    push(coda, destra);
  }
  if (start.x - 1 >= 0 && map[start.x - 1][start.y] == 0) {
    coord sinistra = {start.x - 1, start.y};
    push(coda, sinistra);
  }
  if (start.y + 1 < MAP_Y && map[start.x][start.y + 1] == 0) {
    coord giu = {start.x, start.y + 1};
    push(coda, giu);
  }
  if (start.y - 1 >= 0 && map[start.x][start.y - 1] == 0) {
    coord su = {start.x, start.y - 1};
    push(coda, su);
  }

  virus(map, coda, area - 1, genoma);
}

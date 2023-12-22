#include "../include/utils.h"

#include <stdio.h>

void draw_map(int map[MAP_X][MAP_Y]) {

  for (int i = 0; i < MAP_X; i++) {
    for (int j = 0; j < MAP_Y; j++) {

      if (COLOR)
        printf("\033[%dm%3c\033[0m", 31 + (map[i][j] % 8), CHARSET[map[i][j]]);
      else
        printf("%3c", CHARSET[map[i][j]]);
    }
    printf("\n");
  }
}

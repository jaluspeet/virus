#include "../include/utils.h"

#include <stdio.h>
#include <stdlib.h>

void init_map(int map[MAP_X][MAP_Y]) {

  for (int i = 0; i < MAP_X; i++)
    for (int j = 0; j < MAP_Y; j++)
      map[i][j] = 0;
}

void draw_map(int map[MAP_X][MAP_Y]) {

  for (int i = 0; i < MAP_X; i++) {
    for (int j = 0; j < MAP_Y; j++) {

      if (COLOR)
        printf("\033[%dm%3c\033[0m", 30 + NO_SEA + (map[i][j] % 8),
               CHARSET[map[i][j] % (int)CHARSET_LEN]);
      else
        printf("%3c", CHARSET[map[i][j]]);
    }

    printf("\n");
  }
}

void draw_png(int map[MAP_X][MAP_Y]) {

  int channels = 3; // RGB

  unsigned char *data = malloc(MAP_X * MAP_Y * channels);

  int index = 0;
  for (int i = 0; i < MAP_X; i++) {
    for (int j = 0; j < MAP_Y; j++) {
      data[index++] = map[i][j] % 256; // Red
      data[index++] = map[i][j] % 256; // Green
      data[index++] = map[i][j] % 256; // Blue
    }
  }

  stbi_write_png("map.png", MAP_X, MAP_Y, channels, data, MAP_X * channels);

  free(data);
}
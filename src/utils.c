#include "../include/utils.h"
#include <stdlib.h>

void init_map(int map[MAP_X][MAP_Y]) {

  for (int i = 0; i < MAP_X; i++)
    for (int j = 0; j < MAP_Y; j++)
      map[i][j] = 0;
}

void register_module(module new_module) {

  if (!modules) {
    modules = (module *)malloc(sizeof(module));
    modules[0] = new_module;
    return;
  }

  modules = (module *)realloc(modules, sizeof(module) * modules_size + 1);

  if (modules) {
    modules_size++;
    modules[modules_size] = new_module;
  }
}

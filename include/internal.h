#ifndef UTILS_H
#define UTILS_H

#include "settings.h"
#include "types.h"
#include <stdlib.h>
#include <string.h>

// globals
module *modules;
unsigned int modules_size;

void init_map(int map[MAP_X][MAP_Y]);
void register_module(void (*function)(int map[MAP_X][MAP_Y]), char name[10]);

void init_map(int map[MAP_X][MAP_Y]) {

  for (int i = 0; i < MAP_X; i++)
    for (int j = 0; j < MAP_Y; j++)
      map[i][j] = 0;
}

void register_module(void (*function)(int map[MAP_X][MAP_Y]), char name[10]) {
  module new;
  new.function = function;
  strcpy(new.name, name);

  modules_size++;
  modules = (module *)realloc(modules, sizeof(module) * modules_size);
  modules[modules_size - 1] = new;
}

#endif // UTILS_H

#ifndef UTILS_H
#define UTILS_H

#include "settings.h"
#include "types.h"

// globals
module *modules;
unsigned int modules_size;

void init_map(int map[MAP_X][MAP_Y]);
void register_module(void (*function)(int map[MAP_X][MAP_Y]), char name[10]);

#endif // UTILS_H
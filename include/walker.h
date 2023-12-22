#ifndef WALKER_H
#define WALKER_H

#include "list.h"
#include "settings.h"

void _run_walker(int map[MAP_X][MAP_Y]);
void _walker(int map[MAP_X][MAP_Y], node **head, int area, int flag);

#endif // WALKER_H
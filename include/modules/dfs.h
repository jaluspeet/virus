#ifndef DFS_H
#define DFS_H

#include "settings.h"
#include "stuff/list.h"
#include "types.h"

#define DFS_NUM 50
#define DFS_SIZE 1000
#define DFS_TRIES 1000

void run_dfs(int map[MAP_X][MAP_Y]);

#endif // DFS_H
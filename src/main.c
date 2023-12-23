#include "../include/country.h"
#include "../include/draw.h"
#include "../include/virus.h"
#include "../include/walker.h"

#include <stdlib.h>
#include <time.h>

int main(void) {

  srand(time(NULL));

  int map[MAP_X][MAP_Y];

  init_map(map);

  run_country(map);
  run_virus(map);
  run_walker(map);

  DRAW_MAP;

  return EXIT_SUCCESS;
}

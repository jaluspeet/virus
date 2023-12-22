#include "../include/country.h"
#include "../include/gaming.h"
#include "../include/settings.h"
#include "../include/virus.h"

#include <stdlib.h>
#include <time.h>

int main(void) {

  srand(time(NULL));

  if (GAMING)
    gaming();
  else {
    int map[MAP_X][MAP_Y];

    init_map_country(map);
    init_map_virus(map);

    draw_map(map);
  }

  return EXIT_SUCCESS;
}

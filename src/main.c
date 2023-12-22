#include "../include/country.h"
#include "../include/gaming.h"
#include "../include/settings.h"
#include "../include/virus.h"
#include "../include/walker.h"

#include <stdlib.h>
#include <time.h>

int main(void) {

  srand(time(NULL));

  if (GAMING)
    gaming();
  else {
    int map[MAP_X][MAP_Y];

    init_map(map);

    // run_country(map);
    // run_virus(map);
    run_walker(map);

    draw_map(map);
  }

  return EXIT_SUCCESS;
}

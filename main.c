#include "include/country.h"
#include "include/settings.h"
#include "include/types.h"
#include "include/utils.h"
#include "include/virus.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  srand(time(NULL));

  int map[MAP_X][MAP_Y];
  int score = 0;

  while (1) {
    init_map_country(map);
    init_map_virus(map);
    coord target = {rand() % MAP_X, rand() % MAP_Y};

    system("clear");
    show_map(map, target);

    int guess;
    printf("\n[SCORE: %d] Where was the coordinate? ", score);
    scanf("%d", &guess);

    if (map[target.x][target.y] == guess)
      score++;
    else {
      if (retry(score))
        score = 0;
      else
        return EXIT_SUCCESS;
    }
  }

  return EXIT_FAILURE;
}

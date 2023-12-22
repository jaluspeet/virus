#include "../include/gaming.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gaming() {

  int map[MAP_X][MAP_Y];
  int score = 0;

  while (1) {
    run_country(map);
    run_virus(map);
    coord target = {rand() % MAP_X, rand() % MAP_Y};

    system("clear");

    for (int t = TIMEOUT; t > 0; t--) {

      printf("\nFIND: %dX %dY (MAX: %dX %dY)", target.x, target.y, MAP_X,
             MAP_Y);
      printf("\n%d seconds left\n\n", t);

      draw_map(map);

      sleep(1);
      system("clear");
    }

    char guess;
    printf("\n[SCORE: %d] Where was the coordinate? (insert symbol): ", score);
    scanf("%c", &guess);

    // TODO: non va il check
    if (CHARSET[map[target.x][target.y]] == guess)
      score++;
    else {
      if (retry(score))
        score = 0;
    }
  }
}

int retry(int score) {
  system("clear");
  printf("Your score was: %d. Retry? (y/n):", score);

  getchar();

  while (1) {
    switch (getchar()) {
    case 'n':
    case 'N':
      return 0;
    case 'y':
    case 'Y':
      return 1;
    default:
      printf("\nThat isn't an option, sorry. Retry? (y/n): ");
    }
  }
}

#include "../include/country.h"
#include "../include/draw.h"
#include "../include/utils.h"
#include "../include/virus.h"
#include "../include/walker.h"

#include <stdio.h>
int SEED;

int main(void) {

  srand(time(NULL));

  SEED = rand();
  int map[MAP_X][MAP_Y];

  init_map(map);

  // TODO: registrare automaticamente tutti i moduli disponibili
  register_module(run_country);
  register_module(run_virus);
  register_module(run_walker);

  printf("Welcome to the virus (modules: 0 - %d):\n\n", modules_size);

  while (1) {
    unsigned int choice;
    printf("(virus) ");
    scanf("%ud", &choice);

    if (choice <= modules_size) {
      modules[choice](map);
      DRAW_MAP;
    } else
      fprintf(stderr, "\n\nModule does not exist\n\n");
  }

  return EXIT_SUCCESS;
}

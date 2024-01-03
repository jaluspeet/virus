#include "draw.h"
#include "internal.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// modules
#include "modules/bfs/bfs.h"
#include "modules/country/country.h"
#include "modules/dfs/dfs.h"
#include "modules/walker/walker.h"

int main(void) {

  srand(time(NULL));

  int map[MAP_X][MAP_Y];
  init_map(map);

  printf("Welcome to the virus:\n\n");

  /**
   * vengono "registrati" i vari moduli, ossia aggiunti a un array di struct
   * module (puntatore a funzione, nome del modulo) in modo da poter essere
   * chiamati senza dover ricorrere ad uno switch
   * TODO: registrare automaticamente tutti i moduli disponibili (reflection?)
   **/
  register_module(run_country, "country");
  register_module(run_bfs, "bfs");
  register_module(run_dfs, "dfs");
  register_module(run_walker, "walker");

  /**
   * elenca i moduli disponibili
   * NOTE: modules_size parte da 1. in questo modo 0 può
   * essere utilizzato per uscire dal programma
   **/
  for (int i = 0; i < modules_size; i++) {
    printf("[%d] %s\n", i + 1, modules[i].name);
  }
  printf("\n");

  while (1) {

    unsigned int choice;
    printf("(virus) ");
    scanf("%ud", &choice);

    if (choice == 0)
      return EXIT_SUCCESS;
    else if (choice > modules_size)
      fprintf(stderr, "\nERROR: Module does not exist\n\n");
    else {

      printf("\nRunning %s\n\n", modules[choice - 1].name);
      modules[choice - 1].function(map);

      draw_map_png(map);
    }
  }

  // se il programma arriva qui significa che qualcosa è andato storto
  return EXIT_FAILURE;
}

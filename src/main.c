// global stuff
#include "settings.h"
#include "types.h"

// stuff used here
#include "stuff/draw.h"
#include "stuff/utils.h"

// modules
#include "modules/bfs.h"
#include "modules/country.h"
#include "modules/dfs.h"
#include "modules/walker.h"

// std library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  // seed rand()
  srand(time(NULL));

  // inizializzazione della mappa (una matrice inizializzata a 0)
  int map[MAP_X][MAP_Y];
  init_map(map);

  // vengono "registrati" i vari moduli, ossia aggiunti a un array di struct
  // module (puntatore a funzione, nome del modulo) in modo da poter essere
  // chiamati senza dover ricorrere ad uno switch

  // TODO: registrare automaticamente tutti i moduli disponibili, dopo non sarà
  // più necessario includere tutti gli header dei moduli nel main
  register_module(run_country, "country");
  register_module(run_bfs, "bfs");
  register_module(run_dfs, "dfs");
  register_module(run_walker, "walker");

  // Buongiorno!
  printf("Welcome to the bfs:\n\n");

  // elenca i moduli disponibili
  // NOTE: modules_size non considera il fatto che sia indicizzato a 0, è il
  // numero di moduli disponibili. per questo il + 1. in questo modo 0 può
  // essere utilizzato per uscire dal programma
  for (int i = 0; i < modules_size; i++) {
    printf("[%d] %s\n", i + 1, modules[i].name);
  }
  printf("\n");

  while (1) {

    // l'utente seleziona un modulo e lo lancia
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
      VISUALIZE
    }
  }

  // se il programma arriva qui significa che qualcosa è andato storto
  return EXIT_FAILURE;
}

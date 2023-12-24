#include "../include/country.h"
#include "../include/draw.h"
#include "../include/utils.h"
#include "../include/virus.h"
#include "../include/walker.h"

#include <stdio.h>
int SEED;

int main(void) {

  // SEED è una costante che viene riutilizzata in giro. ad esempio, il nome del
  // file generato sarà mapSEED.png
  SEED = time(NULL);
  srand(SEED);

  // inizializzazione della mappa (una matrice inizializzata a 0)
  int map[MAP_X][MAP_Y];
  init_map(map);

  // vengono "registrati" i vari moduli, ossia aggiunti a un array di struct
  // module (puntatore a funzione, nome del modulo) in modo da poter essere
  // chiamati senza dover ricorrere ad uno switch

  // TODO: registrare automaticamente tutti i moduli disponibili, dopo non sarà
  // più necessario includere tutti gli header dei moduli nel main
  register_module(run_country, "country");
  register_module(run_virus, "virus");
  register_module(run_walker, "walker");

  // Buongiorno!
  printf("Welcome to the virus:\n\n");

  // elenca i moduli disponibili
  for (int i = 0; i < modules_size; i++) {
    printf("[%d] %s\n", i, modules[i].name);
  }
  printf("\n");

  while (1) {

    // l'utente seleziona un modulo e lo lancia
    unsigned int choice;
    printf("(virus) ");
    scanf("%ud", &choice);

    if (choice <= modules_size) {
      printf("\nRunning %s\n\n", modules[choice].name);
      modules[choice].function(map);

      // macro che stampa la mappa in ascii o su un png a seconda di cosa è
      // stato selezionato in settings.h
      DRAW_MAP;
    } else
      fprintf(stderr, "\nModule does not exist\n\n");
  }

  return EXIT_SUCCESS;
}

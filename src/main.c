#include "../include/country.h"
#include "../include/draw.h"
#include "../include/utils.h"
#include "../include/virus.h"
#include "../include/walker.h"

#include <stdio.h>
#include <stdlib.h>
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
      fprintf(stderr, "\nModule does not exist\n\n");
    else {

      printf("\nRunning %s\n\n", modules[choice - 1].name);
      modules[choice - 1].function(map);

      // macro che stampa la mappa in ascii o su un png a seconda di cosa è
      // stato selezionato in settings.h
      DRAW_MAP;
    }
  }

  // se il programma arriva qui significa che qualcosa è andato storto
  return EXIT_FAILURE;
}

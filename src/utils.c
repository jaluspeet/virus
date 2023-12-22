#include "../include/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void push(nodo **testa, coord cella) {
  nodo *nuovo = (nodo *)malloc(sizeof(nodo));
  nuovo->cella = cella;

  nuovo->next = *testa;
  *testa = nuovo;
}

coord pop(nodo **testa) {
  coord ret;

  if (!(*testa)) {
    ret.x = -1;
    ret.y = -1;
    return ret;
  } else if (!(*testa)->next) {
    ret = (*testa)->cella;
    *testa = NULL;
    return ret;
  } else {
    nodo *last = (*testa);
    nodo *prev = NULL;

    while (last->next) {
      prev = last;
      last = last->next;
    }

    ret = last->cella;

    prev->next = NULL;
    free(last);
  }

  return ret;
}

void show_map(int map[MAP_X][MAP_Y], coord target, char charset[CHARSET_LEN]) {

  for (int i = TIMEOUT; i > 0; i--) {

    printf("\nFIND: %dX %dY", target.x, target.y);
    printf("\n%d seconds left\n\n", i);

    for (int i = 0; i < MAP_X; i++) {
      for (int j = 0; j < MAP_Y; j++) {

        if (COLOR)
          printf("\033[%dm%3c\033[0m", 31 + (map[i][j] % 8),
                 charset[map[i][j]]);
        else
          printf("%3c", charset[map[i][j]]);
      }
      printf("\n");
    }

    sleep(1);
    system("clear");
  }
}

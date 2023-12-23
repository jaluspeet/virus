#ifndef SETTINGS_H
#define SETTINGS_H

// map
#define MAP_X 1024
#define MAP_Y 1024

// country (size is border)
#define COUNTRY_SIZE 200
#define COUNTRY_NUM 40
#define COUNTRY_TRIES 100

// virus
#define VIRUS_NUM 50
#define VIRUS_SIZE 10000
#define VIRUS_TRIES 1000

// walker
#define WALKER_NUM 200
#define WALKER_SIZE 1000
#define WALKER_TRIES 100

// draw
#define DRAW_MAP 2 // 0: no, 1: ascii, 2+: png

// draw (ascii)
#define COLOR 1
#define NO_SEA 0
#define CHARSET "$@%&#*/|(){}[]?-_+~<>!;:,^`'."
#define CHARSET_LEN sizeof(CHARSET)

// draw (png)
#define RED 0
#define GREEN 0
#define BLUE 0
#define BRIGHTNESS 50

#endif // SETTINGS_H

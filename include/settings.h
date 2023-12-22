#ifndef SETTINGS_H
#define SETTINGS_H

// map
#define MAP_X 1024
#define MAP_Y 768

// country (size is border)
#define COUNTRY_SIZE 200
#define COUNTRY_NUM 40
#define COUNTRY_TRIES 100

// virus
#define VIRUS_NUM 40
#define VIRUS_SIZE 1000
#define VIRUS_TRIES 1000

// walker
#define WALKER_NUM 200
#define WALKER_SIZE 1000
#define WALKER_TRIES 100

// gaming
#define GAMING 0
#define TIMEOUT 10

// display (ascii)
#define COLOR 1
#define NO_SEA 0
#define CHARSET "$@%&#*/|(){}[]?-_+~<>!;:,^`'."
#define CHARSET_LEN sizeof(CHARSET)

// display (png)
#define RED 50
#define GREEN 0
#define BLUE 40
#define BRIGHTNESS 50

#endif // SETTINGS_H

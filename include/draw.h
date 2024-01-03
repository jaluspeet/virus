#ifndef DRAW_H
#define DRAW_H

#include "settings.h"
#include "types.h"

void init_map(int map[MAP_X][MAP_Y]);

#define COLOR 1
#define NO_SEA 0
#define CHARSET "$@%&#*/|(){}[]?-_+~<>!;:,^`'."
#define CHARSET_LEN sizeof(CHARSET)
void draw_map_ascii(int map[MAP_X][MAP_Y]);

#define RED 0
#define GREEN 0
#define BLUE 0
#define BRIGHTNESS 50
void draw_map_png(int map[MAP_X][MAP_Y]);

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void draw_map_ascii(int map[MAP_X][MAP_Y]) {

    for (int i = 0; i < MAP_X; i++) {
        for (int j = 0; j < MAP_Y; j++) {

            if (COLOR)
                printf("\033[%dm%3c\033[0m", 30 + NO_SEA + (map[i][j] % 8),
                       CHARSET[map[i][j] % (int)CHARSET_LEN]);
            else
                printf("%3c", CHARSET[map[i][j]]);
        }

        printf("\n");
    }
}

void draw_map_png(int map[MAP_X][MAP_Y]) {

    int channels = 3; // RGB

    unsigned char *data = malloc(MAP_X * MAP_Y * channels);

    int index = 0;
    for (int i = 0; i < MAP_X; i++) {
        for (int j = 0; j < MAP_Y; j++) {

            srand(map[i][j]);

            data[index++] = rand() % 256 + BRIGHTNESS + RED;
            data[index++] = rand() % 256 + BRIGHTNESS + GREEN;
            data[index++] = rand() % 256 + BRIGHTNESS + BLUE;
        }
    }

    stbi_write_png("out/map.png", MAP_X, MAP_Y, channels, data, MAP_X * channels);

    free(data);
}

#endif // DRAW_H
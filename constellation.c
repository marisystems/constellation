/*
     Constellation.c
     Little program that draws a randomly generated constellation with ASCII
     art on the terminal using ANSI color codes and some symbols
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGTH 10
#define STRLEN 15

struct pos {
    int x;
    int y;
};


void random_pos(struct pos *p) {
    // Generate random number between 0 and WIDTH/HEIGTH
    p -> x = rand() % WIDTH;
    p -> y = rand() % HEIGTH;
}


char random_char(int index) {
    // Generate a random name and return
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    return charset[index];
}

char *random_name() {
    char static str[STRLEN];
    int i, index;

    for (i = 0; i < STRLEN - 1; i++) {
        index = rand() & 62;
        str[i] = random_char(index);
    }
    str[i] = '\0';

    // printf("%s\n", str);
    // printf("%zu\n", sizeof(str));

    return str;
}

void draw_screen(struct pos *star, char *name) {}

int main() {
    struct pos stars[WIDTH];
    struct pos lines;

    for (int i = 0; i < WIDTH; i++) {
        stars[i].x = rand() & WIDTH;
        stars[i].y = rand() & HEIGTH;
    }

    // Seed random
    srand(time(NULL));
    char *name = random_name();
    printf("%s\n", name);

    // draw_screen(stars, str);
}

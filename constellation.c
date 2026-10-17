/*
     Constellation.c
     Little program that draws a randomly generated constellation with ASCII
     art on the terminal using ANSI color codes and some symbols
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGTH 10
#define NUM_STARS 5
#define STRLEN 15

struct pos {
    int x;
    int y;
};

void random_pos(struct pos p[]) {
    // Generate random number between 0 and WIDTH/HEIGTH
    // and populate given array
    for (int i = 0; i < NUM_STARS; i++) {
        p[i].x = rand() % WIDTH;
        p[i].y = rand() % WIDTH;
    }
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

void draw_screen(struct pos *stars, char *name) {
    printf("constellation.c\n");

    for (int y = 0; y < HEIGTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if( y == 0  || y == HEIGTH - 1) {
                printf("-");
            } else if(x == 0 || x == WIDTH - 1) {
                printf("|");
            } else if(x == WIDTH - 2 || y == HEIGTH - 1) {
                printf("\033[0m");
            } else if (x > 0 || x < WIDTH || y > 0 || y < HEIGTH ) {
                printf("*");
            } else {
                printf("\033[38;5;15m\033[48;5;16m ");
            }
        }
        printf("\n");
    }
}


int main() {
    struct pos stars[NUM_STARS];

    // Seed random
    srand(time(NULL));
    // char *name = random_name();

    random_pos(stars);

    for (int i = 0; i < NUM_STARS; i++) {
        printf("stars[%d].x = %d  stars[%d].y = %d\n", i, stars[i].x, i, stars[i].y);
    }

    // draw_screen(stars, name);
}

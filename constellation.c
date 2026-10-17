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
#define STRLEN 8

struct pos {
    int x;
    int y;
};

void random_pos(struct pos p[]) {
    // Generate random number between 0 and WIDTH/HEIGTH
    // and populate given array
    for (int i = 0; i < NUM_STARS; i++) {
        p[i].x = rand() % (WIDTH - 3) + 1;
        p[i].y = rand() % (HEIGTH - 3) + 1;
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

    for (i = 0; i <= STRLEN - 1; i++) {
        index = rand() % 62;
        str[i] = random_char(index);
    }
    str[i] = '\0';

    // printf("%s\n", str);
    // printf("%zu\n", sizeof(str));
    return str;
}

    void draw_screen(struct pos *stars, char *name) {
    // Lines
    for (int y = 0; y < HEIGTH; y++) {
        // Columns
        for (int x = 0; x < WIDTH; x++) {

            // Top & Bottom border
            if( y == 0  || y == HEIGTH - 1) {
                printf("-");

            // Left and Right border
            } else if(x == 0 || x == WIDTH - 1) {
                printf("|");

            // Contain ANSI CODE inside box (gonna delete soon)
            } else if(x == WIDTH - 2 || y == HEIGTH - 1) {
                printf("\033[0m");

            // Select inside the box without borders
            } else if (x > 0 || x < WIDTH || y > 0 || y < HEIGTH ) {
                // So we don't overflow on spaces
                int print_switch = 0;

                // Loop trough stars array to see if it matches
                // this happens for each 'block' inside the square
                for (int z = 0; z < NUM_STARS; z++) {
                    if (x == stars[z].x && y == stars[z].y) {
                        printf("\033[38;5;15m\033[48;5;16m*");
                        print_switch = 1;
                    }
                }
                // Print empty space
                if(!print_switch) {
                    printf("\033[38;5;15m\033[48;5;16m ");
                    print_switch = 0;
                }
            }
        }
        printf("\n");
    }

    // Print constellation name
    int size = ( WIDTH / 2 ) - STRLEN / 2 - 5;
    for (int i = 0; i < size ; i++) {
        printf(" ");
    }
    printf("%s sector\n", name);
}


int main() {
    struct pos stars[NUM_STARS];

    // Seed random
    srand(time(NULL));

    char *name = random_name();
    random_pos(stars);
    draw_screen(stars, name);
}

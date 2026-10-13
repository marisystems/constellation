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

struct star {
    int x;
    int y;
};

void random_pos(struct star *s) {
    // Generate random number between 0 and WIDTH/HEIGTH
    s -> x = rand() % WIDTH;
    s -> y = rand() % HEIGTH;
}

char random_char(int index) {
    // Generate a random name and return
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    return charset[index];
}

void draw_screen(struct star *s, char *name) {
    printf("constellation.c\n");
    for (int i = 0; i < HEIGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            random_pos(s);

            // // Conditions for the border
            // // Top and bottom
            if( i == 0  || i == HEIGTH - 1) {
                printf("-");
            } else if(j == 0 || j == WIDTH - 1) {
                printf("|");
            } else if(j == WIDTH - 2 || i == HEIGTH - 1) {
                printf("\033[0m");
            // Draw a start at a position
            } else if (i == s -> x && s -> y) {
                printf("*");
            } else {
                printf("\033[38;5;15m\033[48;5;16m ");
            }
        }
        printf("\n");
    }
    int test = (WIDTH / 2) - (sizeof(name - 5) );
    for (int i = 0; i < test; i++) {
        printf(" ");
    }
    printf("%s sector\n", name);
}

int main() {
    srand(time(NULL));
    struct star Star = {0, 0};

    char str[STRLEN];
    int i, index;

    for (i = 0; i < STRLEN - 1; i++) {
        index = rand() & 62;
        str[i] = random_char(index);
    }
    str[i] = '\0';

    printf("%s\n", str);
    printf("%zu\n", sizeof(str));

    draw_screen(&Star, str);

    // 4. Connect the stars
    // 5 Generate a random name
    // 6. Print the name under the constellation

}

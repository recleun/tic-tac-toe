#include <stdlib.h>
#include <time.h>
#include "./playground.h"

Playground playground;

int main() {
    srand(time(NULL));

    printf("Welcome to tic-tac-toe\n\n");
    printf("To choose a cell, type its name, or its shortened name, like:\n\n");
    printf("top left (tl)\n");
    printf("middle center (mc)\n");
    printf("bottom right (br)\n\n");

    display(playground);

    while (true) {
        if (announce_winner(playground) == 1) break;
        player_move(&playground);
        if (!has_empty(playground.top) && !has_empty(playground.middle) && !has_empty(playground.bottom))
            break;
        cpu_move(&playground);
        display(playground);
    }

    display(playground);
}

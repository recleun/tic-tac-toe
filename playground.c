#include "./playground.h"

void display(Playground playground) {
    printf("[%c][%c][%c]\n", parse_state(playground.top.left), parse_state(playground.top.center), parse_state(playground.top.right));
    printf("[%c][%c][%c]\n", parse_state(playground.middle.left), parse_state(playground.middle.center), parse_state(playground.middle.right));
    printf("[%c][%c][%c]\n", parse_state(playground.bottom.left), parse_state(playground.bottom.center), parse_state(playground.bottom.right));
}

int announce_winner(Playground playground) {
    if (playground.top.left == 1 && playground.top.center == 1 && playground.top.right == 1 ||
        playground.middle.left == 1 && playground.middle.center == 1 && playground.middle.right == 1 ||
        playground.bottom.left == 1 && playground.bottom.center == 1 && playground.bottom.right == 1 ||
        playground.top.left == 1 && playground.middle.left == 1 && playground.bottom.left == 1 ||
        playground.top.center == 1 && playground.middle.center == 1 && playground.bottom.center == 1 ||
        playground.top.right == 1 && playground.middle.right == 1 && playground.bottom.right == 1 ||
        playground.top.left == 1 && playground.middle.center == 1 && playground.bottom.right == 1 ||
        playground.top.right == 1 && playground.middle.center == 1 && playground.bottom.left == 1)
    {
        printf("\nYou won\n");
        return 1;
    } else if (playground.top.left == 2 && playground.top.center == 2 && playground.top.right == 2 ||
        playground.middle.left == 2 && playground.middle.center == 2 && playground.middle.right == 2 ||
        playground.bottom.left == 2 && playground.bottom.center == 2 && playground.bottom.right == 2 ||
        playground.top.left == 2 && playground.middle.left == 2 && playground.bottom.left == 2 ||
        playground.top.center == 2 && playground.middle.center == 2 && playground.bottom.center == 2 ||
        playground.top.right == 2 && playground.middle.right == 2 && playground.bottom.right == 2 ||
        playground.top.left == 2 && playground.middle.center == 2 && playground.bottom.right == 2 ||
        playground.top.right == 2 && playground.middle.center == 2 && playground.bottom.left == 2)
    {
        printf("\nCPU won\n");
        return 1;
    }
    return 0;
}

char parse_state(int n) {
    if (n == 2) return 'o';
    if (n == 1) return 'x';
    return ' ';
}

void cpu_move(Playground *playground) {
    bool cpu_choice = false;
    while (!cpu_choice) {
        int choice_int = rand_range(1, 3);
        if (choice_int == 1 && has_empty(playground->top)) {
            while (!cpu_choice) {
                choice_int = rand_range(1, 3);
                if (choice_int == 1 && is_empty(playground->top.left)) {
                    playground->top.left = 2;
                    cpu_choice = true;
                    break;
                }
                if (choice_int == 2 && is_empty(playground->top.center)) {
                    playground->top.center = 2;
                    cpu_choice = true;
                }
                if (choice_int == 3 && is_empty(playground->top.right)) {
                    playground->top.right = 2;
                    cpu_choice = true;
                }
            }
        }
        if (choice_int == 2 && has_empty(playground->middle)) {
            while (!cpu_choice) {
                choice_int = rand_range(1, 3);
                if (choice_int == 1 && is_empty(playground->middle.left)) {
                    playground->middle.left = 2;
                    cpu_choice = true;
                    break;
                }
                if (choice_int == 2 && is_empty(playground->middle.center)) {
                    playground->middle.center = 2;
                    cpu_choice = true;
                }
                if (choice_int == 3 && is_empty(playground->middle.right)) {
                    playground->middle.right = 2;
                    cpu_choice = true;
                }
            }
        }
        if (choice_int == 3 && has_empty(playground->bottom)) {
            while (!cpu_choice) {
                choice_int = rand_range(1, 3);
                if (choice_int == 1 && is_empty(playground->bottom.left)) {
                    playground->bottom.left = 2;
                    cpu_choice = true;
                    break;
                }
                if (choice_int == 2 && is_empty(playground->bottom.center)) {
                    playground->bottom.center = 2;
                    cpu_choice = true;
                }
                if (choice_int == 3 && is_empty(playground->bottom.right)) {
                    playground->bottom.right = 2;
                    cpu_choice = true;
                }
            }
        }
    }
}

void player_move(Playground *playground) {
    bool player_choice = false;
    while (!player_choice) {
        char input[15];
        printf("> ");
        scanf("%s", input);
        if (strcmp(input, "tl") == 0 || strcmp(input, "top left") == 0 || strcmp(input, "tc") == 0 ||
            strcmp(input, "top center") == 0 || strcmp(input, "tr") == 0 || strcmp(input, "top right") == 0)
        {
            if (!has_empty(playground->top)) {
                printf("Choice invalid, cell already filled\n\n");
                continue;
            }
            if (strcmp(input, "tl") == 0 || strcmp(input, "top left") == 0) {
                if (!is_empty(playground->top.left)) {
                    printf("Choice invalid, cell already filled\n\n");
                    continue;
                } else {
                    playground->top.left = 1;
                    player_choice = true;
                    break;
                }
            }
            if (strcmp(input, "tc") == 0 || strcmp(input, "top center") == 0) {
                if (!is_empty(playground->top.center)) {
                    printf("Choice invalid, cell already filled\n\n");
                    continue;
                } else {
                    playground->top.center = 1;
                    player_choice = true;
                    break;
                }
            }
            if (strcmp(input, "tr") == 0 || strcmp(input, "top right") == 0) {
                if (!is_empty(playground->top.right)) {
                    printf("Choice invalid, cell already filled\n\n");
                    continue;
                } else {
                    playground->top.right = 1;
                    player_choice = true;
                    break;
                }
            }
        }
        else if (strcmp(input, "ml") == 0 || strcmp(input, "middle left") == 0 || strcmp(input, "mc") == 0 ||
            strcmp(input, "middle center") == 0 || strcmp(input, "mr") == 0 || strcmp(input, "middle right") == 0)
        {
            if (!has_empty(playground->middle)) {
                printf("Choice invalid, cell already filled\n\n");
                continue;
            }
            if (strcmp(input, "ml") == 0 || strcmp(input, "middle left") == 0) {
                if (!is_empty(playground->middle.left)) {
                    printf("Choice invalid, cell already filled\n\n");
                    continue;
                } else {
                    playground->middle.left = 1;
                    player_choice = true;
                    break;
                }
            }
            if (strcmp(input, "mc") == 0 || strcmp(input, "middle center") == 0) {
                if (!is_empty(playground->middle.center)) {
                    printf("Choice invalid, cell already filled\n\n");
                    continue;
                } else {
                    playground->middle.center = 1;
                    player_choice = true;
                    break;
                }
            }
            if (strcmp(input, "mr") == 0 || strcmp(input, "middle right") == 0) {
                if (!is_empty(playground->middle.right)) {
                    printf("Choice invalid, cell already filled\n\n");
                    continue;
                } else {
                    playground->middle.right = 1;
                    player_choice = true;
                    break;
                }
            }
        }
        else if (strcmp(input, "bl") == 0 || strcmp(input, "bottom left") == 0 || strcmp(input, "bc") == 0 ||
            strcmp(input, "bottom center") == 0 || strcmp(input, "br") == 0 || strcmp(input, "bottom right") == 0)
        {
            if (!has_empty(playground->bottom)) {
                printf("Choice invalid, cell already filled\n\n");
                continue;
            }
            if (strcmp(input, "bl") == 0 || strcmp(input, "bottom left") == 0) {
                if (!is_empty(playground->bottom.left)) {
                    printf("Choice invalid, cell already filled\n\n");
                    continue;
                } else {
                    playground->bottom.left = 1;
                    player_choice = true;
                    break;
                }
            }
            if (strcmp(input, "bc") == 0 || strcmp(input, "bottom center") == 0) {
                if (!is_empty(playground->bottom.center)) {
                    printf("Choice invalid, cell already filled\n\n");
                    continue;
                } else {
                    playground->bottom.center = 1;
                    player_choice = true;
                    break;
                }
            }
            if (strcmp(input, "br") == 0 || strcmp(input, "bottom right") == 0) {
                if (!is_empty(playground->bottom.right)) {
                    printf("Choice invalid, cell already filled\n\n");
                    continue;
                } else {
                    playground->bottom.right = 1;
                    player_choice = true;
                    break;
                }
            }
        } else {
            printf("Choice invalid\n\n");
            continue;
        }
    }
}

bool has_empty(Row row) {
    if (row.left == 0) return true;
    if (row.center == 0) return true;
    if (row.right == 0) return true;
    return false;
}

bool is_empty(int cell) {
    return cell == 0;
};

int rand_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

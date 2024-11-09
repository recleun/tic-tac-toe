#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int left;
    int center;
    int right;
} Row;

typedef struct {
    Row top;
    Row middle;
    Row bottom;
} Playground;

void display(Playground playground);
int announce_winner(Playground playground);
char parse_state(int n);
void cpu_move(Playground *playground);
void player_move(Playground *playground);
bool has_empty(Row row);
bool is_empty(int cell);
int rand_range(int min, int max);

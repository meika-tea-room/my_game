#include <stdlib.h>
#include "../Headers/helpers/print.h"
#include "../Headers/helpers/string.h"
#include "../Headers/helpers/random.h"
#include "../Headers/memory.h"
#include "../Headers/map.h"

_Bool              generate_map(t_game * g, const char * x, const char * y)
{
    unsigned short i;
    unsigned short j;

    g->map.size.x = str_to_unshort(x);
    g->map.size.y = str_to_unshort(y);
    if (!(g->map.board = init_map(g->map.size.x, g->map.size.y))) return ERROR;
    for (i = 0; i < g->map.size.y; ++i) {
        if (!(g->map.board[i] = init_map_cell(g->map.size.x))) return ERROR;
        for (j = 0; j < g->map.size.x; ++j) {
            if ((j == 0)||(j == g->map.size.x - 1)) g->map.board[i][j] = '1';
            else if (((i == 0) || (i == g->map.size.y -1)) && j != g->map.size.x -1) g->map.board[i][j] = '1';
            else if (j != g->map.size.x) g->map.board[i][j] = ' ';
        }
        g->map.board[i][j] = '\0';
        j = 0;
    }
    generate_bonus_malus(g);
    generate_snake(g);
    return SUCCESS;
}

void generate_snake(t_game *g)
{
    g->map.board[g->map.size.y/2][(g->map.size.x/2) - 1] = 's';
    g->map.board[g->map.size.y/2][g->map.size.x/2] = 's';
}

void        generate_bonus_malus(t_game * g)
{
    t_axe   bonus;
    t_axe   malus;

    bonus = generate_rand_pos(g);
    g->map.board[bonus.x][bonus.y] = 'B';
    malus = generate_rand_pos(g);
    while ((malus.y == bonus.y) && (malus.x == malus.x)) malus = generate_rand_pos(g);
    g->map.board[malus.x][malus.y] = 'M';
}

t_axe       generate_rand_pos(t_game * g)
{
    t_axe   item;

    item.x = rand_pos(g->map.size.x);
    item.y = rand_pos(g->map.size.y);
    return item;
}

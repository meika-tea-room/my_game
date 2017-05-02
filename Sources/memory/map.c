#include <stdlib.h>
#include "../../Headers/memory.h"
#include "../../Headers/helpers/print.h"

inline _Bool    init_map(t_game * g, t_axe s)
{
    if (s.x < MIN_WEED || s.x > MAX_WEED) return ERROR;
    if (s.y < MIN_WEED || s.y > MAX_HEIGHT) return ERROR;
    g->map.size = s;
    g->map.board = (char **) malloc((long unsigned int) s.y * sizeof(char **));
    g->map.board[0] = create_map_cell(s.x);
    return SUCCESS;
}

inline char * create_map_cell(int x)
{
    return (char *) malloc((long unsigned int) (x + 1) * sizeof(char *));
}

inline void free_map(t_game * g)
{
    int i;

    for (i = 0; i != g->map.size.y; ++i) free(g->map.board[i]);
    free(g->map.board);
}

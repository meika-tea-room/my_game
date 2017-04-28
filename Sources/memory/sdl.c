#include <SDL2/SDL.h>
#include "../../Headers/memory.h"

t_interface     create_interface()
{
    t_interface i;

    if (!(i.window = SDL_CreateWindow("Snake 2.0", SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    500, 500, SDL_WINDOW_SHOWN))) return ERROR;
    if (!(i.render = SDL_CreateRenderer(i.window, -1, SDL_RENDERER_ACCELERATED |
                                        SDL_RENDERER_PRESENTVSYNC))) return ERROR;
    return i;
}

void    free_interface(t_interface * i)
{
    SDL_DestroyRenderer(i->render);
    SDL_DestroyWindow(i->window);
}

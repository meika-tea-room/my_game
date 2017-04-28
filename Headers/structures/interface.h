#ifndef _SNAKE_STUCTURE_INTERFACE_H_
#define _SNAKE_STUCTURE_INTERFACE_H_

#include <SDL2/SDL.h>

typedef struct      s_interface
{
    SDL_Window *    window;
    SDL_Renderer *  render;
}                   t_interface;

#endif //_SNAKE_STUCTURE_INTERFACE_H_

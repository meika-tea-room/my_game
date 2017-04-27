#ifndef _SNAKE_FILE_H_
#define _SNAKE_FILE_H_

#include "structures/type.h"
#include "structures/game.h"

/* Usage functions */

_Bool load_file(t_game * restrict g, const char * restrict f, _Bool (* callback)(t_game * g));

#endif //_SNAKE_FILE_H_
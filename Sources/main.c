#include "../Headers/helpers/print.h"
#include "../Headers/helpers/type.h"
#include "../Headers/game.h"

int             main(int argc, char * argv[])
{
    t_game *    game;

    game = NULL;
    if (argc == 3 && is_digit(argv[1]) && is_digit(argv[2]))
        return new_game(game, argv[1], argv[2], play_game);
    else if (argc == 2)
        return load_game(game, argv[1], play_game);
    print_str("Please, enter a file or width and height of the map.\n");
    return EXIT_FAILURE;
}

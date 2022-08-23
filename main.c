#include "so_long.h"

#include <stdio.h>

void	so_long(char *map)
{
	t_game          game;

	game.mlx = mlx_init();
	ft_images(&game);
	ft_map(&game, map);
	printf("Width: %d\nHeight: %d\n", game.screen.width, game.screen.height);
	printf("X: %d\nY: %d\n", game.x, game.y);
	ft_screen(game);
	mlx_put_image_to_window(game.mlx, game.screen.ref, game.person.ref, game.person.x, game.person.y);
	//mlx_key_hook(game.screen.ref, ft_check_key, &game);
	mlx_loop(game.mlx);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	else
		exit(EXIT_FAILURE);
	return (0);
}

#include "so_long.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
	t_game		game;

	game.mlx = mlx_init();
	game.person.img = ft_image(game.mlx, "imgs/person.xpm");
	printf("AAAA\n");
	ft_map(&game, argv[1]);
	printf("AAAA\n");
	printf("X: %d\nY: %d\n", game.screen.size.x, game.screen.size.y);
	game.screen = ft_screen(game.mlx, game.screen.size.x, game.screen.size.y, "so_long");
	mlx_put_image_to_window(game.mlx, game.screen.ref, game.person.img.ref, game.person.pos.x, game.person.pos.y);
	mlx_key_hook(game.screen.ref, ft_check_key, &game);
	mlx_loop(game.mlx);
	return (argc);
}

#include "so_long.h"

void	ft_so_long(char *map)
{
	t_game		game;

	game.mlx = mlx_init();
	ft_images(&game);
	ft_map_check(&game, map);
	ft_screen(&game);
	ft_map(&game);
	mlx_key_hook(game.screen.ref, ft_check_key, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_so_long(argv[1]);
	else
		exit(EXIT_FAILURE);
	return(0);
}

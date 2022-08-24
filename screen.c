#include "so_long.h"

int	ft_close()
{
	exit(EXIT_SUCCESS);
}

void	ft_screen(t_game *game)
{
	game->screen.ref = mlx_new_window(game->mlx, game->screen.width, game->screen.height, "so_long");
	mlx_hook(game->screen.ref, 17, 0, ft_close, 0);
}

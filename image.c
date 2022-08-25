#include "so_long.h"

void	ft_images(t_game *game)
{
	game->person.ref = mlx_xpm_file_to_image(game->mlx, "imgs/person.xpm", &game->x, &game->y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", &game->x, &game->y);
	game->floor = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm", &game->x, &game->y);
	game->coin.ref = mlx_xpm_file_to_image(game->mlx, "imgs/coin.xpm", &game->x, &game->y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm", &game->x, &game->y);
	game->x = 64;
	game->y = 64;
}

void	ft_put_image(t_game *game, void *ref, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->screen.ref, ref, x * game->x, y * game->y);
}

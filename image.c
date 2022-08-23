#include "so_long.h"

void	ft_images(t_game *game)
{
	game->person.ref = mlx_xpm_file_to_image(game->mlx, "imgs/person.xpm", &game->x, &game->y);
}



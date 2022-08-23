#include "so_long.h"

int	ft_check_key(int key, void *param)
{
	t_game	*game;

	game = param;
	mlx_clear_window(game->mlx, game->screen.ref);
	if (key == 53)
		ft_close();
	else if (key == 0)
		game->person.x -= game->person.img.width;
	else if (key == 2)
		game->person.x += game->person.img.width;
	else if (key == 1)
		game->person.y += game->person.img.height;
	else if (key == 13)
		game->person.y -= game->person.img.height;
	mlx_put_image_to_window(game->mlx, game->screen.ref, game->person.img.ref, game->person.x, game->person.y);
	return (0);	
}

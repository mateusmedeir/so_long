#include "so_long.h"

int	ft_check_key(int key, void *param)
{
	t_game	*game;

	game = param;
	mlx_clear_window(game->mlx, game->screen.ref);
	if (key == 53)
		ft_close();
	else if (key == 0)
		game->person.pos_x -= game->x;
	else if (key == 2)
		game->person.pos_x += game->x;
	else if (key == 1)
		game->person.pos_y += game->y;
	else if (key == 13)
		game->person.pos_y -= game->y;
	mlx_put_image_to_window(game->mlx, game->screen.ref, game->person.ref, game->person.pos_x, game->person.pos_y);
	return (0);	
}

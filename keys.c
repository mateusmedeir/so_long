#include "so_long.h"

int	ft_key_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || (game->map[y][x] == 'E' && game->coin.amount > 0))
		return (0);
	if (game->map[y][x] == 'C')
		game->coin.amount--;
	game->map[game->person.y][game->person.x] = '0';
	game->map[y][x] = 'P';
	game->person.x = x;
	game->person.y = y;
	return (1);
}

int	ft_key_check(int key, t_game *game)
{
	if (key == 53)
		ft_close();
	else if (key == 0)
		return(ft_key_move(game, game->person.x - 1, game->person.y));
	else if (key == 2)
		return(ft_key_move(game, game->person.x + 1, game->person.y));
	else if (key == 13)
		return(ft_key_move(game, game->person.x, game->person.y - 1));
	else if (key == 1)
		return(ft_key_move(game, game->person.x, game->person.y + 1));
	return (0);	
}

int	ft_key(int key, void *param)
{
	static int	counter;
	t_game		*game;

	game = param;
	if (ft_key_check(key, game) == 1)
	{
		ft_printf("%d\n", ++counter);
		ft_map(game);
	}
	return (0);
}

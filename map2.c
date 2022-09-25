#include "so_long.h"

void	ft_map_check_line_error(t_game *game, int counter)
{
	if (counter == -1)
		ft_error("Map must be surrounded by walls");
	else if (counter == -2)
		ft_error("Map can only contain 0, 1, P, C and E");
	else if (counter == -3)
		ft_error("Map can only contain 1 start and 1 exit");
	else if (game->screen.height > 0 && counter != game->screen.width)
		ft_error("Map must be rectangular");
	else
		ft_error("Invalid map");
}

void	ft_map_path(t_game *game, int x, int y, char **map)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x - 1] == 'E' || map[y][x + 1] == 'E' || map[y - 1][x] == 'E'
			|| map[y + 1][x] == 'E' || map[y][x] == 'E')
		game->exit_path++;
	if (map[y][x] != '1')
		map[y][x] = '1';
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'E')
		ft_map_path(game, x - 1, y, map);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'E')
		ft_map_path(game, x + 1, y, map);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E')
		ft_map_path(game, x, y - 1, map);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'E')
		ft_map_path(game, x, y + 1, map);
}

void	ft_map_valid_path(t_game *game, char *map)
{
	int	pos;
	int	counter;
	char	**tmp;

	game->exit_path = 0;
	tmp = ft_split(map, '\n');
	ft_map_path(game, game->person.x, game->person.y, tmp);
	if (game->exit_path <= 0)
		ft_error_free(tmp, map, "No valid path on map");
	pos = -1;
	while (++pos < game->screen.height)
	{
		counter = -1;
		while (++counter < game->screen.width)
		{
			if (tmp[pos][counter] == 'C')
				ft_error_free(tmp, map, "No valid path on map");
		}
	}
	ft_free_map(tmp);
}

#include "so_long.h"

void	ft_map_check(t_game *game, char *map)
{
	char	*line;
	char	*tmp;
	int	fd;

	fd = open(map, O_RDONLY);
	game->screen.height = 0;
	tmp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = join_strings(tmp, line);
		free(line);
		game->screen.height++;
	}
	game->map = ft_split(tmp, '\n');
	free(tmp);
	game->screen.width = ft_strlen(*game->map);
	game->screen.width *= game->x;
	game->screen.height *= game->y;
}

void	ft_map_block(t_game *game, int pos)
{
	int	counter;

	counter = -1;
	while (game->map[pos][++counter])
	{
		if (game->map[pos][counter] == 'P')
		{
			game->person.x = counter;
			game->person.y = pos;
			ft_put_image(game, game->person.ref, counter, pos);
		}
		else if (game->map[pos][counter] == '1')
			ft_put_image(game, game->wall, counter, pos);
		else if (game->map[pos][counter] == '0')
			ft_put_image(game, game->floor, counter, pos);
		else if (game->map[pos][counter] == 'C')
		{
			++game->coin.amount;
			ft_put_image(game, game->coin.ref, counter, pos);
		}
		else if (game->map[pos][counter] == 'E')
			ft_put_image(game, game->exit, counter, pos);
	}
}

void	ft_map(t_game *game)
{
	int	pos;

	pos = 0;
	game->coin.amount = 0;
	while (game->map[pos])
		ft_map_block(game, pos++);
}	

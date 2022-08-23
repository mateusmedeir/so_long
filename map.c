#include "so_long.h"

#include <fcntl.h>

#include <stdio.h>

void	ft_map(t_game *game, char *map)
{
	char	*line;
	int	fd;

	fd = open(map, O_RDONLY);
	game->screen.height = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->screen.width = -1;
		while (line[++game->screen.width])
			ft_map_block(game, line[game->screen.width]);
		line = get_next_line(fd);
		game->screen.height++;
	}
	game->screen.width *= game->x;
	game->screen.height *= game->y;
}

void	ft_map_block(t_game *game, char line)
{
	printf(" %c", line);
	if (line == 'P')
	{
		game->person.x = game->screen.width * game->x;
		game->person.y = game->screen.height * game->y;
	}
}

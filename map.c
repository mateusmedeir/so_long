#include "so_long.h"

#include <fcntl.h>

#include <stdio.h>

void	ft_map(t_game *game, char *map)
{
	char	*line;
	int	fd;

	fd = open(map, O_RDONLY);
	game->screen.size.y = 0;
	line = get_next_line(fd);
	printf("AAAA\n");
	while (line)
	{
		game->screen.size.x = -1;
		while (line[++game->screen.size.x])
			ft_map_block(game, line[game->screen.size.x]);
		line = get_next_line(fd);
		game->screen.size.y++;
	}
	game->screen.size.x *= game->person.img.size.x;
	game->screen.size.y *= game->person.img.size.y;
}

void	ft_map_block(t_game *game, char line)
{
	printf(" %c", line);
	if (line == 'P')
	{
		game->person.pos.x = game->screen.size.x * game->person.img.size.x;
		game->person.pos.y = game->screen.size.y * game->person.img.size.y;
	}
}

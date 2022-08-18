#include "so_long.h"

#include <fcntl.h>

#include <stdio.h>

void	ft_map(t_long *so_long, char *map)
{
	char	*line;
	int	fd;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	so_long->screen.size.y = 0;
	while (line)
	{
		so_long->screen.size.x = -1;
		while (line[++so_long->screen.size.x])
			ft_map_block(so_long, line[so_long->screen.size.x]);
		line = get_next_line(fd);
		so_long->screen.size.y += 1;
	}
	so_long->screen.size.x *= so_long->character.image.size.x;
	so_long->screen.size.y *= so_long->character.image.size.y;
}

void	ft_map_block(t_long *so_long, char line)
{
	printf(" %c", line);
	if (line == 'P')
	{
		so_long->character.location.x = so_long->screen.size.x * so_long->character.image.size.x;
		so_long->character.location.y = so_long->screen.size.y * so_long->character.image.size.y;
	}
}

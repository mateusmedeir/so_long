#include "so_long.h"

#include <fcntl.h>

t_block	ft_map(t_long so_long, char *map)
{
	t_block	map_block;
	t_size	position;
	char	*line;
	int		fd;
	int		counter;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	position.x = 0;
	position.y = 0;
	while (line[0])
	{
		position.y += 1;
		counter = -1;
		while (line[++counter])
			ft_map_block(map_block, position, line);
		line = get_next_line(fd);
	}
	map.x = counter;
	return (map);
}

void	ft_map_block(t_block map, t_size position, char *line)
{
	
}

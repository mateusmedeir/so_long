#include "so_long.h"

#include <fcntl.h>

t_block	ft_map(t_long so_long, char *map)
{
	t_block	map_block;
	t_size	position;
	char	*a;
	int		fd;
	int		counter;

	fd = open(map, O_RDONLY);
	a = get_next_line(fd);
	position.x = 0;
	position.y = 0;
	while (a[0])
	{
		position.y += 1;
		counter = -1;
		while (a[++counter])
			ft_map_block(map_block, position, a);
		a = get_next_line(fd);
	}
	map.x = counter;
	return (map);
}

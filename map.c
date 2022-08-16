#include "so_long.h"

#include <fcntl.h>

t_size	ft_map(t_long so_long, char *map)
{
	t_size	map;
	char	*a;
	int		fd;
	int		counter;

	fd = open(map, O_RDONLY);
	a = get_next_line(fd);
	while (a[0])
	{
		map.y += 1;
		counter = 0;
		while (a[counter])
			ft_map_block();
		a = get_next_line(fd);
	}
	map.x = counter;
	return (map);
}

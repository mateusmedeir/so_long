#include "so_long.h"

#include <fcntl.h>

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

void	ft_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->screen.ref, game->wall, x * game->x, y * game->y);
			else if (game->map[y][x] == '0')
                                mlx_put_image_to_window(game->mlx, game->screen.ref, game->floor, x * game->x, y * game->y);
			else if (game->map[y][x] == 'C')
                                mlx_put_image_to_window(game->mlx, game->screen.ref, game->coin, x * game->x, y * game->y);
			else if (game->map[y][x] == 'P')
			{
				game->person.pos_x = x * game->x;
				game->person.pos_y = y * game->y;
				mlx_put_image_to_window(game->mlx, game->screen.ref, game->person.ref, game->person.pos_x, game->person.pos_y);
			}
		}
	}
}	

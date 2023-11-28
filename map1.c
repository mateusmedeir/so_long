/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:39:33 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/28 10:39:36 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_error(t_game *game, char *line, int pos)
{
	int	count;

	count = 0;
	while (line[count] && line[count] != '\n')
	{
		if ((pos == 0 && line[count] != '1') || ((line[count + 1] == '\n'
					|| !line[count + 1] || count == 0) && line[count] != '1'))
			return (-1);
		if (line[count] == 'P')
		{
			game->person.x = count;
			game->person.y = pos;
			game->person.amount++;
		}
		else if (line[count] == 'E')
			game->exit.amount++;
		else if (line[count] == 'C')
			game->coin.amount++;
		else if (line[count] != '1' && line[count] != '0')
			return (-2);
		if (game->person.amount > 1 || game->exit.amount > 1)
			return (-3);
		count++;
	}
	return (count);
}

char	*ft_map_check_line(t_game *game)
{
	char	*line;
	char	*tmp;
	int		counter;

	tmp = NULL;
	while (1)
	{
		line = get_next_line(game->fd);
		if (line == NULL)
			break ;
		counter = ft_map_error(game, line, game->screen.height);
		if (counter <= 0 || (game->screen.height > 0
				&& counter != game->screen.width))
		{
			free(line);
			free(tmp);
			ft_map_check_line_error(game, counter);
		}
		tmp = ft_strjoin_new(tmp, line);
		free(line);
		game->screen.width = counter;
		game->screen.height++;
	}
	return (tmp);
}

void	ft_map_check(t_game *game, char *map)
{
	char	*tmp;

	game->fd = open(map, O_RDONLY);
	game->screen.height = 0;
	game->coin.amount = 0;
	game->person.amount = 0;
	game->exit.amount = 0;
	tmp = ft_map_check_line(game);
	close(game->fd);
	if (!tmp)
		ft_error("Invalid map");
	if (game->coin.amount == 0 || game->person.amount == 0
		|| game->exit.amount == 0)
	{
		free(tmp);
		ft_error("Wrong number of elements in the map");
	}
	ft_map_valid_path(game, tmp);
	game->map = ft_split(tmp, '\n');
	free(tmp);
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
			ft_put_image(game, game->coin.ref, counter, pos);
		else if (game->map[pos][counter] == 'E')
			ft_put_image(game, game->exit.ref, counter, pos);
	}
}

void	ft_map(t_game *game)
{
	int	pos;

	pos = 0;
	while (game->map[pos])
		ft_map_block(game, pos++);
}

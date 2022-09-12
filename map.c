/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:25:58 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/08/30 11:31:47 by mmedeiro         ###   ########.fr       */
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
			return (0);
		if (line[count] == 'P')
		{
			if (game->person.amount++ >= 1)
				return (0);
		}
		else if (line[count] == 'E')
		{
			if (game->exit.amount++ >= 1)
				return (0);
		}
		else if (line[count] == 'C')
			game->coin.amount++;
		else if (line[count] != '1' && line[count] != '0')
			return (0);
		count++;
	}
	return (count);
}

char	*ft_map_check_line(t_game *game)
{
	char	*line;
	char	*tmp;
	int	counter;

	tmp = NULL;
	while (1)
	{
		line = get_next_line(game->fd);
		if (line == NULL)
			break ;
		counter = ft_map_error(game, line, game->screen.height);
		if (counter == 0 || (game->screen.height > 0
				&& counter != game->screen.width))
		{
			free(line);
			free(tmp);
			ft_error("Wrong map format");
		}
		tmp = join_strings(tmp, line);
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
	if (game->screen.width <= game->screen.height || game->coin.amount == 0
		|| game->person.amount == 0 || game->exit.amount == 0)
	{
		free(tmp);
		ft_error("Wrong map format");
	}
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

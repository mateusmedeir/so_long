/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:32:04 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/09/25 12:53:34 by mateus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || (game->map[y][x] == 'E'
				&& game->coin.amount > 0))
		return (0);
	if (game->map[y][x] == 'C')
		game->coin.amount--;
	else if (game->map[y][x] == 'E')
		return (2);
	game->map[game->person.y][game->person.x] = '0';
	game->map[y][x] = 'P';
	game->person.x = x;
	game->person.y = y;
	return (1);
}

int	ft_key_check(int key, t_game *game)
{
	if (key == 53)
		return (-1);
	else if (key == 0)
		return (ft_key_move(game, game->person.x - 1, game->person.y));
	else if (key == 2)
		return (ft_key_move(game, game->person.x + 1, game->person.y));
	else if (key == 13)
		return (ft_key_move(game, game->person.x, game->person.y - 1));
	else if (key == 1)
		return (ft_key_move(game, game->person.x, game->person.y + 1));
	return (0);
}

int	ft_key(int key, void *param)
{
	static int	counter;
	int			check;
	t_game		*game;

	game = param;
	check = ft_key_check(key, game);
	if (check == -1)
		ft_close(game);
	if (check == 1)
	{
		ft_printf("%d\n", ++counter);
		ft_map(game);
	}
	else if (check == 2)
	{
		ft_printf("%d\n", ++counter);
		ft_printf("You finished the game in %d moves!\n", counter);
		ft_exit(game);
	}
	return (0);
}

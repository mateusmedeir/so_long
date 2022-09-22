/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:34:16 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/09/22 10:55:47 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_screen(t_game *game)
{
	game->screen.ref = mlx_new_window(game->mlx, game->screen.width
			* game->x, game->screen.height * game->y, "so_long");
	mlx_hook(game->screen.ref, 17, 0, ft_close, game);
}

void	ft_free_map(t_game *game)
{
	int	counter;

	counter = 0;
	while (game->map[counter])
		free(game->map[counter++]);
	free(game->map);
}

void	ft_error(char *strerror)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(strerror, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_close(t_game *game)
{
	ft_free_map(game);
	ft_putstr_fd("The game has been closed\n", 1);
	exit(EXIT_SUCCESS);
}

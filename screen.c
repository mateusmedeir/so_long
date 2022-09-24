/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:34:16 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/09/24 08:17:43 by mateus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_screen(t_game *game)
{
	game->screen.ref = mlx_new_window(game->mlx, game->screen.width
			* game->x, game->screen.height * game->y, "so_long");
	mlx_hook(game->screen.ref, 17, 0, ft_close, game);
}

void	ft_free_map(char **map)
{
	int	counter;

	counter = 0;
	while (map[counter])
		free(map[counter++]);
	free(map);
}

void	ft_error_free(char **map, char *str, char *strerror)
{
	ft_free_map(map);
	if (str)
		free(str);
	ft_error(strerror);
}

void	ft_error(char *strerror)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(strerror, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_close(t_game *game)
{
	ft_free_map(game->map);
	exit(EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:37:50 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/28 10:37:52 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_free(char **map, char *str, char *strerror)
{
	ft_free_map(map);
	if (str)
		free(str);
	ft_error(strerror);
}

void	ft_error(char *strerror)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(strerror, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_exit(t_game *game)
{
	ft_free_map(game->map);
	ft_free_images(game);
	mlx_destroy_window(game->mlx, game->screen.ref);
	exit(EXIT_SUCCESS);
}

int	ft_close(t_game *game)
{
	ft_putstr_fd("The game has been closed\n", 1);
	ft_exit(game);
	return (0);
}

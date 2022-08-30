/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:34:16 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/08/30 11:31:35 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_game *game)
{
	int counter;

	counter = 0;
	while (game->map[counter])
		free(game->map[counter++]);
	free(game->map);
}

void	ft_error(t_game *game, char *strerror)
{
	ft_free_map(game);
	ft_putstr_fd(strerror, 2);
	exit(EXIT_FAILURE);
}

int ft_close(t_game *game)
{
	ft_free_map(game);
	exit(EXIT_SUCCESS);
}

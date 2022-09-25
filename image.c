/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:29:30 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/09/25 07:14:15 by mateus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_images(t_game *game)
{
	game->person.ref = mlx_xpm_file_to_image(game->mlx,
			"imgs/person.xpm", &game->x, &game->y);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"imgs/wall.xpm", &game->x, &game->y);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"imgs/floor.xpm", &game->x, &game->y);
	game->coin.ref = mlx_xpm_file_to_image(game->mlx,
			"imgs/coin.xpm", &game->x, &game->y);
	game->exit.ref = mlx_xpm_file_to_image(game->mlx,
			"imgs/exit.xpm", &game->x, &game->y);
	if (!game->person.ref || !game->wall || !game->floor
		|| !game->coin.ref || !game->exit.ref)
		ft_error_free(game->map, NULL, "Error loading images");
	game->x = 50;
	game->y = 50;
}

void	ft_put_image(t_game *game, void *ref, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->screen.ref,
		ref, x * game->x, y * game->y);
}

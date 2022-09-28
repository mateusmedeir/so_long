/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:29:30 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/09/28 10:27:31 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_images(t_game *game)
{
	if (game->person.ref)
		mlx_destroy_image(game->mlx, game->person.ref);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->coin.ref)
		mlx_destroy_image(game->mlx, game->coin.ref);
	if (game->exit.ref)
		mlx_destroy_image(game->mlx, game->exit.ref);
}

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
	{
		ft_free_images(game);
		ft_error_free(game->map, NULL, "Failed to load images");
	}
	game->x = 50;
	game->y = 50;
}

void	ft_put_image(t_game *game, void *ref, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->screen.ref,
		ref, x * game->x, y * game->y);
}

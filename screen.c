/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:33:39 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/08/30 11:33:26 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_screen(t_game *game)
{
	game->screen.ref = mlx_new_window(game->mlx,
			game->screen.width, game->screen.height, "so_long");
	mlx_hook(game->screen.ref, 17, 0, ft_close, 0);
}

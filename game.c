/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:25:06 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/09/25 12:16:00 by mateus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_so_long(char *map)
{
	t_game		game;

	ft_map_check(&game, map);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_error("Error starting mlx");
	ft_images(&game);
	ft_screen(&game);
	ft_map(&game);
	mlx_key_hook(game.screen.ref, ft_key, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 5) == 0)
			ft_so_long(argv[1]);
		else
			ft_error("Map must be in .ber format");
	}
	else
		ft_error("Wrong number of arguments");
	return (0);
}

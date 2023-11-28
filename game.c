/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:37:59 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/28 10:38:01 by matlopes         ###   ########.fr       */
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
	game.screen.ref = mlx_new_window(game.mlx, game.screen.width
			* game.x, game.screen.height * game.y, "so_long");
	ft_map(&game);
	mlx_hook(game.screen.ref, 17, 0, ft_close, &game);
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

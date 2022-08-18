#include "so_long.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
	t_long		so_long;

	so_long.mlx = mlx_init();
	so_long.character.image = ft_image(so_long.mlx, "character.xpm");
	ft_map(&so_long, argv[1]);
	printf("X: %d\nY: %d\n", so_long.screen.size.x, so_long.screen.size.y);
	so_long.screen = ft_screen(so_long.mlx, so_long.screen.size.x, so_long.screen.size.y, "so_long");
	mlx_put_image_to_window(so_long.mlx, so_long.screen.ref, so_long.character.image.ref, 
			so_long.character.location.x, so_long.character.location.y);
	mlx_key_hook(so_long.screen.ref, ft_check_key, &so_long);
	mlx_loop(so_long.mlx);
	return (argc);
}

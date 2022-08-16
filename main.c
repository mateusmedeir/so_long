#include "so_long.h"

int main(void)
{
	t_long	so_long;

	so_long.mlx = mlx_init();
	so_long.screen = ft_screen(so_long.mlx, 1600, 900, "so_long");
	so_long.image = ft_image(so_long.mlx, "character.xpm");
	so_long.location.x = 0;
	so_long.location.y = 0;
	mlx_put_image_to_window(so_long.mlx, so_long.screen.ref, so_long.image.ref, 
			so_long.location.x, so_long.location.y);
	mlx_key_hook(so_long.screen.ref, ft_check_key, &so_long);
	mlx_loop(so_long.mlx);
}

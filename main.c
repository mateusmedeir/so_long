#include "so_long.h"

int main(void)
{
	t_long	so_long;

	so_long.mlx = mlx_init();
	so_long.screen = ft_screen(mlx, 1600, 900, "so_long");
	so_long.image = ft_image(mlx, "character.xpm");
	so_long.position.x = 0;
	so_long.position.y = 0;
	mlx_put_image_to_window(mlx, so_long.screen.ref, so_long.image.ref, so_long.location.x, so_long.location.y);
	mlx_loop(so_long.mlx);
}

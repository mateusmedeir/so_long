#include "so_long.h"

int main(void)
{
	void	*mlx;
	t_screen	screen;
	t_image		image;
	t_size		size;

	mlx = mlx_init();
	ft_screen(&screen, mlx, 1600, 900, "so_long");
	ft_image(&image, mlx, "block.xpm");
	size.x = 0;
	size.y = 0;
	mlx_put_image_to_window(mlx, screen.ref, image.ref, size.x, size.y);
	mlx_loop(mlx);
}

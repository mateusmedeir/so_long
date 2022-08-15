#include "so_long.h"

int main(void)
{
	void	*mlx;
	t_screen	screen;
	t_image		image;
	t_size		size;

	mlx = mlx_init();
	ft_window(window, mlx);
	ft_image(image, mlx, "image.xpm");
	size.x = 0;
	size.y = 0;
	max_put_image_to_window(mlx, window.ref, image.ref, size.x, size.y);
	mlx_loop(mlx);
}

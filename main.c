#include "so_long.h"

int main(void)
{
	void	*mlx;
	t_window	window;
	t_image		image;

	mlx = mlx_init();
	ft_window(window, mlx);
	ft_image(image, mlx, "image.xpm");
	image->x = 0;
	image->y = 0;
	max_put_image_to_window(mlx, window->ref, image->ref, image->x, image->y);
	mlx_loop(program->mlx);
}

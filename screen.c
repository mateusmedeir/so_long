#include "so_long.h"

int ft_close()
{
	exit(EXIT_SUCCESS);
}

t_screen	ft_screen(void *mlx, int width, int height, char *title)
{
	t_screen	screen;

	screen.size.x = width;
        screen.size.y = height;
	screen.ref = mlx_new_window(mlx, screen.size.x, screen.size.y, title);
	mlx_hook(screen.ref, 17, 0, ft_close, 0);
	return (screen);
}

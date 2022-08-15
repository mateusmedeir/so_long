#include "so_long.h"

int ft_close()
{
	exit(EXIT_SUCCESS);
}

void	ft_screen(t_screen *screen, void *mlx, int width, int height, char *title)
{
	screen->size.x = width;
        screen->size.y = height;
	screen->ref = mlx_new_window(mlx, screen->size.x, screen->size.y, title);
	mlx_hook(screen->ref, 17, 0, ft_close, 0);
}

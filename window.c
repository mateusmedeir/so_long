#include "so_long.h"

int ft_close()
{
	exit(EXIT_SUCCESS);
}

void	ft_window(t_window window, void *mlx)
{
	window.size.x = 1920;
        window.size.y = 1080;
	window.ref = mlx_new_window(mlx, window.size.x, window.size.y, "so_long");
	mlx_hook(window.ref, 17, 0, ft_close, 0);
}

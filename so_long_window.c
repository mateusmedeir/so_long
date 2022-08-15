#include "so_long.h"

void	ft_window(t_window window, void *mlx)
{
	window.x = 1920;
        window.y = 1080;
	window.ref = mlx_new_window(mlx, window.x, window.y, "so_long");
}

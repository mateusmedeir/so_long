#include "mlx/mlx.h"

int main(void)
{
	void *mlx;
	t_window	window;

	mlx = mlx_init();
	ft_window(window, mlx);
	mlx_loop(mlx);
}

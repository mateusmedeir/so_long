#include <mlx.h>

typedef struct s_data {
	void *img;
	char *addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_data;

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1600, 900, "Hello World!");
	img.img = mlx_new_image(mlx, 1600, 900);
	mlx_loop(mlx);
}

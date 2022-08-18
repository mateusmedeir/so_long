#include "so_long.h"

t_image	ft_image(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ref, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

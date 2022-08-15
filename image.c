#include "so_long.h"

void ft_image(t_image *image, void *mlx, char *path)
{
	image->ref = mlx_xpm_file_to_image(mlx, path, &image->size.x, &image->size.y);
		image->pixels = mlx_get_data_addr(image->ref, &image->bits_per_pixel, &image->line_size, &image->endian);
}

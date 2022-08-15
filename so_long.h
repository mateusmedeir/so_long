#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include <stdlib.h>

typedef struct	s_size
{
	int	x;
	int	y;
}				t_size;

typedef struct	s_screen {
	void	*ref;
	t_size	size;
}				t_screen;

typedef struct	s_image {
	void	*ref;
	t_size	size;
	char	*pixels;
	int	bits_per_pixel;
	int	line_size;
	int	endian;
}				t_image;

void    ft_screen(t_screen *screen, void *mlx, int width, int height, char *title);
void ft_image(t_image *image, void *mlx, char *path);

#endif

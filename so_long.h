#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include <stdlib.h>

typedef struct	s_size
{
	int	x;
	int	y;
}				t_size;

typedef struct	s_screen
{
	void	*ref;
	t_size	size;
}				t_screen;

typedef struct	s_image
{
	void	*ref;
	t_size	size;
	char	*pixels;
	int	bits_per_pixel;
	int	line_size;
	int	endian;
}				t_image;

typedef struct s_long
{
	void		*mlx;
	s_image		image;
	s_screen	screen;
	s_size		location;
}				t_long;

t_screen	ft_screen(void *mlx, int width, int height, char *title);
t_image		ft_image(void *mlx, char *path);

#endif

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include <stdlib.h>

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_window {
	void		*ref;
	t_vector	size;
}				t_window;

typedef struct s_color {
	int	r;
	int g;
	int b;
	int a;
}	t_color;

typedef struct	s_image {
	void		*ref;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		image;
	t_vector	image_position;
}				t_program;

void    ft_window(t_window window, void *mlx);

#endif

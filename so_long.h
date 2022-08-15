#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include <stdlib.h>

typedef struct	s_window {
	void		*ref;
	int     x;
        int     y;
}				t_window;

typedef struct	s_image {
	void		*ref;
	int     x;
        int     y;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

void    ft_window(t_window window, void *mlx);

#endif

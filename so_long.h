#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include <stdlib.h>

typedef struct s_window {
	void	*ref;
	int	x;
	int	y;
}			t_window;

void    ft_window(t_window window, void *mlx);

#endif

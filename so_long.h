#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include "gnl/get_next_line.h"
#include <stdlib.h>

typedef struct	s_size
{
	int	x;
	int	y;
}				t_size;

typedef struct	s_image
{
	void	*ref;
	t_size	size;
	char	*pixels;
	int	bits_per_pixel;
	int	line_size;
	int	endian;
}				t_image;

typedef struct s_screen
{
	void		*ref;
	t_size		size;
}				t_screen;

typedef struct	s_block
{
	t_image	image;
	t_size	location;
}				t_block;

typedef struct s_long
{
	void		*mlx;
	t_screen 	screen;
	t_block		character;
	t_block		map;
}				t_long;

int ft_close();
t_screen	ft_screen(void *mlx, int width, int height, char *title);
t_image		ft_image(void *mlx, char *path);
int			ft_check_key(int key, void *param);
void    ft_map(char *map);

#endif

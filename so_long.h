#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>

typedef struct s_screen
{
	void	*ref;
	int	width;
	int	height;
}				t_screen;

typedef struct	s_person
{
	void	*ref;
	int	pos_x;
	int	pos_y;
}				t_person;

typedef struct s_game
{
	void		*mlx;
	t_screen 	screen;
	t_person	person;
	void		*wall;
	void		*floor;
	void		*coin;
	char		**map;
	int		x;
	int		y;
}				t_game;

void	ft_so_long(char *map);
//screen
int	ft_close();
void	ft_screen(t_game *game);
//image
void	ft_images(t_game *game);
//key
int	ft_check_key(int key, void *param);
//map
void	ft_map_check(t_game *game, char *map);
void	ft_map(t_game *game);

#endif

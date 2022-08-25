#ifndef SO_LONG_H
#define SO_LONG_H

#include "libraries/mlx/mlx.h"
#include "libraries/gnl/get_next_line.h"
#include "libraries/libft/libft.h"
#include "libraries/libft/ft_printf/ft_printf.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_screen
{
	void	*ref;
	int	width;
	int	height;
}				t_screen;

typedef struct	s_person
{
	void	*ref;
	int	x;
	int	y;
}				t_person;

typedef struct	s_coin
{
	void	*ref;
	int	amount;
}				t_coin;

typedef struct s_game
{
	void		*mlx;
	t_screen 	screen;
	t_person	person;
	void		*wall;
	void		*floor;
	t_coin		coin;
	void		*exit;
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
void    ft_put_image(t_game *game, void *ref, int x, int y);
//key
int	ft_key_move(t_game *game, int x, int y);
int	ft_key_check(int key, t_game *game);
int	ft_key(int key, void *param);
//map
void	ft_map_check(t_game *game, char *map);
void	ft_map(t_game *game);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 09:27:58 by mateus            #+#    #+#             */
/*   Updated: 2023/11/27 12:39:31 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/mlx-linux/mlx.h"
# include "libs/libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# define KEY_ESC 65307
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115

typedef struct s_screen
{
	void	*ref;
	int		width;
	int		height;
}				t_screen;

typedef struct s_person
{
	void	*ref;
	int		amount;
	int		x;
	int		y;
}				t_person;

typedef struct s_block
{
	void	*ref;
	int		amount;
}				t_block;

typedef struct s_game
{
	void		*mlx;
	t_screen	screen;
	t_person	person;
	void		*wall;
	void		*floor;
	t_block		coin;
	t_block		exit;
	char		**map;
	int			fd;
	int			x;
	int			y;
	int			exit_path;
}				t_game;

//game
void	ft_so_long(char *map);
//screen
void	ft_free_map(char **map);
void	ft_error_free(char **map, char *str, char *strerror);
void	ft_error(char *strerror);
void	ft_exit(t_game *game);
int		ft_close(t_game *game);
//image
void	ft_images(t_game *game);
void	ft_put_image(t_game *game, void *ref, int x, int y);
void	ft_free_images(t_game *game);
//keys
int		ft_key_move(t_game *game, int x, int y);
int		ft_key_check(int key, t_game *game);
int		ft_key(int key, void *param);
//map2
void	ft_map_check_line_error(t_game *game, int counter);
void	ft_map_path(t_game *game, int x, int y, char **map);
int		ft_map_check_last_line(char **map);
void	ft_map_valid_path(t_game *game, char *map);
//map
int		ft_map_error(t_game *game, char *line, int pos);
int		ft_map_error(t_game *game, char *line, int pos);
char	*ft_map_check_line(t_game *game);
void	ft_map_check(t_game *game, char *map);
void	ft_map(t_game *game);

#endif

#include "so_long.h"

int	ft_check_key(int key, void *param)
{
	t_long	*so_long;

	so_long = param;
	mlx_clear_window(so_long->mlx, so_long->screen.ref);
	if (key == 53)
		ft_close();
	else if (key == 0)
		so_long->location.x -= so_long->image.size.x;
	else if (key == 2)
		so_long->location.x += so_long->image.size.x;
	else if (key == 1)
		so_long->location.y += so_long->image.size.y;
	else if (key == 13)
		so_long->location.y -= so_long->image.size.y;
	mlx_put_image_to_window(so_long->mlx, so_long->screen.ref, so_long->image.ref, so_long->location.x, so_long->location.y);
	return (0);	
}

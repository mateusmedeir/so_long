#include "so_long.h"

int main(int argc, char *argv[])
{
	t_long		so_long;

	so_long.mlx = mlx_init();
	so_long.screen = ft_screen(so_long.mlx, 1600, 900, "so_long");
	so_long.character.image = ft_image(so_long.mlx, "character.xpm");
	ft_map(argv[1]);
	so_long.character.location.x = 0;
	so_long.character.location.y = 0;
	mlx_put_image_to_window(so_long.mlx, so_long.screen.ref, so_long.character.image.ref, 
			so_long.character.location.x, so_long.character.location.y);
	mlx_key_hook(so_long.screen.ref, ft_check_key, &so_long);
	mlx_loop(so_long.mlx);
	return (argc);
}

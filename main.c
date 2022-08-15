#include "so_long.h"

int main(void)
{
	t_program	program;

	program->mlx = mlx_init();
	ft_window(program->window, program->mlx);
	ft_image(program->image, program->mlx, "image.xpm");
	program->image->x = 0;
	program->image->y = 0;
	max_put_image_to_window(program->mlx, program->window->ref, program->image->ref, program->image->x, program->image->y);
	mlx_key_hook(program->window->ref, *ft_input, &program);
	mlx_loop(program->mlx);
}

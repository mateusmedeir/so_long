#include "so_long.h"

void	ft_error(char *strerror)
{
	ft_putstr_fd(strerror, 2);
	exit(EXIT_FAILURE);
}

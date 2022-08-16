/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:45:45 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/06/20 11:34:42 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_file(fd));
}

char	*read_file(int fd)
{
	int			counter;
	char		*new;
	static char	*res;

	new = malloc(BUFFER_SIZE + 1);
	if (!new)
		return (NULL);
	counter = 1;
	while (counter > 0 && find_next_line(res) != 1)
	{
		counter = read (fd, new, BUFFER_SIZE);
		if (counter < 0)
		{
			free(new);
			return (NULL);
		}
		new[counter] = '\0';
		res = join_strings(res, new);
	}
	free(new);
	if (!res)
		return (NULL);
	new = put_the_line(res);
	res = cat_res(res);
	return (new);
}

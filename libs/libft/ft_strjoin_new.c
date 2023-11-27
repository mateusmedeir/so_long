/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:07:11 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/27 14:07:11 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_new(char *old, char *str)
{
	char	*pointer;
	int		counter;

	counter = 0;
	pointer = malloc((ft_strlen(old) + ft_strlen(str) + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	if (old)
	{
		while (old[counter])
		{
			pointer[counter] = old[counter];
			counter++;
		}
		free(old);
	}
	while (*str)
		pointer[counter++] = *str++;
	pointer[counter] = '\0';
	if (!*pointer)
	{
		free(pointer);
		return (NULL);
	}
	return (pointer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:42:45 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/22 12:24:27 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pointer;
	int		index;

	pointer = (char *)s;
	index = ft_strlen(pointer);
	while (index >= 0 && pointer[index] != c)
		index--;
	if (index >= 0 && pointer[index] == (char)c)
		return (pointer + index);
	return (NULL);
}

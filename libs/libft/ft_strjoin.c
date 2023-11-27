/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:42:08 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/07 12:40:01 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	pointer = malloc(size * sizeof(char));
	if (!pointer)
		return (NULL);
	ft_strlcpy(pointer, s1, size);
	ft_strlcat(pointer, s2, size);
	return (pointer);
}

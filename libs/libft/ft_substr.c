/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:42:53 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/07 14:42:09 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;
	size_t	counter;

	counter = ft_strlen(s);
	if (start >= counter)
		return (ft_calloc(1, sizeof(char)));
	if ((counter - start) < len)
		len = counter - start;
	pointer = malloc((len + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	ft_strlcpy(pointer, s + start, len + 1);
	return (pointer);
}

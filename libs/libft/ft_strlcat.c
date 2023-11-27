/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:42:13 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/07 13:47:18 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_counter;
	size_t	src_counter;
	size_t	size;

	dst_counter = ft_strlen (dst);
	src_counter = ft_strlen (src);
	if (dstsize <= dst_counter)
		return (src_counter + dstsize);
	size = dst_counter + src_counter;
	while (*src != '\0' && dst_counter < dstsize - 1)
		dst[dst_counter++] = *src++;
	dst[dst_counter] = '\0';
	return (size);
}

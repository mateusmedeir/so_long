/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:40:58 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/22 12:23:34 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*p_dst;
	char	*p_src;
	size_t	counter;

	p_src = (char *) src;
	p_dst = (char *) dst;
	if (!p_src && !p_dst)
		return (NULL);
	if (p_dst < p_src)
		return (ft_memcpy(dst, src, len));
	else
	{
		counter = len;
		while (--counter + 1 > 0)
			p_dst[counter] = p_src[counter];
	}
	return (p_dst);
}

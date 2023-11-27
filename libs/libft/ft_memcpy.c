/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:40:52 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/07 09:40:53 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p_dst;
	char	*p_src;
	size_t	counter;

	p_dst = (char *)dst;
	p_src = (char *)src;
	if (!p_dst && !p_src)
		return (NULL);
	counter = 0;
	while (counter < n)
	{
		p_dst[counter] = p_src[counter];
		counter++;
	}
	return (p_dst);
}

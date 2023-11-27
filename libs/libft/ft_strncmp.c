/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:42:33 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/07 09:42:34 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			counter;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	counter = 0;
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (p_s1[counter] == p_s2[counter] && p_s1[counter]
		&& p_s2[counter] && counter < n - 1)
		counter++;
	return (p_s1[counter] - p_s2[counter]);
}

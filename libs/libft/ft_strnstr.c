/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:42:39 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/07 15:00:08 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_counter;

	needle_counter = ft_strlen(needle);
	if (!needle_counter)
		return ((char *)haystack);
	while (*haystack != '\0' && len-- >= needle_counter)
	{
		if (!ft_strncmp(haystack, needle, needle_counter))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

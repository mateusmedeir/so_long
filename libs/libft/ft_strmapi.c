/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:42:26 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/07 13:48:20 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pointer;
	int		counter;

	pointer = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	counter = -1;
	while (s[++counter] != '\0')
		pointer[counter] = (*f)(counter, s[counter]);
	pointer[counter] = '\0';
	return (pointer);
}

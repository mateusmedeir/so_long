/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:39:48 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/27 12:34:02 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*pointer;
	int			counter;
	int			signal;
	long int	value;

	value = (long int)n;
	counter = ft_intlen(value);
	pointer = malloc((counter + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	signal = 0;
	if (value < 0)
	{
		pointer[0] = '-';
		value *= -1;
		signal = 1;
	}
	pointer[counter--] = '\0';
	while (counter >= signal)
	{
		pointer[counter--] = ((value % 10) + '0');
		value /= 10;
	}
	return (pointer);
}

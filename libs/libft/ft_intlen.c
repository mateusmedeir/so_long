/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:07:56 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/27 12:07:56 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int nbr)
{
	long int	value;
	size_t		counter;

	counter = 1;
	value = nbr;
	if (value < 0)
	{
		value = -value;
		counter++;
	}
	while (value > 9)
	{
		value /= 10;
		counter++;
	}
	return (counter);
}

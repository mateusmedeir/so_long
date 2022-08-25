/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:49:23 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/06/22 14:49:42 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uns_num(unsigned int n)
{
	unsigned long int	value;
	int					counter;

	value = n;
	counter = 0;
	if (value > 9)
	{
		counter += print_uns_num(value / 10);
		counter += print_uns_num(value % 10);
	}
	else
		counter += print_char(value + '0');
	return (counter);
}

int	print_hex(unsigned int n, char c)
{
	int	size;

	size = 1;
	if (n / 16)
		size += print_hex(n / 16, c);
	if (c == 'x')
		print_char("0123456789abcdef"[n % 16]);
	else if (c == 'X')
		print_char("0123456789ABCDEF"[n % 16]);
	return (size);
}

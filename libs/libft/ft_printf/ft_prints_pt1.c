/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_pt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:46:21 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/06/22 14:46:23 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[counter])
		write(1, &str[counter++], 1);
	return (counter);
}

int	print_adress_helper(unsigned long n)
{
	write(1, "0x", 2);
	return (print_adress(n) + 2);
}

int	print_adress(unsigned long n)
{
	int	size;

	size = 1;
	if (n / 16)
		size += print_adress(n / 16);
	print_char("0123456789abcdef"[n % 16]);
	return (size);
}

int	print_num(int n)
{
	long int	value;
	int			counter;

	value = n;
	counter = 0;
	if (value < 0)
	{
		counter += print_char('-');
		value *= -1;
	}
	if (value > 9)
	{
		counter += print_num(value / 10);
		counter += print_num(value % 10);
	}
	else
		counter += print_char(value + '0');
	return (counter);
}

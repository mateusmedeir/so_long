/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:44:55 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/06/22 14:58:05 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	arg;

	counter = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%' && *str + 1)
		{
			counter += ft_conversions(*++str, arg);
			str++;
		}
		else
		{
			write(1, &*str, 1);
			str++;
			counter++;
		}
	}
	va_end(arg);
	return (counter);
}

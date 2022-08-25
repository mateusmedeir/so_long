/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:50:12 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/06/22 14:50:21 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_conversions(char str, va_list arg);
int	print_char(int c);
int	print_str(char *str);
int	print_adress_helper(unsigned long n);
int	print_adress(unsigned long n);
int	print_num(int n);
int	print_uns_num(unsigned int n);
int	print_hex(unsigned int n, char c);

#endif

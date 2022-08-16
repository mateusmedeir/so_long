/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:52:49 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/06/20 11:38:38 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_file(int fd);
size_t	ft_strlen(const char *s);
int		find_next_line(char *s);
int		count_line(char *s);
char	*put_the_line(char *s);
char	*cat_res(char *res);
char	*join_strings(char *res, char *tmp);

#endif

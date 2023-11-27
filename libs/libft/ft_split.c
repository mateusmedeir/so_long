/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:41 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/22 13:00:35 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free_all(char **pointer, int split)
{
	while (split >= 0)
		free (pointer[split--]);
	free (pointer);
	return (-1);
}

static int	ft_how_many_splits(char const *s, char c)
{
	int	split;
	int	counter;

	split = 0;
	counter = -1;
	while (s[++counter])
		if (s[counter] != c && (counter == 0 || s[counter - 1] == c))
			split++;
	return (split);
}

static int	ft_put_string(char **pointer, int split, char const *s, char c)
{
	int	start;
	int	size;

	start = 0;
	size = 0;
	while (s[start] == c && s[start])
		start++;
	if (!s[start])
		return (start);
	while (s[start + size] != '\0' && s[start + size] != c)
		size++;
	pointer[split] = ft_substr(s, start, size);
	if (!pointer[split])
		return (ft_free_all(pointer, split));
	return (start + size);
}

char	**ft_split(char const *s, char c)
{
	char	**pointer;
	int		counter;
	int		split;
	int		max;

	if (!s)
		return (NULL);
	split = -1;
	max = ft_how_many_splits(s, c);
	pointer = malloc((max + 1) * sizeof(char *));
	if (!pointer)
		return (NULL);
	while (++split < max && *s)
	{
		counter = ft_put_string(pointer, split, s, c);
		if (counter == -1)
			return (NULL);
		s += counter;
	}
	pointer[split] = NULL;
	return (pointer);
}

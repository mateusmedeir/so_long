/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:40:27 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/07 09:40:28 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*pointer;

	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (new);
	pointer = new;
	lst = lst->next;
	while (lst != NULL)
	{
		new->next = ft_lstnew((*f)(lst->content));
		if (!new->next)
		{
			ft_lstclear (&pointer, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (pointer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:32:06 by fescande          #+#    #+#             */
/*   Updated: 2025/05/06 10:32:09 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	**last;
	void	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	last = &new;
	while (lst)
	{
		tmp = f(lst->content);
		*last = ft_lstnew(tmp);
		if (!*last)
		{
			del(tmp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		last = &(*last)->next;
		lst = lst->next;
	}
	return (new);
}

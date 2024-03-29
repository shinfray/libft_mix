/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:40:36 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 14:51:32 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*ptr;

	if (lst == NULL || (f) == NULL || (del) == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		ptr = ft_lstnew(NULL);
		if (ptr == NULL)
		{
			ft_lstclear(&new_list, (del));
			return (NULL);
		}
		ptr->content = (f)(lst->content);
		ft_lstadd_back(&new_list, ptr);
		lst = lst->next;
	}
	return (new_list);
}

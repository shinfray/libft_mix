/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:50:53 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 14:51:21 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	*temp;

	if (lst == NULL || (del) == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(temp, (del));
	}
}

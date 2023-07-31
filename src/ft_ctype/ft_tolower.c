/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:34:01 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 14:49:37 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int			ft_tolower(int c);
static int	ft_isupper(int c);

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

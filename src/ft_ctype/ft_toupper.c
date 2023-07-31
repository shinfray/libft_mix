/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:22:34 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 14:49:40 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int			ft_toupper(int c);
static int	ft_islower(int c);

int	ft_toupper(int c)
{
	if (ft_islower(c))
		c -= 32;
	return (c);
}

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

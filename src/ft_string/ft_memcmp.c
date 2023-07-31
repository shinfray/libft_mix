/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:49:39 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 14:52:55 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cast_s1;
	const unsigned char	*cast_s2;

	cast_s1 = (const unsigned char *)s1;
	cast_s2 = (const unsigned char *)s2;
	while (n != 0 && *cast_s1 == *cast_s2)
	{
		--n;
		++cast_s1;
		++cast_s2;
	}
	if (n != 0)
		return (*cast_s1 - *cast_s2);
	return (0);
}

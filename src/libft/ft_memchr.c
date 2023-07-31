/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:28:53 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 11:28:54 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	c2 = c;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n != 0 && *ptr != c2)
	{
		--n;
		++ptr;
	}
	if (n != 0)
		return ((void *)ptr);
	return (NULL);
}

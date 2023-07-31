/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:14:13 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 14:52:57 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cast_dst;
	const char	*cast_src;

	cast_dst = (char *)dst;
	cast_src = (const char *)src;
	if (len == 0 || cast_src == cast_dst)
		return (dst);
	if (cast_dst < cast_src)
		ft_memcpy(cast_dst, cast_src, len);
	else
		while (len-- != 0)
			cast_dst[len] = cast_src[len];
	return (dst);
}

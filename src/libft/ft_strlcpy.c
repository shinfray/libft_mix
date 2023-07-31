/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:35:19 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 13:00:46 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char *const	ptr = src;

	if (dstsize == 0 || dst == NULL || src == NULL)
		return (ft_strlen(src));
	while (*src != '\0' && --dstsize != 0)
		*dst++ = *src++;
	*dst = '\0';
	return ((size_t)(src - ptr) + ft_strlen(src));
}

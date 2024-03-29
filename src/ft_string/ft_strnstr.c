/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:33:06 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 14:53:08 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0 || ft_strlen(haystack) < needle_len)
		return (NULL);
	while (*haystack != '\0' && len >= needle_len)
	{
		if (ft_memcmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}

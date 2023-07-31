/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:31:06 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 14:53:08 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	const char	c2 = (const char)c;
	const char	*ptr;

	ptr = NULL;
	while (1)
	{
		if (*s == c2)
			ptr = s;
		if (*s == '\0')
			return ((char *)ptr);
		++s;
	}
}

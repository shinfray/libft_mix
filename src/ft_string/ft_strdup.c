/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:34:43 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 15:06:23 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s1);

char	*ft_strdup(const char *s1)
{
	const size_t	size = ft_strlen(s1);
	char			*s2;

	s2 = ft_calloc(size + 1, sizeof(*s2));
	if (s2 == NULL)
		return (NULL);
	return (ft_memcpy(s2, s1, size + 1));
}

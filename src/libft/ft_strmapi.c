/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:24:32 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 13:10:47 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab;
	size_t	i;

	i = 0;
	if (s == NULL || (f) == NULL)
		return (NULL);
	tab = ft_calloc(ft_strlen(s) + 1, sizeof(*tab));
	if (tab == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		tab[i] = (*f)((unsigned int)i, s[i]);
		++i;
	}
	return (tab);
}

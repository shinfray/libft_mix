/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:17:59 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 14:53:06 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlen(const char *s)
{
	const char *const	p = s;

	while (*s != '\0' )
		++s;
	return ((size_t)(s - p));
}

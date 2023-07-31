/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:23:36 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 13:00:01 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len);

void	*ft_memset(void *b, int c, size_t len)
{
	const unsigned char	uc_c = (const unsigned char)c;
	unsigned char		*uc_b;

	uc_b = (unsigned char *)b;
	while (len-- != 0)
		*uc_b++ = uc_c;
	return (b);
}

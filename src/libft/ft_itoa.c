/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:02:27 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 13:09:35 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n);
static size_t	ft_count_digit(int n);
static void		ft_fill(char *const s, unsigned int n, size_t i);

char	*ft_itoa(int n)
{
	const size_t	numb_digit = ft_count_digit(n);
	char			*s;

	s = ft_calloc(numb_digit + 1, sizeof(*s));
	if (s == NULL)
		return (NULL);
	if (n < 0)
		*s = '-';
	if (n < 0)
		ft_fill(s, (unsigned int)(-n), numb_digit - 1);
	else
		ft_fill(s, (unsigned int)n, numb_digit - 1);
	s[numb_digit] = '\0';
	return (s);
}

static size_t	ft_count_digit(int n)
{
	size_t	count;

	count = 1 + (n < 0);
	while (n / 10 != 0)
	{
		++count;
		n /= 10;
	}
	return (count);
}

static void	ft_fill(char *const s, unsigned int n, size_t i)
{
	if (n > 9)
		ft_fill(s, n / 10, i - 1);
	s[i] = n % 10 + '0';
}

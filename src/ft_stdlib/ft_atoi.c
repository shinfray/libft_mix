/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:22:29 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 14:51:48 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

int			ft_atoi(const char *str);
static int	ft_isspace(int c);

int	ft_atoi(const char *str)
{
	long int	n;
	long int	buff;
	char		sign;

	n = 0;
	sign = 1;
	while (ft_isspace(*str) != 0)
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str) != 0)
	{
		buff = n;
		n = n * 10 + *str++ - '0';
		if (n < buff && sign > 0)
			return (-1);
		if (n < buff && sign < 0)
			return (0);
	}
	return ((int)(n * sign));
}

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

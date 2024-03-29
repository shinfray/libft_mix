/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 03:02:21 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 13:51:40 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_s(va_list *ap);
int			ft_print_c(va_list *ap);
int			ft_print_u(va_list *ap);
int			ft_print_d_i(va_list *ap);
static void	ft_recurs(const unsigned int uns_num, int *len);

int	ft_print_s(va_list *ap)
{
	const char *const	s = va_arg(*ap, char *);
	int					i;

	i = 0;
	if (s == NULL)
		return ((int)write(1, "(null)", 6));
	while (s[i] != '\0')
		++i;
	return ((int)write(1, s, (size_t)i));
}

int	ft_print_c(va_list *ap)
{
	const unsigned char	c = (const unsigned char)va_arg(*ap, int);

	return ((int)write(1, &c, 1));
}

int	ft_print_u(va_list *ap)
{
	unsigned int	u;
	int				len;

	u = va_arg(*ap, unsigned int);
	len = 0;
	ft_recurs(u, &len);
	return (len);
}

int	ft_print_d_i(va_list *ap)
{
	int				num;
	unsigned int	uns_num;
	int				len;

	num = va_arg(*ap, int);
	uns_num = (unsigned int)num;
	len = 0;
	if (num < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		++len;
		uns_num = (unsigned int)(-num);
	}
	ft_recurs(uns_num, &len);
	return (len);
}

static void	ft_recurs(const unsigned int uns_num, int *len)
{
	unsigned char	c;

	if (uns_num > 9)
	{
		ft_recurs(uns_num / 10, len);
		if (*len == -1)
			return ;
	}
	c = '0' + uns_num % 10;
	if (write(1, &c, 1) < 0)
	{
		*len = -1;
		return ;
	}
	(*len)++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:29:18 by shinfray          #+#    #+#             */
/*   Updated: 2023/07/31 13:47:26 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...);
static int	ft_parse_format(const char *format, va_list *ap);
static int	ft_print(const char *format);
static int	ft_print_flags(const char *format, va_list *ap);
static char	*ft_strchr(const char *s, int c);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_parse_format(format, &ap);
	va_end(ap);
	return (count);
}

static int	ft_parse_format(const char *format, va_list *ap)
{
	int	count;
	int	return_value;

	count = 0;
	return_value = 0;
	while (*format != '\0')
	{
		return_value = ft_print(format);
		if (return_value < 0)
			return (-1);
		format += return_value;
		count += return_value;
		if (*format == '\0')
			return (count);
		return_value = ft_print_flags(format, ap);
		if (return_value < 0)
			return (-1);
		count += return_value;
		format += 2;
	}
	return (count);
}

static int	ft_print(const char *format)
{
	int	len;

	len = 0;
	while (format[len] != '%' && format[len] != '\0')
		++len;
	return ((int)write(1, format, (size_t)len));
}

static int	ft_print_flags(const char *format, va_list *ap)
{
	int			(*function_list[8])(va_list *);
	char		*flag_position;
	const char	flags[10] = "scdiupxX%";

	flag_position = ft_strchr(flags, format[1]);
	(function_list[0]) = &ft_print_s;
	(function_list[1]) = &ft_print_c;
	(function_list[2]) = &ft_print_d_i;
	(function_list[3]) = &ft_print_d_i;
	(function_list[4]) = &ft_print_u;
	(function_list[5]) = &ft_print_p;
	(function_list[6]) = &ft_print_x;
	(function_list[7]) = &ft_print_upper_x;
	if (flag_position != NULL)
	{
		if (*flag_position == '%')
			return ((int)write(1, "%", 1));
		return ((*function_list[flag_position - flags])(ap));
	}
	return (-1);
}

static char	*ft_strchr(const char *s, int c)
{
	const char	c2 = (const char)c;

	while (*s != c2)
		if (*s++ == '\0')
			return (NULL);
	return ((char *)s);
}

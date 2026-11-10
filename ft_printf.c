/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abed-dyb <abed-dyb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:53:54 by abed-dyb          #+#    #+#             */
/*   Updated: 2026/11/09 10:16:03 by abed-dyb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_handle(char format, va_list arg)
{
	if (format == '%')
		return (ft_putchar('%'));
	if (format == 'c')
		return (ft_putchar((char)va_arg(arg, int)));
	if (format == 's')
		return (ft_putstr(va_arg(arg, char *), format));
	if (format == 'i' || format == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int)));
	if (format == 'x')
		return (ft_print_hex(va_arg(arg, unsigned int), 'x'));
	if (format == 'X')
		return (ft_print_hex(va_arg(arg, unsigned int), 'X'));
	if (format == 'p')
		return (ft_print_addres((unsigned long)va_arg(arg, void *), format));
	return (-1);
}

static int	call_format_handle(const char *s, int i, va_list arg)
{
	int	count;

	count = 0;
	i++;
	if (!s[i])
		return (-1);
	count = ft_format_handle(s[i], arg);
	return (count);
}

static int	end_arg(va_list arg)
{
	va_end(arg);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		i;
	int		temp;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			temp = call_format_handle(format, i++, arg);
		else
			temp = ft_putchar(format[i]);
		if (temp == -1)
			return (end_arg(arg));
		count += temp;
		i++;
	}
	va_end(arg);
	return (count);
}

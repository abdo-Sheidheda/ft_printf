/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helper_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abed-dyb <abed-dyb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:10:18 by abed-dyb          #+#    #+#             */
/*   Updated: 2026/11/07 16:44:36 by abed-dyb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, char format)
{
	const char	*base;
	int			count;
	int			ret;

	count = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else if (format == 'x')
		base = "0123456789abcdef";
	if (n >= 16)
	{
		ret = ft_print_hex(n / 16, format);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_print_addres(unsigned long n, char format)
{
	int	count;
	int	ret;

	count = 0;
	if (n == 0)
	{
		count = ft_putstr(NULL, format);
		if (count == -1)
			return (-1);
		return (count);
	}
	if (write (1, "0x", 2) == -1)
		return (-1);
	count += 2;
	ret = ft_print_hex(n, 'x');
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

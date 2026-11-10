/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helper_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abed-dyb <abed-dyb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:09:10 by abed-dyb          #+#    #+#             */
/*   Updated: 2026/11/06 21:02:34 by abed-dyb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *str, char format)
{
	int	i;
	int	ret;
	int	count;

	if (!str && format == 's')
		return (write (1, "(null)", 6));
	else if (!str && format == 'p')
		return (write (1, "(nil)", 5));
	i = 0;
	count = 0;
	while (str[i])
	{
		ret = ft_putchar(str[i]);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned long n)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putnbr_unsigned(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_putchar((char)(n % 10 + '0')) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putnbr(int n)
{
	int		count;
	long	nb;
	int		ret;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		nb = -nb;
	}
	ret = ft_putnbr_unsigned((unsigned long)nb);
	if (ret == -1)
		return (-1);
	return (count + ret);
}

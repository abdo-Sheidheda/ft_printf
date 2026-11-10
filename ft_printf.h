/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abed-dyb <abed-dyb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:06:35 by abed-dyb          #+#    #+#             */
/*   Updated: 2026/11/07 17:28:01 by abed-dyb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// main one :
int			ft_printf(const char *format, ...);

// helper one :
int			ft_putchar(char c);
int			ft_putstr(char *str, char format);
int			ft_putnbr(int n);
int			ft_putnbr_unsigned(unsigned long n);

// helper two :
int			ft_print_hex(unsigned long n, char format);
int			ft_print_addres(unsigned long n, char format);
#endif

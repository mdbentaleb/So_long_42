/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:20:49 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/09 21:10:14 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(arg, int));
	else if (c == 'c')
		count = ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count = ft_putstr(va_arg(arg, char *));
	else if (c == 'u')
		count = ft_putunbr(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthex(va_arg(arg, unsigned int), c);
	else if (c == 'p')
		count = ft_putp(va_arg(arg, void *));
	else if (c == '%')
		count = ft_putchar(c);
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		i;

	va_start(arg, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (count);
			count += check_format(format[i], arg);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}

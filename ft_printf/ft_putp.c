/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:07:56 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/09 17:53:15 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthexa(unsigned long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += puthexa(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putp(void *ptr)
{
	int				count;
	unsigned long	n;

	n = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += puthexa(n);
	return (count);
}

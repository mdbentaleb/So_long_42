/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:20:56 by moben-ta          #+#    #+#             */
/*   Updated: 2024/12/05 16:09:35 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	int		count;
	char	*base;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, c);
	if (c == 'x')
	{
		base = "0123456789abcdef";
		count += ft_putchar(base[n % 16]);
	}
	else if (c == 'X')
	{
		base = "0123456789ABCDEF";
		count += ft_putchar(base[n % 16]);
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:20:43 by moben-ta          #+#    #+#             */
/*   Updated: 2025/03/15 18:18:00 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putunbr(unsigned int nbr);
int	ft_putnbr(int nbr);
int	ft_putstr(char *s);
int	ft_puthex(unsigned int n, char c);
int	ft_putp(void *ptr);

#endif